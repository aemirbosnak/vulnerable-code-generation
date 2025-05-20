//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_MSG_LEN 1024

int main(int argc, char *argv[]) {
    struct addrinfo hints, *servinfo, *p;
    int sockfd, portno, n, err;
    char recv_buf[MAX_MSG_LEN];
    char message[] = "Hello, world!\n";

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((err = getaddrinfo(argv[1], "25", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
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

    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("client: send");
        close(sockfd);
        return 1;
    }

    if ((n = recv(sockfd, recv_buf, MAX_MSG_LEN, 0)) == -1) {
        perror("client: recv");
        close(sockfd);
        return 1;
    }

    recv_buf[n] = '\0';
    printf("Received: %s\n", recv_buf);

    close(sockfd);
    return 0;
}