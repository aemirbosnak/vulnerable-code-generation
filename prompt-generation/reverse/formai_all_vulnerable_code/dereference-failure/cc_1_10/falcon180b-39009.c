//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <ctype.h>

#define MAXLINE 1024
#define DELIM " "

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    char buffer[MAXLINE];
    struct addrinfo hints, *servinfo, *p;
    char s[INET6_ADDRSTRLEN];

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s hostname port username\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((n = getaddrinfo(argv[1], argv[2], &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(n));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen)!= -1) {
            break;
        }

        close(sockfd);
        perror("connect");
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    sprintf(buffer, "USER %s\r\n", argv[3]);
    write(sockfd, buffer, strlen(buffer));

    while ((n = read(sockfd, buffer, MAXLINE)) > 0) {
        buffer[n] = '\0';
        fprintf(stdout, "%s", buffer);
    }

    close(sockfd);
    exit(0);
}