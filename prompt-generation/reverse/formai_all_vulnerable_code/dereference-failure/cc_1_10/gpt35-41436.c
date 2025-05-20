//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc < 4) {
        printf("Usage: %s hostname port username password\n", argv[0]);
        return 1;
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0) {
        perror("Failed to create socket");
        return 1;
    }

    char hostname[MAX_BUFFER_SIZE];
    strcpy(hostname, argv[1]);

    struct hostent *host_info = gethostbyname(hostname);
    if(!host_info) {
        perror("Failed to get host information");
        close(sock_fd);
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    if(connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to host");
        close(sock_fd);
        return 1;
    }

    char command[MAX_BUFFER_SIZE];
    char recv_buffer[MAX_BUFFER_SIZE];

    recv(sock_fd, recv_buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", recv_buffer);

    sprintf(command, "USER %s\r\n", argv[3]);
    send(sock_fd, command, strlen(command), 0);
    recv(sock_fd, recv_buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", recv_buffer);

    sprintf(command, "PASS %s\r\n", argv[4]);
    send(sock_fd, command, strlen(command), 0);
    recv(sock_fd, recv_buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", recv_buffer);

    sprintf(command, "LIST\r\n");
    send(sock_fd, command, strlen(command), 0);

    memset(recv_buffer, 0, sizeof(recv_buffer));
    while(recv(sock_fd, recv_buffer, MAX_BUFFER_SIZE, 0) > 0) {
        printf("%s", recv_buffer);
        if(strstr(recv_buffer, "\r\n.\r\n")) {
            break;
        }
        memset(recv_buffer, 0, sizeof(recv_buffer));
    }

    sprintf(command, "QUIT\r\n");
    send(sock_fd, command, strlen(command), 0);
    recv(sock_fd, recv_buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", recv_buffer);

    close(sock_fd);
    return 0;
}