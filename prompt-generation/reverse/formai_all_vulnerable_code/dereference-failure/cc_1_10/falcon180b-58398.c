//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo;
    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    int port = 21;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &servinfo)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        exit(1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype,
                    servinfo->ai_protocol);

    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to %s\n", hostname);

    char *username_password = malloc(strlen(username) + strlen(password) + 3);
    sprintf(username_password, "%s:%s", username, password);

    send(sockfd, username_password, strlen(username_password), 0);

    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);

    while ((recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("Received: %s", buffer);
        bzero(buffer, BUFFER_SIZE);
    }

    close(sockfd);

    return 0;
}