//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

void die(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((res = getaddrinfo(argv[1], NULL, &hints, NULL)) == NULL) {
        die("getaddrinfo");
    }

    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        die("socket");
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        die("connect");
    }

    char buf[BUF_SIZE];
    snprintf(buf, BUF_SIZE, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", argv[1]);
    send(sockfd, buf, strlen(buf), 0);

    char response[BUF_SIZE];
    memset(response, 0, BUF_SIZE);
    int bytes_received = recv(sockfd, response, BUF_SIZE, 0);
    response[bytes_received] = '\0';

    if (bytes_received <= 0) {
        die("recv");
    }

    printf("Response:\n%s\n", response);

    close(sockfd);
    freeaddrinfo(res);

    return 0;
}