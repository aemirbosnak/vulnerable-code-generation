//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_LINE 1024
#define PORT 21

void error(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[MAX_LINE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname filename\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((getaddrinfo(argv[1], PORT, &hints, &servinfo))!= 0) {
        error("getaddrinfo");
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        break;
    }

    if (sockfd == -1) {
        error("socket");
    }

    if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
        error("connect");
    }

    snprintf(s, MAX_LINE, "STOR %s\r\n", argv[2]);
    send(sockfd, s, strlen(s), 0);

    char buffer[MAX_LINE];
    while (1) {
        memset(buffer, 0, MAX_LINE);
        int bytes_received = recv(sockfd, buffer, MAX_LINE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}