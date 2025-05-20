//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_LINE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage: %s <host> <port> <message>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *port = argv[2];
    char *message = argv[3];

    int sockfd, newsockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    int opt = 1;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(host, port, &hints, &servinfo))!= 0) {
        error("getaddrinfo");
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            error("socket");
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
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

    send(sockfd, message, strlen(message), 0);

    while (1) {
        char buffer[MAX_LINE];
        memset(buffer, 0, MAX_LINE);
        int bytes_received = recv(sockfd, buffer, MAX_LINE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Received: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}