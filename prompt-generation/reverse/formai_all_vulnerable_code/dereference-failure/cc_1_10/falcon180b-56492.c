//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

void print_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char hostname[NI_MAXHOST];
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(argv[1], NULL, &hints, &result)!= 0) {
        print_error("getaddrinfo");
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        print_error("socket");
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        print_error("connect");
    }

    freeaddrinfo(result);
    char send_buf[BUF_SIZE], recv_buf[BUF_SIZE];
    memset(send_buf, 'A', BUF_SIZE);
    memset(recv_buf, 0, BUF_SIZE);

    int sent = send(sockfd, send_buf, BUF_SIZE, 0);
    if (sent == -1) {
        print_error("send");
    }

    int recv_size = recv(sockfd, recv_buf, BUF_SIZE, 0);
    if (recv_size == -1) {
        print_error("recv");
    }

    close(sockfd);

    if (recv_size > 0 && strncmp(send_buf, recv_buf, BUF_SIZE) == 0) {
        printf("PING OK\n");
    } else {
        printf("PING FAIL\n");
    }

    return 0;
}