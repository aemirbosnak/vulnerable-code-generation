//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <target IP> <start port>\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int sockfd = socket(hints.ai_family, hints.ai_socktype, hints.ai_protocol);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    if (getaddrinfo(ip, "80", &hints, &servinfo)!= 0) {
        fprintf(stderr, "ERROR getting address info\n");
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        int val = 1;
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(int)) < 0) {
            perror("setsockopt");
            exit(1);
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) < 0) {
            perror("connect");
            continue;
        }

        printf("Port %d is open on %s\n", ntohs(p->ai_protocol), inet_ntoa(p->ai_addr));
    }

    freeaddrinfo(servinfo);
    close(sockfd);
    return 0;
}