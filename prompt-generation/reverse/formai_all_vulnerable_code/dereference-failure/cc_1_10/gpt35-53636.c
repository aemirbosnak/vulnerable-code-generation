//FormAI DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 2048

void scanports(const char *host, int startport, int endport);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <host> <startport> <endport>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    int startport = atoi(argv[2]);
    int endport = atoi(argv[3]);

    scanports(host, startport, endport);

    return 0;
}

void scanports(const char *host, int startport, int endport) {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;

    printf("Scanning ports %d-%d on %s\n", startport, endport, host);

    // loop through all ports specified
    for (int port = startport; port <= endport; port++) {
        // create socket
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            printf("Error creating socket for port %d\n", port);
            continue;
        }

        // set serv_addr fields
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
            printf("Error setting IP address for port %d\n", port);
            close(sockfd);
            continue;
        }

        // connect to socket
        if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            // port closed
            printf("Port %d closed\n", port);
        } else {
            // port open
            printf("Port %d open\n", port);
        }

        // close socket
        close(sockfd);
    }
}