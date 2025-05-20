//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_port(int sock, int port) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in target;
    int addrlen = sizeof(target);

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &target.sin_addr);

    if (connect(sock, (struct sockaddr *)&target, addrlen) == 0) {
        printf("Port %d is open.\n", port);
    } else {
        printf("Port %d is closed.\n", port);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to %s: %s\n", argv[1], strerror(errno));
        close(sock);
        return 1;
    }

    printf("Scanning ports on %s...\n", argv[1]);

    for (int i = 1; i <= MAX_PORTS; i++) {
        scan_port(sock, i);
    }

    close(sock);
    return 0;
}