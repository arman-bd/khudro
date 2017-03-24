/*
struct server_config {
    char default_ip[16];
    int default_port;
    char default_dir[512];
    int compression;
};

typedef struct server_config s_conf;
*/


int send_header(SOCKET socket, int response, char *c_type, long c_size){
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

int send_content(SOCKET socket, char *content){
    return send(socket, content, strlen(content), 0);
}

int send_file(SOCKET socket, FILE *fp, int file_size){
    int byteSent = SOCKET_ERROR;
    char *file_buff;

    file_buff = malloc(file_size + 1);
    fread(file_buff, sizeof(char), file_size + 1, fp);
    byteSent = send(socket, file_buff, file_size, 0);
    free(file_buff);
    return byteSent;
}

long getFileSize(FILE *fp){
    long file_size = 0;

    // Get File Size
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    return file_size;
}

/*
THIS NEEDS TO BE DONE!!!
s_conf parse_config(char *file_path){

    FILE *fp;
    char *conf_array;
    char *conf_value;
    char *file_buff;
    long file_size;
    int i, j, k;

    s_conf config_store;


    if((fp = fopen(file_path, "r")) != NULL){
        file_size = getFileSize(fp);
        file_buff = malloc(file_size + 1);
        fread(file_buff, sizeof(char), file_size + 1, fp);

        conf_array = strtok(file_buff, "\r\n");
        while(conf_array != NULL){
            printf(">> %s\n", conf_array);

            if(strstr(conf_array, "#default_ip ") != NULL){

            }

            if(strstr(conf_array, "#default_dir ") != NULL){
                conf_line = strtok(conf_array, " ");
                conf_line = strtok(NULL, " ");
                strcpy(config_store.default_dir, conf_line);
            }
            if(strstr(conf_array, "#default_port ") != NULL){
                conf_line = strtok(conf_array, " ");
                conf_line = strtok(NULL, " ");
                config_store.default_port = atoi(conf_line);
            }
            if(strstr(conf_array, "#compression ") != NULL){
                conf_line = strtok(conf_array, " ");
                conf_line = strtok(NULL, " ");
                config_store.compression = atoi(conf_line);
            }


            conf_array = strtok(NULL, "\r\n");
        }

        fclose(fp);
    }else{
        printf("Error: Config File Not Found\n");
        strcpy(config_store.default_ip, "127.0.0.1");
        config_store.default_port = 8080;
        strcpy(config_store.default_dir, "htdocs");
        config_store.compression = 0;
    }

    return config_store;
}
*/
