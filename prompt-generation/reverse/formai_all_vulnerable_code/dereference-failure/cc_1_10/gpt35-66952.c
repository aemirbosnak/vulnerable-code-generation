//FormAI DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define TIMEOUT 3

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *hostname = argv[1];
    struct addrinfo hints, *res, *p;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &res) != 0) {
        fprintf(stderr, "Failed to get IP address of %s.\n", hostname);
        exit(EXIT_FAILURE);
    }

    char ipstr[INET6_ADDRSTRLEN];
    
    for (p = res; p != NULL; p = p->ai_next) {
        void *addr;

        if (p->ai_family == AF_INET) {
            struct sockaddr_in *ipv4 = (struct sockaddr_in*)p->ai_addr;
            addr = &(ipv4->sin_addr);
        } else {
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6*)p->ai_addr;
            addr = &(ipv6->sin6_addr);
        }

        inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));

        printf("Scanning ports on %s...\n", ipstr);

        for (int port = 1; port < 65536; port++) {
            int sockfd = socket(p->ai_family, SOCK_STREAM, 0);
            if (sockfd < 0) {
                fprintf(stderr, "Failed to create socket.\n");
                exit(EXIT_FAILURE);
            }
            
            struct timeval tv;
            tv.tv_sec = TIMEOUT;
            tv.tv_usec = 0;
            
            if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
                fprintf(stderr, "Failed to set socket timeout.\n");
                exit(EXIT_FAILURE);
            }

            struct sockaddr_storage dest_addr;
            memset(&dest_addr, 0, sizeof dest_addr);

            if (p->ai_family == AF_INET) {
                ((struct sockaddr_in*)&dest_addr)->sin_family = AF_INET;
                ((struct sockaddr_in*)&dest_addr)->sin_port = htons(port);
                inet_pton(AF_INET, ipstr, &((struct sockaddr_in*)&dest_addr)->sin_addr);
            } else {
                ((struct sockaddr_in6*)&dest_addr)->sin6_family = AF_INET6;
                ((struct sockaddr_in6*)&dest_addr)->sin6_port = htons(port);
                inet_pton(AF_INET6, ipstr, &((struct sockaddr_in6*)&dest_addr)->sin6_addr);
            }

            if (connect(sockfd, (struct sockaddr*)&dest_addr, sizeof(dest_addr)) == 0) {
                printf("Port %d is open.\n", port);
                close(sockfd);
            }
        }
    }
    
    freeaddrinfo(res);
    
    return EXIT_SUCCESS;
}