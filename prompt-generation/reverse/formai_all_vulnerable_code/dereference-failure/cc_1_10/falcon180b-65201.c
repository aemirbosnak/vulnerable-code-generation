//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 65535

void scan_ports(int sock, struct sockaddr_in target) {
    int port = 1;
    while (port <= MAX) {
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is open\n", port);
            close(sock);
        } else {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed\n", port);
            } else {
                printf("Error connecting to port %d: %s\n", port, strerror(errno));
            }
        }
        port++;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    char *port_range = argv[2];

    struct sockaddr_in target;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    target.sin_family = AF_INET;
    target.sin_port = htons(atoi(port_range));
    target.sin_addr.s_addr = inet_addr(ip);

    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == -1) {
        printf("Error connecting to %s:%s: %s\n", ip, port_range, strerror(errno));
        close(sock);
        return 1;
    }

    printf("Scanning ports on %s...\n", ip);
    scan_ports(sock, target);

    close(sock);
    return 0;
}