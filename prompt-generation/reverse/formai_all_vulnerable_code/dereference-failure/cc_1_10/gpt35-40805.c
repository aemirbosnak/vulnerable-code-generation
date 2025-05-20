//FormAI DATASET v1.0 Category: Network Ping Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define TIMEOUT_SEC 2
#define MAX_RETRY 3

void displayError(const char *errorMsg) {
    fprintf(stderr, "Error: %s. %s\n", errorMsg, strerror(errno));
    exit(1);
}

bool ping(char *ipAddr) {
    int sockfd;
    struct sockaddr_in addr;
    struct timeval timeout;
    char buffer[BUFFER_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0)
        displayError("Failed to create socket");

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ipAddr);

    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout,
                   sizeof(timeout)) == -1)
        displayError("Failed to set socket options");

    for (int i = 0; i < MAX_RETRY; i++) {
        if (sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *) &addr,
                   sizeof(addr)) < 0) {
            fprintf(stderr, "Failed to send packet to %s. %s\n", ipAddr, strerror(errno));
            continue;
        }

        n = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
        if (n == -1) {
            fprintf(stderr, "No response from %s. %s\n", ipAddr, strerror(errno));
            continue;
        }

        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        exit(1);
    }

    if (ping(argv[1]))
        printf("Host %s is alive!\n", argv[1]);
    else
        printf("Host %s is unreachable!\n", argv[1]);

    return 0;
}