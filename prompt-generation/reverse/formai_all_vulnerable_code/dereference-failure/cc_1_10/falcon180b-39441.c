//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define BUF_SIZE 1024
#define PORT "80"

void die(const char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(ip, PORT, &hints, &res)!= 0) {
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

    char buf[BUF_SIZE];
    snprintf(buf, BUF_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: Close\r\n\r\n", ip);

    send(sock, buf, strlen(buf), 0);

    char response[BUF_SIZE];
    memset(response, 0, BUF_SIZE);

    int bytes_received = recv(sock, response, BUF_SIZE, 0);

    if (bytes_received <= 0) {
        die("recv");
    }

    printf("Response:\n%s\n", response);

    close(sock);
    freeaddrinfo(res);

    return 0;
}