//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 4096

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[MAX_REQUEST_SIZE];
    char response[MAX_RESPONSE_SIZE];
    int response_len;

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <method>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    snprintf(request, MAX_REQUEST_SIZE, "%s %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\nContent-Length: 0\r\n\r\n", argv[3], argv[1], argv[1]);

    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        return 1;
    }

    response_len = 0;
    while ((response_len < MAX_RESPONSE_SIZE) && (response_len >= 0)) {
        if ((response_len = recv(sockfd, response + response_len, MAX_RESPONSE_SIZE - response_len, 0)) == -1) {
            if (errno!= EAGAIN) {
                perror("recv");
                return 1;
            }
        }
    }

    if (response_len == -1) {
        perror("recv");
        return 1;
    }

    response[response_len] = '\0';
    printf("%s", response);

    close(sockfd);
    return 0;
}