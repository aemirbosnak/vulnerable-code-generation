//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    int sockfd, connfd;
    struct addrinfo hints, *servinfo, *p;
    char portstr[16];
    int rv;
    char *host;
    struct hostent *server;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    snprintf(portstr, sizeof(portstr), "%d", atoi(argv[2]));
    host = argv[1];

    rv = getaddrinfo(host, portstr, &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }

        connfd = connect(sockfd, p->ai_addr, p->ai_addrlen);
        if (connfd == -1) {
            close(sockfd);
            continue;
        }

        printf("Connected to %s:%s\n", p->ai_canonname, portstr);

        // Perform SMTP client operations here

        close(sockfd);
    }

    freeaddrinfo(servinfo);

    return 0;
}