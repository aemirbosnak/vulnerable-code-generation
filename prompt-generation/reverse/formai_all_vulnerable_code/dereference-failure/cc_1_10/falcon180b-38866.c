//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[NI_MAXSERV];
    char h[NI_MAXHOST];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("www.example.com", "80", &hints, &servinfo))!= 0) {
        error("getaddrinfo");
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            error("socket");
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen)!= -1) {
            break;
        }

        close(sockfd);
    }

    if (p == NULL) {
        error("connect");
    }

    if (getnameinfo(p->ai_addr, p->ai_addrlen, h, sizeof(h), s, sizeof(s), 0) == -1) {
        error("getnameinfo");
    }

    printf("Connected to %s:%s\n", h, s);

    char request[1024] = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    send(sockfd, request, strlen(request), 0);

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);

    if (bytes_received <= 0) {
        error("recv");
    }

    printf("Received: %s\n", buffer);

    close(sockfd);

    return 0;
}