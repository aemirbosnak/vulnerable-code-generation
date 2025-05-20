//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: high level of detail
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main() {
    struct addrinfo hints, *servinfo, *p;
    int sockfd;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo("www.google.com", NULL, &hints, &servinfo)!= 0) {
        fprintf(stderr, "getaddrinfo() failed\n");
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to create socket\n");
        return 1;
    }

    if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
        fprintf(stderr, "connect() failed\n");
        return 1;
    }

    char buffer[256] = {0};
    if (send(sockfd, "GET / HTTP/1.1\r\nHost: google.com\r\n\r\n",
               strlen("GET / HTTP/1.1\r\nHost: google.com\r\n\r\n"),
               0) == -1) {
        fprintf(stderr, "send() failed\n");
        return 1;
    }

    int n;
    while ((n = recv(sockfd, buffer, 256, 0)) > 0) {
        printf("%s", buffer);
    }

    if (n == -1) {
        fprintf(stderr, "recv() failed\n");
        return 1;
    }

    close(sockfd);
    return 0;
}