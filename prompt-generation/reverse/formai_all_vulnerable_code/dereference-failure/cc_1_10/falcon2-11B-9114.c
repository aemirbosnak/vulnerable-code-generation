//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define PORT 80
#define HOST "www.example.com"

int main(int argc, char *argv[])
{
    struct addrinfo hints, *servinfo, *p;
    int rv;
    int sockfd;
    int port;
    char port_buffer[5];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(HOST, PORT, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        if (send("GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n", 1, 0, sockfd) == -1) {
            perror("send");
            close(sockfd);
            continue;
        }

        if (recv(sockfd, port_buffer, 4, 0) == -1) {
            perror("recv");
            close(sockfd);
            continue;
        }

        port = atoi(port_buffer);

        printf("Port %d is %s\n", port, port_buffer);

        close(sockfd);
    }

    freeaddrinfo(servinfo);

    return 0;
}