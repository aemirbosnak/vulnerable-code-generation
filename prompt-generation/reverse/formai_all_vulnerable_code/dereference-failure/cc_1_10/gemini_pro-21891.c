//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024
#define TIMEOUT 3000 // milliseconds

struct timeval tv;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_CANONNAME;

    int err = getaddrinfo(argv[1], NULL, &hints, &res);
    if (err != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    char buf[BUFSIZE];
    int nbytes;

    gettimeofday(&tv, NULL);
    tv.tv_sec += TIMEOUT / 1000;
    tv.tv_usec += (TIMEOUT % 1000) * 1000;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    nbytes = send(sockfd, "ping", 4, 0);
    if (nbytes != 4) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    nbytes = recv(sockfd, buf, BUFSIZE, 0);
    if (nbytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    gettimeofday(&tv, NULL);
    int elapsed = (tv.tv_sec - tv.tv_sec) * 1000 + (tv.tv_usec - tv.tv_usec) / 1000;

    printf("Round trip time: %d ms\n", elapsed);

    close(sockfd);

    return EXIT_SUCCESS;
}