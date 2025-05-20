//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535

int scan_port(int sock, int port) {
    struct sockaddr_in server;
    int opt = 1;
    int result;

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(port);

    result = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));
    if (result < 0) {
        printf("setsockopt() failed: %s\n", strerror(errno));
        exit(1);
    }

    result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (result < 0) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("connect() failed: %s\n", strerror(errno));
        }
    } else {
        printf("Port %d is open\n", port);
        close(sock);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int sock, result;
    int start_port, end_port;

    if (argc!= 4) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    start_port = atoi(argv[1]);
    end_port = atoi(argv[2]);

    if (start_port > end_port || start_port < 1 || end_port > MAX_PORTS) {
        printf("Invalid port range\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("socket() failed: %s\n", strerror(errno));
        exit(1);
    }

    for (int i = start_port; i <= end_port; i++) {
        scan_port(sock, i);
    }

    close(sock);
    return 0;
}