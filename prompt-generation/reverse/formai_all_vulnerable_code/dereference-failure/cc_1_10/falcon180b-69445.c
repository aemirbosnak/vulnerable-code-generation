//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 110
#define MAX_LINE 1024

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAX_LINE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    if (sockfd < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char *username = "your_username";
    char *password = "your_password";

    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);

    char *response = (char *)malloc(MAX_LINE);
    memset(response, 0, MAX_LINE);

    int bytes_received = recv(sockfd, response, MAX_LINE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Server response: %s\n", response);

    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", 2, 0);

    memset(response, 0, MAX_LINE);

    bytes_received = recv(sockfd, response, MAX_LINE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Server response: %s\n", response);

    close(sockfd);

    return 0;
}