//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/time.h>

void die(const char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int s = getaddrinfo(argv[1], NULL, &hints, &res);
    if (s!= 0) {
        die("getaddrinfo");
    }

    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock == -1) {
        die("socket");
    }

    if (connect(sock, res->ai_addr, res->ai_addrlen) == -1) {
        close(sock);
        die("connect");
    }

    char buf[1024];
    snprintf(buf, sizeof(buf), "PING %s\r\n", argv[1]);
    send(sock, buf, strlen(buf), 0);

    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv));
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv));

    char rbuf[1024];
    int len = recv(sock, rbuf, sizeof(rbuf), 0);
    if (len <= 0) {
        close(sock);
        die("recv");
    }

    close(sock);

    printf("Pinging %s...\n", argv[1]);
    printf("Received %d bytes of data:\n", len);
    printf("%s", rbuf);

    return 0;
}