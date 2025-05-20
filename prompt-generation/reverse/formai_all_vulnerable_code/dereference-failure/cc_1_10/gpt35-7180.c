//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    char *host = argv[1];
    char *path = argv[2];
    char *method = "GET";

    // create socket
    struct addrinfo *res;
    int sockfd = 0;
    int status = getaddrinfo(host, "http", NULL, &res);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket error");
        return 1;
    }

    // connect to server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect error");
        return 1;
    }

    // send request
    char request[BUF_SIZE];
    sprintf(request, "%s %s HTTP/1.1\r\nHost: %s\r\n\r\n", method, path, host);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send error");
        return 1;
    }

    // receive response
    char response[BUF_SIZE];
    int recv_status = 0;
    while (recv_status != -1) {
        recv_status = recv(sockfd, response, BUF_SIZE, 0);
        if (recv_status == -1) {
            perror("recv error");
            return 1;
        }
        printf("%.*s", recv_status, response);
    }

    // cleanup
    freeaddrinfo(res);
    close(sockfd);

    return 0;
}