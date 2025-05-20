//Falcon2-11B DATASET v1.0 Category: Networking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server-address> <url>\n", argv[0]);
        exit(1);
    }

    struct addrinfo hints, *servinfo, *p;
    int rv;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(argv[1], "http", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        int sockfd;
        struct sockaddr_in server;

        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        printf("Connected to %s\n", argv[1]);

        char request[256];
        sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", argv[2], argv[1]);

        send(sockfd, request, strlen(request), 0);

        char response[4096];
        int n;
        if ((n = recv(sockfd, response, sizeof response, 0)) == -1) {
            perror("recv");
            close(sockfd);
            continue;
        }

        printf("%s\n", response);
        close(sockfd);
        break;
    }

    freeaddrinfo(servinfo);
    return 0;
}