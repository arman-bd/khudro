/*
Project: Khudro Web-Server

By: Arman Hossain
CSE 11'th Batch,
Shanto-Mariam University of Creative Technology
Dhaka, Bangladesh

GitHub: https://github.com/arman-bd/khudro
*/

char __ServerName[128] = "Khudro";
char __ServerVersion[16] = "0.1.1";
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
#include "request.c"
#include "response.c"

int main(){

    // Socket
    WORD versionRequested;
    WSADATA wsaData;
    int wsaError;
    int bytesRecv = SOCKET_ERROR;
    SOCKET MainSocket;
    SOCKET AcceptSocket;

    // Request Data
    rqpack request_data;

    // File
    FILE *fp;
    char *file_type = malloc(128);
    size_t file_size = 0;

    // Print Application Name
    printf("::: %s v%s - %s :::\n\n", __ServerName, __ServerVersion, __ServerOS);

    // Load Default Configuration
    s_conf server_conf;
    server_conf = parse_config("khudro.conf", 1);

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
    struct sockaddr_in service;
    service.sin_family = AF_INET; // AF_INET is the Internet address family.
    service.sin_addr.s_addr = inet_addr(server_conf.default_ip); // Local IP
    service.sin_port = htons(server_conf.default_port);// Local Port

    // Bind Socket
    if (bind(MainSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR){
        printf("Error: Binding Failed - %ld.\n", WSAGetLastError());
        printf("       Check If Port Is Already In Use.\n");
        closesocket(MainSocket);
        return 0;
    }else{
        printf("Server: Binded Successfully\n");
        printf("Server: IP [ %s ]\n", server_conf.default_ip);
    }

    if(listen(MainSocket, 10) == SOCKET_ERROR){
       printf("Error: Unable To Listen On Port [ %d ] - %ld.\n", server_conf.default_port, WSAGetLastError());
    }else{
       printf("Server: Listening On Port [ %d ]\n", server_conf.default_port);
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
    bytesRecv = process_request(AcceptSocket, server_conf, &request_data);


    if(bytesRecv == -1){
        // PING Request
        closesocket(AcceptSocket); // Close Socket
        goto listen_for_client; // Repeat Process
    }

    if((fp = fopen(request_data.file_path, "rb")) != NULL){
        /* File Found, Now Get Some Information About File And Send It */
        get_mime_type(request_data.file_name, file_type); // Get MIME Type
        file_size = getFileSize(fp); // Get File Size
        send_response_header(AcceptSocket, 200, file_type, file_size); // Send Header
        send_response_file(AcceptSocket, fp, file_size, server_conf.max_buffer); // Send File To Client
        fclose(fp); // Close File
    }else{
        send_response_error(AcceptSocket, 404, server_conf, 0); // No Debug Print
    }


    closesocket(AcceptSocket); // Close Connection
    goto listen_for_client; // Repeat Process

    WSACleanup();
    return 0;
}
