//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFSIZE 512

void error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int create_socket(char *hostname, char *portname) {
    
    struct addrinfo hints, *res, *p;
    int sockfd;
    int status;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(hostname, portname, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return -1;
    }

    for (p = res; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
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
        fprintf(stderr, "Could not connect to %s:%s\n", hostname, portname);
        sockfd = -1;
    }

    freeaddrinfo(res);

    return sockfd;
}

void send_commands(int sockfd) {
    char buffer[BUFSIZE];
    ssize_t n;

    n = snprintf(buffer, BUFSIZE, "commands\n");
    send(sockfd, buffer, n, 0);

    while ((n = recv(sockfd, buffer, BUFSIZE-1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    if (n == -1) {
        error("recv");
    }
}

int main(int argc, char *argv[]) {
    int sockfd;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = create_socket(argv[1], argv[2]);

    if (sockfd >= 0) {
        send_commands(sockfd);
        close(sockfd);
    }

    return 0;
}