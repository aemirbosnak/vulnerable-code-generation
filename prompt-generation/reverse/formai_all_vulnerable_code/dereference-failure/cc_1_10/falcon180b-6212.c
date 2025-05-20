//Falcon-180B DATASET v1.0 Category: Networking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[INET6_ADDRSTRLEN];
    int rv;
    int numbytes;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up address structure
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get address info
    if ((rv = getaddrinfo("localhost", "8080", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(EXIT_FAILURE);
    }

    // Connect to server
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
        exit(EXIT_FAILURE);
    }

    // Send data to server
    char *message = "Hello, world!";
    numbytes = send(sockfd, message, strlen(message), 0);
    if (numbytes == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive data from server
    char buffer[BUFFER_SIZE];
    numbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (numbytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("Received: %s\n", buffer);

    close(sockfd);

    return 0;
}