//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    struct addrinfo hints, *servinfo, *p;
    int rv;
    int sockfd;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(NULL, "localhost", &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1)
            error("socket");

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1)
            error("connect");

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    freeaddrinfo(servinfo);

    char buffer[1024];
    int n;

    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("Received %d bytes: %s\n", n, buffer);
    }

    close(sockfd);

    return 0;
}