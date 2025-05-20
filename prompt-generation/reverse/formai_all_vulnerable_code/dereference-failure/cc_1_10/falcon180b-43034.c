//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct addrinfo hints, *res;
    char host[NI_MAXHOST];
    char service[NI_MAXSERV];
    int rv;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        return 1;
    }

    strncpy(host, argv[1], NI_MAXHOST-1);
    strncpy(service, argv[2], NI_MAXSERV-1);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(host, service, &hints, &res);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        return 1;
    }

    rv = connect(sockfd, res->ai_addr, res->ai_addrlen);
    if (rv == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        return 1;
    }

    char buffer[BUF_SIZE];
    memset(buffer, 0, BUF_SIZE);

    snprintf(buffer, BUF_SIZE-1, "USER %s\r\n", argv[1]);
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, BUF_SIZE-1, "PASS %s\r\n", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);

    char response[BUF_SIZE];
    memset(response, 0, BUF_SIZE);

    int bytes_received = recv(sockfd, response, BUF_SIZE-1, 0);
    response[bytes_received] = '\0';

    printf("Server response: %s\n", response);

    close(sockfd);

    return 0;
}