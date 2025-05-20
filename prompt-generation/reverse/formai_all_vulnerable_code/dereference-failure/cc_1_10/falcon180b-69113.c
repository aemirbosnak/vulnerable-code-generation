//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    struct addrinfo *result, *ptr;
    int rc, sockfd;
    char buffer[BUFFER_SIZE];

    rc = getaddrinfo(hostname, NULL, NULL, &result);
    if (rc!= 0) {
        printf("getaddrinfo failed: %s\n", gai_strerror(rc));
        return 1;
    }

    sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        printf("socket failed: %s\n", strerror(errno));
        return 1;
    }

    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    while (result!= NULL) {
        memset(buffer, 0, BUFFER_SIZE);
        rc = sendto(sockfd, "PING", strlen("PING"), 0, result->ai_addr, result->ai_addrlen);
        if (rc == -1) {
            printf("sendto failed: %s\n", strerror(errno));
            close(sockfd);
            return 1;
        }

        rc = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (rc == -1) {
            printf("recv failed: %s\n", strerror(errno));
            close(sockfd);
            return 1;
        } else if (rc > 0) {
            printf("Received response from %s: %s\n", hostname, buffer);
        }

        result = result->ai_next;
    }

    close(sockfd);
    return 0;
}