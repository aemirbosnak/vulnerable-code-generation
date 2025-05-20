//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT_NUM 80
#define SCAN_TIMEOUT 5

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please specify an IP address or hostname to scan\n");
        exit(1);
    }

    char *target_host = argv[1];
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int ret = getaddrinfo(target_host, NULL, &hints, &result);
    if (ret != 0) {
        fprintf(stderr, "Error: getaddrinfo: %s\n", gai_strerror(ret));
        exit(1);
    }

    printf("Scanning for wireless networks on %s:\n", target_host);

    for (struct addrinfo *rp = result; rp != NULL; rp = rp->ai_next) {
        int sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        struct sockaddr_in *sin = (struct sockaddr_in *) rp->ai_addr;
        char *ip_addr = inet_ntoa(sin->sin_addr);

        printf("  * Scanning network %s...\n", ip_addr);

        struct timeval timeout;
        timeout.tv_sec = SCAN_TIMEOUT;
        timeout.tv_usec = 0;

        int optval = 1;
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) == -1) {
            perror("setsockopt");
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &timeout,
                       sizeof(timeout)) == -1) {
            perror("setsockopt");
        }

        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) == -1) {
            if (errno == ECONNREFUSED || errno == ETIMEDOUT) {
                // Network down or not reachable
                printf("    - Network %s is down or not reachable\n", ip_addr);
            } else {
                perror("connect");
            }
        } else {
            // Network up and reachable
            printf("    + Network %s is up and reachable\n", ip_addr);
        }

        close(sockfd);
    }

    freeaddrinfo(result);
    return 0;
}