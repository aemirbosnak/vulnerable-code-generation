//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#define PORT 8080

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server_address>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int sockfd = socket(hints.ai_family, hints.ai_socktype, hints.ai_protocol);
    if (sockfd < 0) {
        error("Failed to create socket");
    }

    if (getaddrinfo(argv[1], NULL, &hints, &servinfo)!= 0) {
        error("getaddrinfo failed");
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) < 0) {
            freeaddrinfo(servinfo);
            error("Failed to connect");
        }

        break;
    }

    freeaddrinfo(servinfo);

    char buffer[1024];
    int n;
    while ((n = recv(sockfd, buffer, sizeof buffer, 0)) > 0) {
        printf("Received: %s\n", buffer);
        send(sockfd, buffer, n, 0);
    }

    close(sockfd);
    return 0;
}