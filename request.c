typedef struct rqpack {
    // Request Parameter
    char request_method[9];
    int compressed;

    // File Parameter
    char *requested_uri;
    char *file_name;
    char *file_path;
    char *query;
}rqpack;


int process_request(SOCKET socket, s_conf config_store, rqpack *request_data){

    int i, j;
    char file_name[2084]; // Maximum URL Length
    char file_path[2596];
    int bytesRecv = 0;

    char *buffer_data;
    char *receive_array;

    buffer_data = malloc(config_store.receive_buffer + 1);

    // Receive Data From Client
    bytesRecv = recv(socket, buffer_data, config_store.receive_buffer, 0);

    if(bytesRecv == SOCKET_ERROR){
        printf("Error: Data Receive Error [ 0x01 ] - %ld\n", WSAGetLastError());
    }else{
        if(bytesRecv == 0){ // PING Request
            // Close Connection
            // Repeat Process
            return bytesRecv;
        }

        /* Process Primary Buffer for Hint to Next */

        // Process Received Header
        receive_array = strtok(buffer_data, "\n");

        // Re-Tokenize To Parse First Lines
        receive_array = strtok(receive_array, " ");

        // Not We Have Request Method [ GET, POST, PUT, DELETE ]
        strcpy(request_data->request_method, receive_array);

        // Move To Next Data [ URL ]
        receive_array = strtok(NULL, " ");

        // Now We Have Requested URL
        strcpy(file_name, receive_array);
        request_data->requested_uri = malloc(strlen(file_name) + 1);
        request_data->requested_uri = file_name;

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

        url_decode((const char*)file_name, file_name);

        request_data->file_name = malloc(strlen(file_name) + 1);
        request_data->file_name = file_name;

        // Make File Path
        sprintf(file_path, "%s%s", config_store.default_dir, file_name);

        request_data->file_path = malloc(strlen(file_path) + 1);
        request_data->file_path = file_path;

        // Display Info About Requested File
        //printf("> Requested File: %s [ %s ]\n", file_path, file_type);
    }

    return 1;
}
