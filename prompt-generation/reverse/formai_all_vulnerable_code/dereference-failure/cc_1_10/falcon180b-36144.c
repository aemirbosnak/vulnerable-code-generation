//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define HOST_NAME "localhost"
#define PORT_NUMBER "80"

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo *addrinfo;
    int status;
    char buffer[BUF_SIZE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    if ((status = getaddrinfo(argv[1], NULL, NULL, &addrinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(1);
    }

    sockfd = socket(addrinfo->ai_family, addrinfo->ai_socktype, addrinfo->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sockfd, addrinfo->ai_addr, addrinfo->ai_addrlen) == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    if (send(sockfd, "GET / HTTP/1.1\r\nHost: ", strlen("GET / HTTP/1.1\r\nHost: "), 0) == -1) {
        fprintf(stderr, "send: %s\n", strerror(errno));
        exit(1);
    }

    memset(buffer, 0, BUF_SIZE);
    if (recv(sockfd, buffer, BUF_SIZE, 0) == -1) {
        fprintf(stderr, "recv: %s\n", strerror(errno));
        exit(1);
    }

    printf("Response:\n%s", buffer);

    close(sockfd);
    freeaddrinfo(addrinfo);
    return 0;
}