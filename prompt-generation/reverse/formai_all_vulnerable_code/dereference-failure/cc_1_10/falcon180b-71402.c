//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error_handling(char *message);

int main(void) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[NI_MAXSERV];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("localhost", "8080", &hints, &servinfo))!= 0) {
        error_handling("getaddrinfo");
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            error_handling("socket");
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            error_handling("connect");
        }

        break;
    }

    if (p == NULL) {
        error_handling("connect");
    }

    freeaddrinfo(servinfo);

    send(sockfd, "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n"), 0);

    while ((rv = recv(sockfd, s, sizeof s, 0)) > 0) {
        s[rv] = '\0';
        printf("%s", s);
    }

    close(sockfd);

    return 0;
}

void error_handling(char *message) {
    fprintf(stderr, "Socket Error: %s\n", message);
    exit(1);
}