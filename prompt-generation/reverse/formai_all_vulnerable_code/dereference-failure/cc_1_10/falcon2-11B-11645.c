//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 256

int main() {
    struct hostent *server;
    struct sockaddr_in servaddr;
    int sockfd, portno, n, status;
    char *hostname = "google.com";
    char line[MAX_LINE], *ipaddr, *port;
    struct addrinfo hints, *ai, *p;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(hostname, NULL, &hints, &ai);
    if (status!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    for (p = ai; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        port = inet_ntop(p->ai_family, &(((struct sockaddr_in *)p->ai_addr)->sin_addr), line, MAX_LINE);
        printf("Connected to %s on port %s\n", hostname, port);

        freeaddrinfo(ai);
        close(sockfd);
        break;
    }

    return 0;
}