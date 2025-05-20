//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    struct addrinfo hints, *servinfo, *p;
    int status, sockfd, port;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(argv[1], "80", &hints, &servinfo);
    if (status!= 0) {
        fprintf(stderr, "Error: %s\n", gai_strerror(status));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd < 0) {
            continue;
        }

        port = p->ai_addrlen;
        if (connect(sockfd, p->ai_addr, port) < 0) {
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Error: Failed to connect to %s:%d\n", argv[1], "80");
        exit(1);
    }

    char request[1024] = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
    send(sockfd, request, strlen(request), 0);

    char response[1024] = "";
    while ((recv(sockfd, response, 1024, 0)) > 0) {
        printf("%s", response);
    }

    close(sockfd);
    return 0;
}