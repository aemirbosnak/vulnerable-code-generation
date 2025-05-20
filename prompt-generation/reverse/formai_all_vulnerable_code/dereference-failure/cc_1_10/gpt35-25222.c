//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>

#define PORT 21
#define BUFF_SIZE 1024

// Function to send commands to the FTP server
void send_command(int sock_fd, char* command) {
    char buf[BUFF_SIZE];
    sprintf(buf, "%s\r\n", command);
    send(sock_fd, buf, strlen(buf), 0);
}

// Function to receive response from the FTP server
void receive_response(int sock_fd, char* response) {
    char buf[BUFF_SIZE];
    memset(buf, 0, sizeof(buf));
    int bytes_received = recv(sock_fd, buf, sizeof(buf), 0);
    strcat(response, buf);
    while(bytes_received==BUFF_SIZE-1) {
        memset(buf, 0, sizeof(buf));
        bytes_received = recv(sock_fd, buf, sizeof(buf), 0);
        strcat(response, buf);
    }
}

int main(int argc, char** argv) {
    int sock_fd;
    struct sockaddr_in server_address;

    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket.");
        exit(1);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if(connect(sock_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server.");
        exit(1);
    }

    char response[BUFF_SIZE];
    memset(response, 0, sizeof(response));
    receive_response(sock_fd, response);
    printf("%s", response);

    char* username = "USERNAME";
    char* password = "PASSWORD";
    send_command(sock_fd, "USER");
    receive_response(sock_fd, response);
    printf("%s", response);
    send_command(sock_fd, username);
    receive_response(sock_fd, response);
    printf("%s", response);
    send_command(sock_fd, "PASS");
    receive_response(sock_fd, response);
    printf("%s", response);
    send_command(sock_fd, password);
    receive_response(sock_fd, response);
    printf("%s", response);

    send_command(sock_fd, "PWD");
    memset(response, 0, sizeof(response));
    receive_response(sock_fd, response);
    printf("%s", response);

    char path[BUFF_SIZE], command[BUFF_SIZE];
    memset(path, 0, sizeof(path));

    while(1) {
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\r\n")] = 0;
        char* cmd = strtok(command, " ");
        if(strcmp(cmd, "cd") == 0) {
            char* dir = strtok(NULL, " ");
            if(dir) {
                sprintf(path, "CWD %s", dir);
                send_command(sock_fd, path);
                memset(response, 0, sizeof(response));
                receive_response(sock_fd, response);
                printf("%s", response);
            } else {
                printf("Invalid command. Usage: cd <directory>\n");
            }
        } else if(strcmp(cmd, "ls") == 0) {
            char* data_address = "127,0,0,1,12,23";
            char* data_cmd = "NLST";
            char* port_cmd = "PORT 127,0,0,1,12,23";
            unsigned int data_sock_fd;
            struct sockaddr_in data_address_info;
            char data_buffer[BUFF_SIZE];
            int bytes_received;

            if((data_sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                perror("Failed to create socket.");
                exit(1);
            }

            memset(&data_address_info, 0, sizeof(data_address_info));
            data_address_info.sin_family = AF_INET;
            data_address_info.sin_port = htons(3059);
            inet_pton(AF_INET, data_address, &(data_address_info.sin_addr));

            if(connect(data_sock_fd, (struct sockaddr*) &data_address_info, sizeof(data_address_info)) < 0) {
                perror("Failed to connect to data socket.");
                exit(1);
            }

            char data_response[BUFF_SIZE];
            memset(data_response, 0, sizeof(data_response));
            receive_response(sock_fd, data_response);
            printf("%s", data_response);

            send_command(sock_fd, port_cmd);
            receive_response(sock_fd, data_response);
            printf("%s", data_response);

            send_command(sock_fd, data_cmd);

            memset(data_buffer, 0, sizeof(data_buffer));
            bytes_received = recv(data_sock_fd, data_buffer, sizeof(data_buffer), 0);
            while(bytes_received > 0) {
                printf("%s", data_buffer);
                memset(data_buffer, 0, sizeof(data_buffer));
                bytes_received = recv(data_sock_fd, data_buffer, sizeof(data_buffer), 0);
            }

            close(data_sock_fd);
        } else if(strcmp(cmd, "put") == 0) {
            char* file = strtok(NULL, " ");
            if(file) {
                char file_path[BUFF_SIZE];
                sprintf(file_path, "./%s", file);
                if(access(file_path, F_OK) != -1) {
                    char* data_address = "127,0,0,1,12,24";
                    char* port_cmd = "PORT 127,0,0,1,12,24";
                    char* data_cmd = "STOR";
                    unsigned int data_sock_fd;
                    struct sockaddr_in data_address_info;

                    if((data_sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                        perror("Failed to create socket.");
                        exit(1);
                    }

                    memset(&data_address_info, 0, sizeof(data_address_info));
                    data_address_info.sin_family = AF_INET;
                    data_address_info.sin_port = htons(3060);
                    inet_pton(AF_INET, data_address, &(data_address_info.sin_addr));

                    if(connect(data_sock_fd, (struct sockaddr*) &data_address_info, sizeof(data_address_info)) < 0) {
                        perror("Failed to connect to data socket.");
                        exit(1);
                    }

                    char data_response[BUFF_SIZE];
                    memset(data_response, 0, sizeof(data_response));
                    receive_response(sock_fd, data_response);
                    printf("%s", data_response);

                    send_command(sock_fd, port_cmd);
                    receive_response(sock_fd, data_response);
                    printf("%s", data_response);

                    char data_buffer[BUFF_SIZE];
                    memset(data_buffer, 0, sizeof(data_buffer));

                    FILE* file_ptr = fopen(file_path, "r");
                    if(file_ptr == NULL) {
                        perror("Failed to open file");
                        exit(1);
                    }
                    int bytes_read = fread(data_buffer, 1, sizeof(data_buffer), file_ptr);
                    while(bytes_read > 0) {
                        send(data_sock_fd, data_buffer, bytes_read, 0);
                        memset(data_buffer, 0, sizeof(data_buffer));
                        bytes_read = fread(data_buffer, 1, sizeof(data_buffer), file_ptr);
                    }

                    fclose(file_ptr);
                    close(data_sock_fd);

                    memset(data_response, 0, sizeof(data_response));
                    receive_response(sock_fd, data_response);
                    printf("%s", data_response);
                } else {
                    printf("File not found.\n");
                }
            } else {
                printf("Invalid command. Usage: put <file>\n");
            }
        } else if(strcmp(cmd, "get") == 0) {
            char* file = strtok(NULL, " ");
            if(file) {
                char* data_address = "127,0,0,1,12,24";
                char* port_cmd = "PORT 127,0,0,1,12,24";
                char* data_cmd = "RETR";
                char data_buffer[BUFF_SIZE];
                unsigned int data_sock_fd;
                struct sockaddr_in data_address_info;

                if((data_sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                    perror("Failed to create socket.");
                    exit(1);
                }

                memset(&data_address_info, 0, sizeof(data_address_info));
                data_address_info.sin_family = AF_INET;
                data_address_info.sin_port = htons(3060);
                inet_pton(AF_INET, data_address, &(data_address_info.sin_addr));

                if(connect(data_sock_fd, (struct sockaddr*) &data_address_info, sizeof(data_address_info)) < 0) {
                    perror("Failed to connect to data socket.");
                    exit(1);
                }

                char data_response[BUFF_SIZE];
                memset(data_response, 0, sizeof(data_response));
                receive_response(sock_fd, data_response);
                printf("%s", data_response);

                send_command(sock_fd, port_cmd);
                receive_response(sock_fd, data_response);
                printf("%s", data_response);

                char get_cmd[BUFF_SIZE];
                sprintf(get_cmd, "%s %s", data_cmd, file);
                send_command(sock_fd, get_cmd);

                memset(data_buffer, 0, sizeof(data_buffer));
                int bytes_received = recv(data_sock_fd, data_buffer, sizeof(data_buffer), 0);
                FILE* f = fopen(file, "w");
                while(bytes_received > 0) {
                    fwrite(data_buffer, bytes_received, 1, f);
                    memset(data_buffer, 0, sizeof(data_buffer));
                    bytes_received = recv(data_sock_fd, data_buffer, sizeof(data_buffer), 0);
                }
                fclose(f);
                close(data_sock_fd);

                memset(data_response, 0, sizeof(data_response));
                receive_response(sock_fd, data_response);
                printf("%s", data_response);
            } else {
                printf("Invalid command. Usage: get <file>\n");
            }
        } else if(strcmp(cmd, "quit") == 0) {
            send_command(sock_fd, "QUIT");
            memset(response, 0, sizeof(response));
            receive_response(sock_fd, response);
            printf("%s", response);
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    close(sock_fd);

    return 0;
}