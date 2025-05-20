//FormAI DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

void port_scan(char* host, int start, int end) {
    struct sockaddr_in addr;
    int sock, res, port;

    printf("Starting port scan on %s\n", host);

    for (port = start; port <= end; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            printf("Failed to create socket: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(host);
        addr.sin_port = htons(port);

        res = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
        if (res < 0) {
            printf("%d closed\n", port);
        } else {
            printf("%d open\n", port);
            close(sock);
        }
    }

    printf("Scan complete\n");
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s [host] [start port] [end port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* host = argv[1];
    int start = atoi(argv[2]);
    int end = atoi(argv[3]);

    port_scan(host, start, end);

    return 0;
}