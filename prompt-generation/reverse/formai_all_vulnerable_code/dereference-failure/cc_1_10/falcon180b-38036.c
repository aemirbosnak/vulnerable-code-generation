//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct addrinfo hints, *servinfo, *p;
    char buffer[BUFFER_SIZE];
    const char *username = "username";
    const char *password = "password";
    const char *command = "STAT\r\n";

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo("localhost", "110", &hints, &servinfo)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        exit(1);
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

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Could not connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    if (send(sockfd, username, strlen(username), 0) == -1) {
        perror("send");
        close(sockfd);
        exit(1);
    }

    if (send(sockfd, password, strlen(password), 0) == -1) {
        perror("send");
        close(sockfd);
        exit(1);
    }

    while (1) {
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            break;
        }

        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}