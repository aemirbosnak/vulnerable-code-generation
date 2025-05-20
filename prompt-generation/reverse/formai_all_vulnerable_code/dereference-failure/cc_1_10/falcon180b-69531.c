//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_HOST_LEN 1024
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct addrinfo hints, *res;
    char host[MAX_HOST_LEN];
    char data[MAX_DATA_LEN];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s host data\n", argv[0]);
        return 1;
    }

    strcpy(host, argv[1]);
    strcpy(data, argv[2]);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    ret = getaddrinfo(host, NULL, &hints, &res);
    if (ret!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        return 1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        return 1;
    }

    ret = connect(sockfd, res->ai_addr, res->ai_addrlen);
    if (ret == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    ret = send(sockfd, data, strlen(data), 0);
    if (ret == -1) {
        fprintf(stderr, "send: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    char buf[MAX_DATA_LEN];
    ret = recv(sockfd, buf, MAX_DATA_LEN, 0);
    if (ret == -1) {
        fprintf(stderr, "recv: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    printf("Received response: %s\n", buf);

    close(sockfd);
    return 0;
}