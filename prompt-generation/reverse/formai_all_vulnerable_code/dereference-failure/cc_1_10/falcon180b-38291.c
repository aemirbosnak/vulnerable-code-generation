//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024
#define USERNAME "username"
#define PASSWORD "password"

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *ip_address = "127.0.0.1";
    char *port_number = "21";
    char *username = USERNAME;
    char *password = PASSWORD;
    char *command;
    int n;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <command> <file>\n", argv[0]);
        exit(1);
    }

    command = argv[1];
    if (strcmp(command, "put")!= 0 && strcmp(command, "get")!= 0) {
        printf("Invalid command\n");
        exit(1);
    }

    if (strcmp(command, "get") == 0) {
        strcat(ip_address, ":");
        strcat(ip_address, port_number);
        strcat(ip_address, "/");
        strcat(ip_address, argv[2]);
    } else {
        strcat(ip_address, ":");
        strcat(ip_address, port_number);
        strcat(ip_address, "/");
        strcat(ip_address, argv[2]);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("socket failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port_number));
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect failed");
    }

    if (strcmp(command, "put") == 0) {
        send(sockfd, argv[2], strlen(argv[2]), 0);
        send(sockfd, "\r\n", 2, 0);
        close(sockfd);
        printf("File uploaded successfully\n");
    } else {
        while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
            buffer[n] = '\0';
            printf("%s", buffer);
        }
        close(sockfd);
    }

    return 0;
}