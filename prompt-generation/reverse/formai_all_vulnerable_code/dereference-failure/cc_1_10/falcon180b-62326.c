//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_ports(int sock, int target_ip, int start_port, int end_port) {
    int port;
    char buffer[BUFFER_SIZE];

    for (port = start_port; port <= end_port; port++) {
        if (connect(sock, (struct sockaddr *)&target_ip, sizeof(target_ip))!= -1) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in target_addr;
    int target_ip;
    int start_port, end_port;

    if (argc!= 4) {
        printf("Usage:./port_scanner <target_ip> <start_port> <end_port>\n");
        exit(1);
    }

    target_ip = inet_addr(argv[1]);
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = target_ip;
    target_addr.sin_port = htons(start_port);

    if (connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) == -1) {
        printf("Error connecting to target\n");
        exit(1);
    }

    scan_ports(sock, target_ip, start_port, end_port);

    close(sock);

    return 0;
}