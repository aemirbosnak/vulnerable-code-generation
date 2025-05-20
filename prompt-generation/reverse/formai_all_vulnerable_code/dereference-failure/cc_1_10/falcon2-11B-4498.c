//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MESSAGE_SIZE 1000

int main(int argc, char *argv[]) {
    struct addrinfo hints, *servinfo, *p;
    int sockfd, rv;
    struct sockaddr_in serveraddr;
    char buffer[MAX_MESSAGE_SIZE];
    char message[] = "Hello, SMTP server!";

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(argv[1], "25", &hints, &servinfo))!= 0) {
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

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to server\n");
        return 1;
    }

    memset(buffer, 0, sizeof(buffer));

    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        close(sockfd);
        return 1;
    }

    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        close(sockfd);
        return 1;
    }

    printf("Received message: %s\n", buffer);

    freeaddrinfo(servinfo);
    close(sockfd);
    return 0;
}