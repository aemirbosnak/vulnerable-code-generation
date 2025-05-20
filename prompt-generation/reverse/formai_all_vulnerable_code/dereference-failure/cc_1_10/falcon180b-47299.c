//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/select.h>
#include <errno.h>
#include <unistd.h>

#define MAXLINE 1024
#define PORT 110

int main(int argc, char **argv) {
    int sockfd, nfds, retval;
    struct addrinfo hints, *servinfo, *p;
    char host[NI_MAXHOST];
    char port[NI_MAXSERV];
    int rv;
    fd_set readfds;

    printf("POP3 Client example\n");

    if (argc!= 3) {
        printf("Usage: %s <hostname> <username>\n", argv[0]);
        exit(1);
    }

    strcpy(host, argv[1]);
    strcpy(port, argv[2]);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(host, port, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    printf("Connecting to %s:%s\n", host, port);
    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    freeaddrinfo(servinfo);

    printf("Connected to server\n");

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        nfds = select(sockfd + 1, &readfds, NULL, NULL, NULL);

        if (nfds == -1) {
            perror("select");
            exit(1);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            char buf[MAXLINE];
            int n;

            n = read(sockfd, buf, MAXLINE);
            if (n == 0) {
                printf("Server closed connection\n");
                exit(0);
            } else if (n == -1) {
                perror("read");
                exit(1);
            }

            buf[n] = '\0';
            printf("Received: %s", buf);
        }
    }

    return 0;
}