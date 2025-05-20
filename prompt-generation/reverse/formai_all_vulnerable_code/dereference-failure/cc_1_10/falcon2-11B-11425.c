//Falcon2-11B DATASET v1.0 Category: Networking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc!= 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    struct addrinfo hints, *servinfo, *p;
    int sockfd, rv;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(argv[1], argv[2], &hints, &servinfo)!= 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to create socket\n");
        exit(1);
    }

    if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
        close(sockfd);
        sockfd = -1;
        fprintf(stderr, "Failed to connect socket\n");
        exit(1);
    }

    while (1) {
        char buffer[1024];
        ssize_t n = recv(sockfd, buffer, sizeof buffer, 0);
        if (n == -1) {
            perror("recv");
            exit(1);
        }
        if (n == 0) {
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    exit(0);
}