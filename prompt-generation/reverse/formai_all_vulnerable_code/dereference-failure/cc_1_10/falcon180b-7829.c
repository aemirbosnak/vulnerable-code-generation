//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    char *host, *user, *pass, *buf;
    struct addrinfo hints, *res;
    int status;

    if (argc < 4) {
        printf("Usage: %s host user pass\n", argv[0]);
        return 1;
    }

    host = argv[1];
    user = argv[2];
    pass = argv[3];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(host, "110", &hints, &res);
    if (status!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    status = connect(sockfd, res->ai_addr, res->ai_addrlen);
    if (status == -1) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    buf = malloc(BUFSIZE);
    if (buf == NULL) {
        perror("malloc");
        close(sockfd);
        return 1;
    }

    snprintf(buf, BUFSIZE, "USER %s\r\n", user);
    send(sockfd, buf, strlen(buf), 0);

    snprintf(buf, BUFSIZE, "PASS %s\r\n", pass);
    send(sockfd, buf, strlen(buf), 0);

    free(buf);
    close(sockfd);

    return 0;
}