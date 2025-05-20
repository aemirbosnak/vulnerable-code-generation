//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_RESPONSE_LENGTH 1024

int main() {
    int socket_fd;
    struct addrinfo *server_info;
    char *host = "localhost";
    char *username = "anonymous";
    char *password = "anonymous@example.com";
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    int command_len;
    int response_len;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_info, 0, sizeof(struct addrinfo));
    server_info->ai_family = AF_INET;
    server_info->ai_socktype = SOCK_STREAM;
    server_info->ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(host, "21", &server_info, NULL)!= 0) {
        printf("Error resolving host\n");
        exit(1);
    }

    if (connect(socket_fd, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(command, "USER %s\r\n", username);
    send(socket_fd, command, strlen(command), 0);

    response_len = recv(socket_fd, response, MAX_RESPONSE_LENGTH, 0);
    response[response_len] = '\0';
    printf("Response: %s\n", response);

    sprintf(command, "PASS %s\r\n", password);
    send(socket_fd, command, strlen(command), 0);

    response_len = recv(socket_fd, response, MAX_RESPONSE_LENGTH, 0);
    response[response_len] = '\0';
    printf("Response: %s\n", response);

    close(socket_fd);
    return 0;
}