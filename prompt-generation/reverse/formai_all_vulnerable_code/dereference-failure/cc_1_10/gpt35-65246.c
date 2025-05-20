//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024
#define MAX_TIMEOUT 5

char* getIPAddress (struct sockaddr *address) {
    char *ipAddress = malloc(INET_ADDRSTRLEN);
    void *numericAddress;

    if (address->sa_family == AF_INET) {
        numericAddress = &((struct sockaddr_in *) address)->sin_addr;
    } else {
        numericAddress = &((struct sockaddr_in6 *) address)->sin6_addr;
    }

    return inet_ntop(address->sa_family, numericAddress, ipAddress, INET_ADDRSTRLEN) == NULL ? NULL : ipAddress;
}

void scanNetwork (char *networkAddress) {
    struct addrinfo hints, *res, *p;
    struct sockaddr_in *ipv4;
    struct sockaddr_in6 *ipv6;
    void *addr;
    char *ipAddress;
    int sockfd, r, i;
    char buffer[MAX_BUFFER];

    memset(&hints, 0, sizeof (hints));
    hints.ai_family = AF_UNSPEC; 
    hints.ai_socktype = SOCK_STREAM;

    if ((r = getaddrinfo(networkAddress, NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(r));
        return;
    }

    for (p = res; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket error");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            printf("Host: %s\tUnreachable\n", getIPAddress(p->ai_addr));
            continue;
        }

        if (p->ai_family == AF_INET) {
            ipv4 = (struct sockaddr_in *) p->ai_addr;
            addr = &(ipv4->sin_addr);
        } else {
            ipv6 = (struct sockaddr_in6 *) p->ai_addr;
            addr = &(ipv6->sin6_addr);
        }

        ipAddress = malloc(INET_ADDRSTRLEN);
        inet_ntop(p->ai_family, addr, ipAddress, INET_ADDRSTRLEN);
        printf("Host: %s\t", ipAddress);

        for (i = 0; i < MAX_TIMEOUT; i++) {
            if (send(sockfd, "PING", strlen("PING"), 0) == -1) {
                printf("Down\n");
                i = MAX_TIMEOUT;
            } else {
                if (recv(sockfd, buffer, MAX_BUFFER, 0) <= 0) {
                    printf("Up\n");
                } else {
                    printf("Running: %s", buffer);
                }

                memset(buffer, 0, MAX_BUFFER);
                sleep(1);
            }
        }

        close(sockfd);
    }

    freeaddrinfo(res);
}

int main (int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [network address]\n", argv[0]);
        return -1;
    }

    scanNetwork(argv[1]);

    return 0;
}