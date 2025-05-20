//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <ip>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *servinfo, *p;
    int status, n;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(argv[1], PORT, &hints, &servinfo);
    if (status!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        int sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        status = connect(sockfd, p->ai_addr, p->ai_addrlen);
        if (status == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        char buffer[1024];
        int n;
        while ((n = recv(sockfd, buffer, sizeof buffer, 0)) > 0) {
            printf("Received: %s\n", buffer);
        }
    }

    freeaddrinfo(servinfo);
    return 0;
}