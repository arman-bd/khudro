/*
Project: Khudro Web-Server
By: Arman Hossain

GitHub: https://github.com/arman-bd/khudro
*/

char __ServerName[128] = "Khudro";
char __ServerVersion[16] = "0.0.1";
char __ServerOS[32] = "Win32";

// Include Required Headers
#include<io.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<sys/stat.h>

// Windows Library
#include<winsock2.h>


// Include Required File
#include "config.c"
#include "mime-list.c"
#include "function.c"

int main(){

    // Misc.
    int i, j;

    // Socket
    WORD versionRequested;
    WSADATA wsaData;
    int wsaError;
    int bytesRecv = SOCKET_ERROR;
    SOCKET MainSocket;
    SOCKET AcceptSocket;

    // Received Header
    char receive_buffer[4096];
    char *receive_array;
    char request_method[8];

    // Web Output
    char web_buffer[512];

    // File
    FILE *fp;
    char file_name[1024] = "";
    char file_path[4096] = "";
    char *file_type = malloc(128);
    size_t file_size = 0;

    // Configuration
    char default_ip[16] = "127.0.0.1";
    char default_dir[512] = "htdocs";
    int default_port = 8080;
    int compression = 0;
    size_t max_buffer = 0;

    // Load Default Configuration
    s_conf server_conf;
    server_conf = parse_config("G:\\GitHub\\khudro\\khudro.conf");

    if(strcmp(default_ip, server_conf.default_ip)){
        strcpy(default_ip, server_conf.default_ip);
    }
    if(strcmp(default_dir, server_conf.default_dir)){
        strcpy(default_dir, server_conf.default_dir);
    }
    if(default_port != server_conf.default_port){
        default_port = server_conf.default_port;
    }
    if(compression != server_conf.compression){
        compression = server_conf.compression;
    }
    if(max_buffer != server_conf.max_buffer){
        max_buffer = server_conf.max_buffer;
    }


    /* Start Socket Initialization */
    versionRequested = MAKEWORD(2, 2);

    wsaError = WSAStartup(versionRequested, &wsaData);
    if(wsaError != 0){
        printf("Error: Winsock Dll Not Found!\n");
        return 0;
    }else{
        printf("Server: Winsock Found.\n");
    }

    // Check Winsock DLL Version : 2.2
    if(LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2 ){
        printf("Error: Unsupported Winsock Dll Version - v%u.%u!\n", LOBYTE(wsaData.wVersion), HIBYTE(wsaData.wVersion));
        WSACleanup();
        return 0;
    }

    // Define Socket Preference
    MainSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // Check Socket Validity
    if(MainSocket == INVALID_SOCKET){
        printf("Error: Socket Error - %ld\n", WSAGetLastError());
        WSACleanup();
        return 0;
    }else{
        printf("Server: Socket Loaded\n");
    }


    /* Start Binding */

    // Create a sockaddr_in object
    struct sockaddr_in service;

    // AF_INET is the Internet address family.
    service.sin_family = AF_INET;
    // "127.0.0.1" is the local IP address to which the socket will be bound.
    service.sin_addr.s_addr = inet_addr(default_ip);
    // 55555 is the port number to which the socket will be bound.
    service.sin_port = htons(default_port);

    // Bind Socket
    if (bind(MainSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR){
        printf("Error: Binding Failed - %ld.\n", WSAGetLastError());
        printf("       Check If Port Is Already In Use.\n");
        closesocket(MainSocket);
        return 0;
    }else{
        printf("Server: Binded Successfully\n");
        printf("Server: IP [ %s ]\n", default_ip);
    }



    if(listen(MainSocket, 10) == SOCKET_ERROR){
       printf("Error: Unable To Listen On Port [ %d ] - %ld.\n", default_port, WSAGetLastError());
    }else{
       printf("Server: Listening On Port [ %d ]\n", default_port);
    }

    printf("\n");

    // Listen For Request
    listen_for_client:

    while(1){
        AcceptSocket = SOCKET_ERROR;

        while(AcceptSocket == SOCKET_ERROR){
            AcceptSocket = accept(MainSocket, NULL, NULL);
        }

        break;
    }

    // Receive Data From Client
    bytesRecv = recv(AcceptSocket, receive_buffer, 4096, 0);

    if(bytesRecv == SOCKET_ERROR){
        printf("Error: Data Receive Error [ 0x01 ] - %ld\n", WSAGetLastError());
    }else{
        if(bytesRecv == 0){ // PING Request
            //printf("Server: PING Request\n");
            // Close Connection
            closesocket(AcceptSocket);
            // Repeat Process
            goto listen_for_client;
        }

        // Process Received Header
        receive_array = strtok(receive_buffer, "\n");

        // Re-Tokenize To Parse First Lines
        receive_array = strtok(receive_array, " ");

        // Not We Have Request Method [ GET, POST, PUT, DELETE ]
        strcpy(request_method, receive_array);

        // Move To Next Data [ URL ]
        receive_array = strtok(NULL, " ");

        // Now We Have Requested URL
        strcpy(file_name, receive_array);

        // Check If ? Exists
        for(i = 0; i < strlen(file_name); i++){
            if(file_name[i] == '?'){
                // Discard [ Query Parameter ]
                for(j = i; j < strlen(file_name); j++){
                    file_name[j] = '\0';
                }
            }
        }


        // Check For Basic
        if(strcmp(file_name, "/") == 0){ // For index.html
            strcpy(file_name, "/index.html");
        }

        // Convert Slash
        for(i = 0; i < strlen(file_name); i++){
            if(file_name[i] == '/'){
                file_name[i] = '\\';
            }
        }

        // Make File Path
        sprintf(file_path, "%s%s", default_dir, file_name);

        // Display Info About Requested File
        //printf("> Requested File: %s [ %s ]\n", file_path, file_type);
    }

    if((fp = fopen(file_path, "rb")) != NULL){
        /* File Found, Now Get Some Information About File And Send It */

        // Get MIME Type
        get_mime_type(file_name, file_type);
        // Get File Size
        file_size = getFileSize(fp);
        // Send Header
        send_header(AcceptSocket, 200, file_type, file_size);
        // Send File To Client
        send_file(AcceptSocket, fp, file_size, max_buffer);
        // Close File
        fclose(fp);
    }else{
        // Content Not Found!
        printf("Error: File Not Found [ 0x02 ]\n");

        // Try 404 Handler!
        sprintf(file_name, "\\error404.html");
        sprintf(file_path, "%s%s", default_dir, file_name);

        // Get MIME Type
        get_mime_type(file_name, file_type);

        if((fp = fopen(file_path, "rb")) != NULL){
            // Get File Size
            file_size = getFileSize(fp);
            // Pack Header
            send_header(AcceptSocket, 404, file_type, file_size);
            // Send File To Client
            send_file(AcceptSocket, fp, file_size, max_buffer);
            // Close File
            fclose(fp);
        }else{
            printf("Error: Error Handler Not Found [ 0x03 ]\n");
            // 404 Handler Not Found!
            strcpy(web_buffer, "Error 404 page not found,<br>");
            strcat(web_buffer, "additional error occurred<br>");
            strcat(web_buffer, "while finding 404 error handler page!");

            // Send Header
            if(send_header(AcceptSocket, 404, "text/html", strlen(web_buffer)) == SOCKET_ERROR){
                printf("Error: Unable To Send [Header] To Client [ 0x04 ]\n");
            }

            // Send Content
            if(send_content(AcceptSocket, web_buffer) == SOCKET_ERROR){
                printf("Error: Unable To Send [Body] To Client [ 0x05 ]\n");
            }
        }
    }

    // Close Connection
    closesocket(AcceptSocket);

    // Repeat Process
    goto listen_for_client;

    WSACleanup();
    return 0;
}
