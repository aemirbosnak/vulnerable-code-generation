//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    struct addrinfo hints, *servinfo, *p;
    int status, sockfd;
    char buf[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    status = getaddrinfo("google.com", "80", &hints, &servinfo);

    if (status!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        if (send(sockfd, "GET / HTTP/1.0\r\n\r\n", 46, 0)!= 46) {
            perror("send");
            close(sockfd);
            continue;
        }

        if (recv(sockfd, buf, INET6_ADDRSTRLEN, 0) == 0) {
            perror("recv");
            close(sockfd);
            continue;
        }

        printf("%s\n", buf);
        close(sockfd);
        break;
    }

    freeaddrinfo(servinfo);

    return 0;
}