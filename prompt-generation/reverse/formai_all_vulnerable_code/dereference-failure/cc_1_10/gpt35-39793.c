//FormAI DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_PORT 65535

void scan_port(char *ip, int port);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 0;
    }

    char *ip = argv[1];

    for (int i = 1; i<=MAX_PORT; i++) {
        scan_port(ip, i);
    }

    return 0;
}

void scan_port(char *ip, int port) {
    int sock, err;
    struct sockaddr_in addr;

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("failed to create socket");
        return;
    }

    // set socket to non-blocking mode
    int flags = fcntl(sock, F_GETFL, 0);
    if (flags < 0) {
        perror("failed to get socket flags");
        close(sock);
        return;
    }
    if (fcntl(sock, F_SETFL, flags | O_NONBLOCK) < 0) {
        perror("failed to set socket to non-blocking mode");
        close(sock);
        return;
    }

    // set address parameters
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);

    // connect to remote host
    err = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (err == -1 && errno != EINPROGRESS) {
        fprintf(stderr, "failed to connect to %s:%d\n", ip, port);
        close(sock);
        return;
    }

    // select timeout
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    fd_set waitset;
    FD_ZERO(&waitset);
    FD_SET(sock, &waitset);

    // wait for connection status
    err = select(sock + 1, NULL, &waitset, NULL, &timeout);
    if (err == -1) {
        perror("failed to select socket");
        close(sock);
        return;
    }
    if (err == 0) {
        close(sock);
        return;
    }

    // get socket error status
    int optlen = sizeof(err);
    if (getsockopt(sock, SOL_SOCKET, SO_ERROR, &err, &optlen) < 0) {
        perror("failed to get socket error status");
        close(sock);
        return;
    }

    // print open port number
    if (err == 0) {
        printf("port %d is open\n", port);
    }

    // close socket
    close(sock);
}