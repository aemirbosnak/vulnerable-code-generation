//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: mathematical
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Could not resolve hostname '%s'\n", hostname);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0); // Ephemeral port
    addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }

    int port = ntohs(addr.sin_port);
    printf("Ephemeral port: %d\n", port);

    for (int i = 0; i < MAX_PORTS; i++) {
        if (i == port) {
            continue;
        }

        addr.sin_port = htons(i);

        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", i);
        }
    }

    close(sockfd);

    return 0;
}