//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define USERNAME "your_username"
#define PASSWORD "your_password"

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];
    char *username = USERNAME;
    char *password = PASSWORD;

    if (argc!= 3) {
        printf("Usage: %s <server_address> <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed: %s\n", strerror(errno));
        return 1;
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Connection failed: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    printf("Connected to server\n");

    if (send(sockfd, username, strlen(username), 0) == -1) {
        printf("Send failed: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    if (send(sockfd, password, strlen(password), 0) == -1) {
        printf("Send failed: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}