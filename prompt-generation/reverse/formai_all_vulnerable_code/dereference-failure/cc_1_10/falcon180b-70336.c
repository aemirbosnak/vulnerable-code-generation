//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error_handling(const char *message);

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./ftp_client <server_address> <port_number> <username>\n");
        return 1;
    }

    char *server_address = argv[1];
    int port_number = atoi(argv[2]);
    char *username = argv[3];

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo *server_info;
    if (getaddrinfo(server_address, NULL, &hints, &server_info)!= 0) {
        error_handling("getaddrinfo");
    }

    int sockfd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (sockfd == -1) {
        error_handling("socket");
    }

    if (connect(sockfd, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        error_handling("connect");
    }

    char *password = "password";
    char *buffer = malloc(BUFFER_SIZE);

    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    char response[BUFFER_SIZE];
    recv(sockfd, response, BUFFER_SIZE, 0);

    if (strcmp(response, "331")!= 0) {
        error_handling("invalid response to USER command");
    }

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, response, BUFFER_SIZE, 0);

    if (strcmp(response, "230")!= 0) {
        error_handling("invalid response to PASS command");
    }

    char command[BUFFER_SIZE];
    while (fgets(command, BUFFER_SIZE, stdin)!= NULL) {
        if (strncmp(command, "ls", 2) == 0) {
            strcat(command, "\r\n");
            send(sockfd, command, strlen(command), 0);

            memset(response, 0, BUFFER_SIZE);
            recv(sockfd, response, BUFFER_SIZE, 0);

            printf("%s", response);
        } else if (strncmp(command, "get", 3) == 0) {
            strcat(command, "\r\n");
            send(sockfd, command, strlen(command), 0);

            memset(response, 0, BUFFER_SIZE);
            recv(sockfd, response, BUFFER_SIZE, 0);

            printf("%s", response);
        } else if (strncmp(command, "quit", 4) == 0) {
            strcat(command, "\r\n");
            send(sockfd, command, strlen(command), 0);

            close(sockfd);
            free(buffer);
            return 0;
        } else {
            printf("Invalid command\n");
        }
    }

    close(sockfd);
    free(buffer);

    return 0;
}

void error_handling(const char *message) {
    perror(message);
    exit(1);
}