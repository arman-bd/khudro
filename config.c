
struct server_config {
    char default_ip[16];
    int default_port;
    char default_dir[512];
    int compression;
    unsigned long long max_buffer;
};

typedef struct server_config s_conf;

s_conf parse_config(char *file_path){

    FILE *fp;
    char *file_buff;
    long file_size;

    char *conf_array;
    char param_name[64];
    char param_value[512];
    int param_number;

    s_conf config_store;


    if((fp = fopen(file_path, "r")) != NULL){
        // Get File Size
        fseek(fp, 0L, SEEK_END);
        file_size = ftell(fp);
        fseek(fp, 0L, SEEK_SET);

        file_buff = malloc(file_size + 1);
        fread(file_buff, sizeof(char), file_size + 1, fp);
        conf_array = strtok(file_buff, "\r\n");
        free(file_buff);

        while(conf_array != NULL){
            if(conf_array[0] == '#'){
                sscanf(conf_array, "#%s %s", param_name, param_value);

                // Place Appropriately
                if(strcmp(param_name, "default_ip") == 0){
                    strcpy(config_store.default_ip, param_value);
                }
                if(strcmp(param_name, "default_port") == 0){
                    sscanf(param_value, "%d", &config_store.default_port);
                }
                if(strcmp(param_name, "default_dir") == 0){
                    strcpy(config_store.default_dir, param_value);
                }
                if(strcmp(param_name, "compression") == 0){
                    sscanf(param_value, "%d", &config_store.compression);
                }
                if(strcmp(param_name, "max_buffer") == 0){

                    config_store.max_buffer = 0;

                    if(strstr(param_value, "KB") != NULL){
                        sscanf(param_value, "%dKB", &param_number);
                        config_store.max_buffer = (unsigned long long)param_number * 1024;
                    }
                    if(strstr(param_value, "MB") != NULL){
                        sscanf(param_value, "%dMB", &param_number);
                        config_store.max_buffer = (unsigned long long)param_number * 1024 * 1024;
                    }
                    if(strstr(param_value, "GB") != NULL){
                        sscanf(param_value, "%dGB", &param_number);
                        config_store.max_buffer = (unsigned long long)param_number * 1024 * 1024 * 1024;
                    }
                }
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
        config_store.max_buffer = 0;
    }

    return config_store;
}
