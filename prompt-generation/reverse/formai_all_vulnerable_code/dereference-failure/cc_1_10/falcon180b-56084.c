//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    memcpy(&servaddr.sin_addr, server->h_addr, server->h_length);
    servaddr.sin_port = htons(21);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char username_buf[64];
    char password_buf[64];
    snprintf(username_buf, sizeof(username_buf), "USER %s\r\n", username);
    snprintf(password_buf, sizeof(password_buf), "PASS %s\r\n", password);

    if (send(sockfd, username_buf, strlen(username_buf), 0) < 0) {
        printf("Error sending username\n");
        exit(1);
    }

    if (send(sockfd, password_buf, strlen(password_buf), 0) < 0) {
        printf("Error sending password\n");
        exit(1);
    }

    char response[BUF_SIZE];
    if (recv(sockfd, response, BUF_SIZE, 0) < 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Server response: %s\n", response);

    close(sockfd);
    return 0;
}