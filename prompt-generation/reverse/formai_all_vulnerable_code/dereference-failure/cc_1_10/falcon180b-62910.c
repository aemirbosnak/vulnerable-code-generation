//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct addrinfo *ai;
    char *host;
    char *port;
    char *ptr;
    int ret;
    char buf[BUF_SIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = argv[2];

    ret = getaddrinfo(host, port, 0, &ai);
    if (ret!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        exit(1);
    }

    sock = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
    if (sock == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    ret = connect(sock, ai->ai_addr, ai->ai_addrlen);
    if (ret == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        memset(buf, 0, BUF_SIZE);
        ret = recv(sock, buf, BUF_SIZE, 0);
        if (ret <= 0) {
            fprintf(stderr, "recv: %s\n", strerror(errno));
            exit(1);
        }
        printf("Received %d bytes: %s\n", ret, buf);
        memset(buf, 0, BUF_SIZE);
        strcpy(buf, "PING");
        ret = send(sock, buf, strlen(buf), 0);
        if (ret!= strlen(buf)) {
            fprintf(stderr, "send: %s\n", strerror(errno));
            exit(1);
        }
    }

    close(sock);
    freeaddrinfo(ai);
    return 0;
}