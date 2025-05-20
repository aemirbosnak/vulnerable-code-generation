//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_LINE_SIZE 512

char *host = "localhost";
int port = 110;

int main() {
    int sockfd;
    char *response = malloc(BUFFER_SIZE);
    char *username = "username";
    char *password = "password";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error: Socket creation failed.\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Connection failed.\n");
        exit(1);
    }

    printf("Connected to %s:%d\n", host, port);

    char *command = "USER ";
    strcat(command, username);
    strcat(command, "\r\n");

    send(sockfd, command, strlen(command), 0);

    char *buffer = malloc(BUFFER_SIZE);
    memset(buffer, 0, BUFFER_SIZE);

    if (recv(sockfd, response, BUFFER_SIZE, 0) == -1) {
        printf("Error: Receiving response failed.\n");
        exit(1);
    }

    printf("Response: %s", response);

    strcat(command, "PASS ");
    strcat(command, password);
    strcat(command, "\r\n");

    send(sockfd, command, strlen(command), 0);

    if (recv(sockfd, response, BUFFER_SIZE, 0) == -1) {
        printf("Error: Receiving response failed.\n");
        exit(1);
    }

    printf("Response: %s", response);

    strcat(command, "LIST\r\n");

    send(sockfd, command, strlen(command), 0);

    if (recv(sockfd, response, BUFFER_SIZE, 0) == -1) {
        printf("Error: Receiving response failed.\n");
        exit(1);
    }

    printf("Response: %s", response);

    close(sockfd);

    return 0;
}