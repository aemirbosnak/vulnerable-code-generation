//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *username = "anonymous";
    char *password = "anonymous@example.com";
    char *command = "LIST";

    if (argc < 4) {
        printf("Usage: %s <server_ip> <port> <command>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    printf("Connected to server\n");

    if (send(sockfd, username, strlen(username), 0) == -1) {
        printf("Error sending username\n");
        close(sockfd);
        return 1;
    }

    if (send(sockfd, password, strlen(password), 0) == -1) {
        printf("Error sending password\n");
        close(sockfd);
        return 1;
    }

    if (send(sockfd, command, strlen(command), 0) == -1) {
        printf("Error sending command\n");
        close(sockfd);
        return 1;
    }

    close(sockfd);

    return 0;
}