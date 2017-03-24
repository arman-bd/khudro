
void pack_header(int response, char *c_type, long c_size, char *header){
    char lenbuf[32] = "";

    if(response == 200){
        strcpy(header, "HTTP/1.1 200 OK\n");
    }

    if(response == 404){
        strcpy(header, "HTTP/1.1 404 Not Found\n");
    }

    strcat(header, "Content-Type: ");
    strcat(header, c_type);
    strcat(header, "; charset=utf-8\n");
    strcat(header, "Content-Length: ");
    sprintf(lenbuf, "%ld", c_size);
    strcat(header, lenbuf);
    strcat(header, "\n\n");
    return;
}

int send_file(FILE *fp, SOCKET socket, int file_size){

    int byteSent;
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
