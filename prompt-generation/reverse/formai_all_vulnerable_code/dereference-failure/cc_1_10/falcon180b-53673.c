//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535

void scan_ports(int sock, int target_ip, int start_port, int end_port) {
    int port;
    for (port = start_port; port <= end_port; port++) {
        int result = connect(sock, (struct sockaddr *)&target_ip, sizeof(target_ip));
        if (result == 0) {
            printf("Port %d is open!\n", port);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed.\n", port);
        } else {
            printf("Error connecting to port %d: %s\n", port, strerror(errno));
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <target_ip> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    int target_ip = inet_addr(argv[1]);
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (target_ip == INADDR_NONE) {
        printf("Invalid target IP address.\n");
        return 1;
    }

    if (start_port > end_port || start_port < 1 || end_port > MAX_PORTS) {
        printf("Invalid port range.\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    scan_ports(sock, target_ip, start_port, end_port);

    close(sock);
    return 0;
}