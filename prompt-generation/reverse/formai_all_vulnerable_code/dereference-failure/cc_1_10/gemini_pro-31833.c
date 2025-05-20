//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 100

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;
    char *host;
    int port;
    int i;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port1> [port2] ... [portN]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    host = argv[1];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (i = 3; i < argc; i++) {
        port = atoi(argv[i]);
        if (port < 1 || port > 65535) {
            fprintf(stderr, "Invalid port number: %d\n", port);
            continue;
        }

        servaddr.sin_port = htons(port);

        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    close(sockfd);

    return 0;
}