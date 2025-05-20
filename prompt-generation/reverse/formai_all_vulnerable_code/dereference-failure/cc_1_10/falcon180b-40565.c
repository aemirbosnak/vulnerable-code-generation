//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535

// Function to check if a port is open
int is_port_open(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("%d: Closed\n", port);
        } else {
            perror("connect");
        }
        close(sock);
        return 0;
    } else {
        printf("%d: Open\n", port);
        close(sock);
        return 1;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS;

    printf("Scanning %s:%d-%d...\n", ip, start_port, end_port - 1);

    for (int port = start_port; port <= end_port; port++) {
        is_port_open(port);
    }

    return 0;
}