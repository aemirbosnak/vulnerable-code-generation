//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

typedef struct {
    char *host;
    int port;
    int timeout;
} target_t;

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <host> <port> [<timeout>]\n", argv[0]);
        return EXIT_FAILURE;
    }

    target_t target;
    target.host = argv[1];
    target.port = atoi(argv[2]);
    target.timeout = (argc > 3) ? atoi(argv[3]) : 10;

    struct hostent *host = gethostbyname(target.host);
    if (!host) {
        printf("Invalid hostname: %s\n", target.host);
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(target.port);
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }

    struct timeval timeout;
    timeout.tv_sec = target.timeout;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt() failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        printf("Connection failed: %s:%d\n", target.host, target.port);
        close(sockfd);
        return EXIT_FAILURE;
    }

    printf("Connection established: %s:%d\n", target.host, target.port);
    close(sockfd);

    return EXIT_SUCCESS;
}