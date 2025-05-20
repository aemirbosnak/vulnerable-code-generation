//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAX_SIZE 2048

int main(int argc, char *argv[]) {
    char* server_address = argv[1];
    int port_number = atoi(argv[2]);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_address);
    server_addr.sin_port = htons(port_number);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    int connect_status = connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

    if(connect_status == -1) {
        printf("Error in establishing connection. Exiting...\n");
        exit(1);
    }

    char command[MAX_SIZE];
    char response[MAX_SIZE];
    char *token;
    char *remainder;
    int file_size, data_recv, total_recv, file_size_big_endian;

    printf("FTP Client\n\nAvailable Commands:\nget <filename>: Download file from server\nquit: Exit FTP Client\n");

    while(1) {
        printf("ftp> ");
        fgets(command, MAX_SIZE, stdin);
        if(strncmp(command, "get ", 4) == 0) {
            send(client_socket, command, strlen(command), 0);
            recv(client_socket, response, MAX_SIZE, 0);
            token = strtok_r(response, " ", &remainder);
            if(strcmp(token, "ERROR") == 0) {
                printf("File not found on server\n");
            }
            else {
                token = strtok_r(NULL, " ", &remainder);
                file_size_big_endian = atoi(token);
                file_size = ntohl(file_size_big_endian);
                FILE *fp = fopen(remainder, "wb");
                char buffer[MAX_SIZE];
                total_recv = 0;
                while(total_recv < file_size) {
                    data_recv = recv(client_socket, buffer, MAX_SIZE, 0);
                    fwrite(buffer, 1, data_recv, fp);
                    total_recv += data_recv;
                }
                fclose(fp);
                printf("File %s downloaded successfully\n", remainder);
            }
        }
        else if(strncmp(command, "quit", 4) == 0) {
            send(client_socket, command, strlen(command), 0);
            recv(client_socket, response, MAX_SIZE, 0);
            printf("%s\n", response);
            close(client_socket);
            exit(0);
        }
        else {
            printf("Invalid command\n");
        }
    }
    return 0;
}