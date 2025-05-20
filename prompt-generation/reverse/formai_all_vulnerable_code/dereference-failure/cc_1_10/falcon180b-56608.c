//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

void die(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(ip, NULL, &hints, &res)!= 0) {
        die("getaddrinfo");
    }

    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        die("socket");
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        die("connect");
    }

    char send_buf[BUF_SIZE];
    memset(send_buf, 0, BUF_SIZE);
    sprintf(send_buf, "GET / HTTP/1.1\r\nHost: %s:%d\r\nConnection: close\r\n\r\n", ip, port);

    if (send(sockfd, send_buf, strlen(send_buf), 0) == -1) {
        die("send");
    }

    char recv_buf[BUF_SIZE];
    memset(recv_buf, 0, BUF_SIZE);

    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, recv_buf, BUF_SIZE, 0)) > 0) {
        printf("%s", recv_buf);
        memset(recv_buf, 0, BUF_SIZE);
    }

    if (bytes_received == -1) {
        die("recv");
    }

    close(sockfd);

    return 0;
}