//GEMINI-pro DATASET v1.0 Category: Networking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>

int main() {
    int sockfd;
    struct addrinfo hints, *res;
    char hostname[] = "google.com";
    char port[] = "80";
    char request[] = "GET / HTTP/1.1\r\nHost: google.com\r\n\r\n";
    ssize_t n;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    if (getaddrinfo(hostname, port, &hints, &res) != 0) {
        perror("getaddrinfo");
        exit(1);
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("connect");
        exit(1);
    }

    freeaddrinfo(res);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        exit(1);
    }

    while ((n = recv(sockfd, request, sizeof request, 0)) > 0) {
        write(1, request, n);
    }

    if (n < 0) {
        perror("recv");
        exit(1);
    }

    close(sockfd);

    return 0;
}