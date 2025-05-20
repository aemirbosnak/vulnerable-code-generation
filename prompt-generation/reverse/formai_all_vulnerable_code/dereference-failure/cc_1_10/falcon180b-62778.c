//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 110
#define USER "username"
#define PASS "password"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    char *username = strdup(USER);
    char *password = strdup(PASS);

    strcat(buffer, "USER ");
    strcat(buffer, username);
    strcat(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    strcat(buffer, "PASS ");
    strcat(buffer, password);
    strcat(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    char *response = (char *)malloc(BUFFER_SIZE);
    memset(response, 0, BUFFER_SIZE);

    while (1) {
        int bytes_received = recv(sockfd, response, BUFFER_SIZE - 1, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        response[bytes_received] = '\0';
        printf("%s", response);

        if (strcmp(response, ".") == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}