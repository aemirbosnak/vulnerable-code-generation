//Falcon-180B DATASET v1.0 Category: Networking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo *servinfo;
    struct sockaddr *servaddr;
    char buffer[BUFFER_SIZE];
    int nbytes;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    if ((servinfo = getaddrinfo(argv[1], argv[2], NULL, NULL)) == NULL) {
        fprintf(stderr, "getaddrinfo(): %s\n", gai_strerror(errno));
        exit(1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket(): %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sockfd, servaddr = servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        fprintf(stderr, "connect(): %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        nbytes = read(sockfd, buffer, BUFFER_SIZE);
        if (nbytes == 0) {
            fprintf(stdout, "Connection closed by server\n");
            break;
        }
        buffer[nbytes] = '\0';
        printf("Received message: %s", buffer);
    }

    close(sockfd);
    return 0;
}