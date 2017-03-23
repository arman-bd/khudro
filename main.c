/*
Project: Khudro Web-Server
By: Arman Hossain

GitHub: https://github.com/arman-bd/khudro
*/

// Include Required Headers
#include<io.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Winsock Library
#include<winsock2.h>

// Include Required File
#include "mime-list.c"


int send_file(FILE *fp, SOCKET socket, int file_size);

int main(){
    // Misc.
    int i;

    // Socket
    WORD versionRequested;
    WSADATA wsaData;
    int wsaError;
    int default_port = 8080;
    int bytesSent;
    int bytesRecv = SOCKET_ERROR;
    SOCKET AcceptSocket;
    char header[4096];
    char recvbuf[4096];
    char lenbuf[32];

    // Received Header
    char *receive_array;
    char request_method[8];

    // File
    FILE *fp;
    char file_directory[512] = "G:\\GitHub\\khudro\\htdocs";
    char file_name[1024] = "";
    char file_path[4096] = "";
    char file_type[256] = "";
    long file_size = 0;


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

    // Create Socket
    SOCKET m_socket;

    // Define Socket Preference
    m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // Check Socket Validity
    if(m_socket == INVALID_SOCKET){
        printf("Error: Socket Error - %ld\n", WSAGetLastError());
        WSACleanup();
        return 0;
    }else{
        printf("Server: Socket Loaded");
    }

    /* BIND */

    // Create a sockaddr_in object
    struct sockaddr_in service;

    // AF_INET is the Internet address family.
    service.sin_family = AF_INET;
    // "127.0.0.1" is the local IP address to which the socket will be bound.
    service.sin_addr.s_addr = inet_addr("127.0.0.1");
    // 55555 is the port number to which the socket will be bound.
    service.sin_port = htons(default_port);

    // Bind Socket
    if (bind(m_socket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR){
        printf("Error: Binding Failed - %ld.\n", WSAGetLastError());
        printf("       Check If Port Is Already In Use.\n");
        closesocket(m_socket);
        return 0;
    }else{
        printf("Server: Binded Successfully!\n");
    }

    // Listen For Request
    listen_for_client:

    if(listen(m_socket, 10) == SOCKET_ERROR){
       printf("\nError: Error Listening on Port [ %d ] - %ld.\n", default_port, WSAGetLastError());
    }else{
       printf("\nServer: Listening On Port [ %d ]\n", default_port);
    }



    printf("Server: Waiting For Client...\n" );
    // Do some verification...
    while(1){
        AcceptSocket = SOCKET_ERROR;

        while(AcceptSocket == SOCKET_ERROR){
            AcceptSocket = accept(m_socket, NULL, NULL);
        }

        printf("Server: Client Connected!\n");
        //m_socket = AcceptSocket;
        break;
    }

    // Receive Data From Client
    bytesRecv = recv(AcceptSocket, recvbuf, 4096, 0);

    if(bytesRecv == SOCKET_ERROR){
        printf("Server: Receive Error - %ld.\n", WSAGetLastError());
    }else{
        printf("Server: Data Received.\n");


        if(bytesRecv == 0){ // PING Request
            printf("Server: PING Request\n");
            // Close Connection
            closesocket(AcceptSocket);
            // Repeat Process
            goto listen_for_client;
        }
        printf("Server: Bytes Received: %ld.\n", bytesRecv);

        // Process Received Header
        receive_array = strtok(recvbuf, "\n");

        // Re-Tokenize To Parse First Lines
        receive_array = strtok(receive_array, " ");

        // Not We Have Request Method [ GET, POST, PUT, DELETE ]
        strcpy(request_method, receive_array);

        // Move To Next Data [ URL ]
        receive_array = strtok(NULL, " ");

        // Check If ? Exists


        // Now We Have Requested URL
        strcpy(file_name, receive_array);

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
        strcpy(file_path, file_directory);
        strcat(file_path, file_name);

        printf("> Requested File: %s\n", file_path);
        get_mime_type(file_name, &file_type);
    }
    if((fp = fopen(file_path, "rb")) != NULL){
        // Get File Size
        fseek(fp, 0L, SEEK_END);
        file_size = ftell(fp);
        fseek(fp, 0L, SEEK_SET);
        sprintf(lenbuf, "%ld", file_size);

        // Pack Header
        strcpy(header, "HTTP/1.1 200 OK\n");
        strcat(header, "Content-Type: ");
        strcat(header, file_type);
        strcat(header, "; charset=utf-8\n");
        strcat(header, "Content-Length: ");
        strcat(header, lenbuf);
        strcat(header, "\n\n");

        // Send Header First
        bytesSent = 0;
        bytesSent += send(AcceptSocket, header, strlen(header), 0);
        printf("\n>>> HEADER :: \n%s\n", header);

        // Send File To Client
        bytesSent += send_file(fp, AcceptSocket, file_size);

        // Close File Pointer
        fclose(fp);
    }else{
        // File Not Found
        strcpy(header, "HTTP/1.1 404 Not Found\n");
        strcat(header, "Content-Type: text/html; charset=utf-8\n");
        strcat(header, "Content-Length: 26");
        strcat(header, "\n\n");
        strcat(header, "Error 404 - File Not Found");

        bytesSent = 0;
        bytesSent += send(AcceptSocket, header, strlen(header), 0);
        printf("\n>>> HEADER :: \n%s\n", header);
    }


    if(bytesSent == SOCKET_ERROR){
           printf("Error: Unable To Send - %ld.\n", WSAGetLastError());
    }else{
           printf("Server: Data Sent.\n");
           printf("Server: Bytes Sent: %ld.\n", bytesSent);
    }

    // Close Connection
    closesocket(AcceptSocket);

    // Repeat Process
    goto listen_for_client;

    WSACleanup();
    return 0;
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


