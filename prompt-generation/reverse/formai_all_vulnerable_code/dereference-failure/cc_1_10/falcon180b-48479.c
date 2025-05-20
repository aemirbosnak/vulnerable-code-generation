//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 21
#define HOST "localhost"
#define USER "username"
#define PASS "password"

int main() {
    int sockfd;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];
    char *username = USER;
    char *password = PASS;
    char *host = HOST;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    inet_pton(AF_INET, host, &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    char *auth_str = (char *)malloc(strlen(username) + strlen(password) + 3);
    sprintf(auth_str, "%s:%s", username, password);

    send(sockfd, auth_str, strlen(auth_str), 0);

    char *response = recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s\n", response);

    close(sockfd);
    return 0;
}