//Falcon-180B DATASET v1.0 Category: Networking ; Style: rigorous
/* A simple TCP client program that connects to a remote server and sends a message */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_DATA_SIZE 1024

int main() {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[MAX_DATA_SIZE];
    int rv;
    char *message = "Hello, world!";

    /* Set up the hints structure */
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    /* Get the server address */
    if ((rv = getaddrinfo("localhost", "8080", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    /* Loop through all the results and connect to the first one */
    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    /* Send the message */
    send(sockfd, message, strlen(message), 0);

    /* Receive the response */
    memset(s, 0, MAX_DATA_SIZE);
    if (recv(sockfd, s, MAX_DATA_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    printf("Server response: %s\n", s);

    /* Close the socket */
    close(sockfd);

    return 0;
}