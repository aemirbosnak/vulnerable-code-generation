//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define PORT 80

int main() {
    struct addrinfo hints, *servinfo, *p;
    int rv, s, ret;
    char buffer[MAX_LINE];
    char *url = "https://www.google.com";

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(url, NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((s = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(s, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(s);
            continue;
        }

        printf("Connected to %s\n", p->ai_canonname);
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to %s\n", url);
        return 1;
    }

    if ((ret = send(s, "GET / HTTP/1.1\r\n\r\n", 50, 0)) == -1) {
        perror("send");
        close(s);
        return 1;
    }

    if ((ret = recv(s, buffer, MAX_LINE, 0)) == -1) {
        perror("recv");
        close(s);
        return 1;
    }

    printf("Response: %s\n", buffer);

    close(s);
    freeaddrinfo(servinfo);

    return 0;
}