//Falcon2-11B DATASET v1.0 Category: Networking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <string.h>
#include <strings.h>

#define PORT 8080

int main() {
    struct addrinfo hints, *servinfo, *p;
    int sockfd, rv;
    char send_buffer[1024], recv_buffer[1024];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(NULL, "localhost", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("client: connect");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        return 1;
    }

    memset(send_buffer, 0, sizeof send_buffer);
    strcpy(send_buffer, "Hello, server!\n");

    if (send(sockfd, send_buffer, strlen(send_buffer), 0) == -1) {
        perror("client: send");
        return 1;
    }

    memset(recv_buffer, 0, sizeof recv_buffer);
    if (recv(sockfd, recv_buffer, sizeof recv_buffer - 1, 0) == -1) {
        perror("client: recv");
        return 1;
    }

    recv_buffer[strlen(recv_buffer) - 1] = '\0';
    printf("Received: %s\n", recv_buffer);

    close(sockfd);

    freeaddrinfo(servinfo);

    return 0;
}