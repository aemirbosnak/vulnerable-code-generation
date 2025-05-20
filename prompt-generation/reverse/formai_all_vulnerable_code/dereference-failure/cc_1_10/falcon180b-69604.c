//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <poll.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    char *host;
    int port;
    int sockfd, ret, val;
    struct addrinfo hints, *res;
    char buf[BUF_SIZE];

    // Check for correct number of arguments
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        exit(1);
    }

    // Set up hints for getaddrinfo()
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get address info for host and port
    ret = getaddrinfo(argv[1], argv[2], &hints, &res);
    if (ret!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        exit(1);
    }

    // Create socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    // Set socket options
    ret = setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &val, sizeof(val));
    if (ret == -1) {
        fprintf(stderr, "setsockopt(SO_KEEPALIVE): %s\n", strerror(errno));
        exit(1);
    }
    ret = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    if (ret == -1) {
        fprintf(stderr, "setsockopt(SO_REUSEADDR): %s\n", strerror(errno));
        exit(1);
    }

    // Connect to server
    ret = connect(sockfd, res->ai_addr, res->ai_addrlen);
    if (ret == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    // Send data to server
    strcpy(buf, "Hello, world!");
    ret = send(sockfd, buf, strlen(buf), 0);
    if (ret == -1) {
        fprintf(stderr, "send: %s\n", strerror(errno));
        exit(1);
    }

    // Receive data from server
    ret = recv(sockfd, buf, BUF_SIZE, 0);
    if (ret == -1) {
        fprintf(stderr, "recv: %s\n", strerror(errno));
        exit(1);
    }
    buf[ret] = '\0';
    printf("Received: %s\n", buf);

    // Close socket
    ret = close(sockfd);
    if (ret == -1) {
        fprintf(stderr, "close: %s\n", strerror(errno));
        exit(1);
    }

    return 0;
}