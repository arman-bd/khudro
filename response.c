
int send_response_header(SOCKET socket, int response, char *c_type, long c_size){
    char header[4096];

    // Add Response Code
    if(response == 200){
        strcpy(header, "HTTP/1.1 200 OK\n");
    }

    if(response == 404){
        strcpy(header, "HTTP/1.1 404 Not Found\n");
    }

    // Process Header
    sprintf(header, "%sServer: %s/%s (%s)\n", header, __ServerName, __ServerVersion, __ServerOS);
    sprintf(header, "%sContent-Type: %s; charset=utf-8\n", header, c_type);
    sprintf(header, "%sContent-Length: %ld\n", header, c_size);
    sprintf(header, "%s\n", header);

    // Send Header
    return send(socket, header, strlen(header), 0);
}

int send_response_content(SOCKET socket, char *content){
    return send(socket, content, strlen(content), 0);
}

int send_response_file(SOCKET socket, FILE *fp, size_t file_size, size_t max_buffer){
    int byteSent = SOCKET_ERROR;
    char *file_buff;

    if(max_buffer == 0 || max_buffer > file_size){
        file_buff = malloc(file_size + 1);
        fread(file_buff, sizeof(char), file_size + 1, fp);
        byteSent = send(socket, file_buff, file_size, 0);
    }else{
        size_t c_position = 0;
        file_buff = malloc(max_buffer + 1);
        byteSent = 0;
        fseek(fp, 0L, SEEK_SET);

        while(c_position + max_buffer <= file_size){
            fseek(fp, c_position, SEEK_SET);
            fread(file_buff, sizeof(char), max_buffer + 1, fp);
            byteSent += send(socket, file_buff, max_buffer, 0);
            c_position = c_position + max_buffer;
        }
        size_t left_buffer = file_size - c_position;
        if(left_buffer > 0){
            fseek(fp, c_position, SEEK_SET);
            fread(file_buff, sizeof(char), left_buffer + 1, fp);
            if(left_buffer < max_buffer){
                file_buff[left_buffer] = '\0';
            }
            byteSent += send(socket, file_buff, left_buffer, 0);
        }
    }

    free(file_buff);
    return byteSent;
}

int send_response_error(SOCKET socket, int error_code, s_conf server_conf, int display_error){

    // Web Output
    FILE *fp;
    int file_size; // Error Handler File
    char file_name[128];
    char file_type[128];
    char file_path[512];
    char web_buffer[512];

    if(display_error == 1){
        // Content Not Found!
        printf("Error: File Not Found [ 0x02 ]\n");
    }

    // Try 404 Handler!
    sprintf(file_name, "\\error404.html");
    sprintf(file_path, "%s%s", server_conf.default_dir, file_name);

    // Get MIME Type
    get_mime_type(file_name, file_type);

    if((fp = fopen(file_path, "rb")) != NULL){
        // Get File Size
        file_size = getFileSize(fp);
        // Pack Header
        send_response_header(socket, error_code, file_type, file_size);
        // Send File To Client
        send_response_file(socket, fp, file_size, server_conf.max_buffer);
        // Close File
        fclose(fp);
    }else{
        if(display_error == 1){
            printf("Error: Error Handler Not Found [ 0x03 ]\n");
        }

        if(error_code == 404){
            // 404 Handler Not Found!
            strcpy(web_buffer, "Error 404 page not found,<br>");
            strcat(web_buffer, "additional error occurred<br>");
            strcat(web_buffer, "while finding 404 error handler page!");
        }

        // Send Header
        if(send_response_header(socket, error_code, "text/html", strlen(web_buffer)) == SOCKET_ERROR){
            if(display_error == 1){
                printf("Error: Unable To Send [Header] To Client [ 0x04 ]\n");
            }
        }

        // Send Content
        if(send_response_content(socket, web_buffer) == SOCKET_ERROR){
            if(display_error == 1){
                printf("Error: Unable To Send [Body] To Client [ 0x05 ]\n");
            }
        }
    }

    return 1;
}
