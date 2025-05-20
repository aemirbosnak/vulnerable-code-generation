//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    struct addrinfo hints, *result = NULL;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
        die("getaddrinfo");
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        die("socket");
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        if (errno == ECONNREFUSED) {
            printf("The host %s is not responding.\n", hostname);
        } else if (errno == ETIMEDOUT) {
            printf("The host %s is not responding.\n", hostname);
        } else {
            die("connect");
        }

        close(sockfd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        die("recv");
    }

    close(sockfd);

    printf("The host %s is responding.\n", hostname);

    return 0;
}