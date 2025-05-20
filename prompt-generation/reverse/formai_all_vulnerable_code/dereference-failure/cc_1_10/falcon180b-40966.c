//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 21
#define MAX_LINE 1000

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd, newsockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[MAX_LINE];
    int rv;
    int opt = 1;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("localhost", "ftp", &hints, &servinfo))!= 0) {
        error("getaddrinfo");
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            error("socket");
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
            error("setsockopt");
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        error("connect");
    }

    printf("Connected to ftp server\n");

    while (1) {
        memset(s, 0, MAX_LINE);
        fgets(s, MAX_LINE, stdin);

        if (send(sockfd, s, strlen(s), 0) == -1) {
            error("send");
        }

        memset(s, 0, MAX_LINE);
        if (recv(sockfd, s, MAX_LINE, 0) == -1) {
            error("recv");
        }

        printf("%s", s);
    }

    close(sockfd);
    return 0;
}