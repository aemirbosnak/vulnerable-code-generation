//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PORT 65535

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *host = argv[1];

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo *result;
    int status = getaddrinfo(host, NULL, &hints, &result);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return EXIT_FAILURE;
    }

    struct sockaddr_in *addr = (struct sockaddr_in *)result->ai_addr;
    char *ip_address = inet_ntoa(addr->sin_addr);

    printf("Scanning host %s (%s)\n", host, ip_address);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        freeaddrinfo(result);
        return EXIT_FAILURE;
    }

    int port;
    for (port = 1; port <= MAX_PORT; port++) {
        addr->sin_port = htons(port);

        int status = connect(sockfd, (struct sockaddr *)addr, sizeof(*addr));
        if (status == 0) {
            printf("Port %d: open\n", port);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d: closed\n", port);
        } else {
            perror("connect");
            break;
        }
    }

    close(sockfd);
    freeaddrinfo(result);

    return EXIT_SUCCESS;
}