

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

int send_file(SOCKET socket, FILE *fp, size_t file_size, size_t max_buffer){
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

size_t getFileSize(FILE *fp){
    size_t file_size = 0;

    // Get File Size
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    return file_size;
}

/*
    Generating RFC 1123 Time Stamp
    Source: http://stackoverflow.com/a/2727122
*/

/*
static const char *DAY_NAMES[] =
  { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
static const char *MONTH_NAMES[] =
  { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

char *Rfc1123_DateTime(time_t t){
    const int RFC1123_TIME_LEN = 29;
    struct tm tm;
    char * buf = malloc(RFC1123_TIME_LEN+1);

    gmtime_s(&tm, &t);

    strftime(buf, RFC1123_TIME_LEN+1, "---, %d --- %Y %H:%M:%S GMT", &tm);
    memcpy(buf, DAY_NAMES[tm.tm_wday], 3);
    memcpy(buf+8, MONTH_NAMES[tm.tm_mon], 3);

    return buf;
}
*/
