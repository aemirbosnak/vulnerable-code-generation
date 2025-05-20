//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[NI_MAXSERV];
    int rv;
    int numbytes;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("www.example.com", "http", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    char request[100] = "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: close\r\n\r\n";

    if (send(sockfd, request, strlen(request), 0)!= strlen(request)) {
        perror("send");
        exit(1);
    }

    char buffer[4096];

    while ((numbytes = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[numbytes] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}