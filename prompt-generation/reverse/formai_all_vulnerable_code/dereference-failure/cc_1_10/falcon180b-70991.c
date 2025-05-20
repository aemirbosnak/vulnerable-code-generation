//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <IP address> <port number> <protocol>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);
    char *protocol = argv[3];

    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    if ((rv = getaddrinfo(ip_address, NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if (p->ai_family == AF_INET) {
            inet_ntop(AF_INET, &((struct sockaddr_in *)p->ai_addr)->sin_addr, s, sizeof(s));
        } else if (p->ai_family == AF_INET6) {
            inet_ntop(AF_INET6, &((struct sockaddr_in6 *)p->ai_addr)->sin6_addr, s, sizeof(s));
        }

        printf("Sending message to %s:%d using %s...\n", s, port_number, protocol);

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

        char buffer[BUFFER_SIZE];
        snprintf(buffer, BUFFER_SIZE, "QoS Test Message");

        if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
            perror("send");
            close(sockfd);
            continue;
        }

        close(sockfd);
    }

    freeaddrinfo(servinfo);
    return 0;
}