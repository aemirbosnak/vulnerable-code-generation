//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server ip> <server port> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char message[BUF_SIZE] = {0};
    sprintf(message, "From: user@example.com\nTo: recipient@example.com\nSubject: Testing SMTP client\n\n%s", argv[3]);

    if (send(sockfd, message, strlen(message), 0) != strlen(message)) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    char response[BUF_SIZE] = {0};
    if (recv(sockfd, response, BUF_SIZE - 1, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", response);

    close(sockfd);
    return 0;
}