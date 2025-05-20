//FormAI DATASET v1.0 Category: Port Scanner ; Style: Donald Knuth
// This program is a unique C Port Scanner example program inspired by Donald Knuth's style of writing.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT_START 1
#define PORT_END 65535

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a hostname or IP address as a command-line argument.\n");
        exit(1);
    }

    char *hostname = argv[1];

    struct hostent *host = gethostbyname(hostname);

    if (!host) {
        printf("Invalid hostname or IP address.\n");
        exit(1);
    }

    printf("Scanning ports on %s (%s):\n", hostname, inet_ntoa(*(struct in_addr *) host->h_addr_list[0]));

    for (int port = PORT_START; port <= PORT_END; port++) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("socket");
            exit(1);
        }

        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        memcpy(&addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

        int result = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));

        if (result >= 0) {
            printf("%d: Open\n", port);
        }

        close(sockfd);
    }

    printf("Scan complete.\n");

    return 0;
}