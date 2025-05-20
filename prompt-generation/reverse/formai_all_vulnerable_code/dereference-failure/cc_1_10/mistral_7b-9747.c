//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd;
    struct addrinfo hints, *res;
    int rc;
    char buffer[BUFFER_SIZE];
    char request[BUFFER_SIZE];
    struct sockaddr_in server_addr;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((rc = getaddrinfo("example.com", "http", &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rc));
        return 1;
    }

    if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
        perror("socket");
        freeaddrinfo(res);
        return 1;
    }

    server_addr.sin_family = res->ai_family;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, res->ai_addr->sa_data, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof server_addr) < 0) {
        perror("connect");
        close(sockfd);
        freeaddrinfo(res);
        return 1;
    }

    snprintf(request, BUFFER_SIZE, "GET /path/to/resource HTTP/1.1\r\n"
                                   "Host: example.com\r\n"
                                   "Custom-Header: Value\r\n"
                                   "Accept: */*\r\n"
                                   "Connection: close\r\n\r\n");

    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        close(sockfd);
        freeaddrinfo(res);
        return 1;
    }

    int received = 0;
    while ((received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("%.*s", (int) received, buffer);
    }

    if (received < 0) {
        perror("recv");
    }

    close(sockfd);
    freeaddrinfo(res);
    return 0;
}