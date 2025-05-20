//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int scan_ports(int sock, int target_ip, int start_port, int end_port);

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <target_ip> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    int target_ip = inet_addr(argv[1]);
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (target_ip == INADDR_NONE) {
        fprintf(stderr, "Invalid target IP address.\n");
        return 1;
    }

    if (start_port > end_port) {
        fprintf(stderr, "Start port cannot be greater than end port.\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    scan_ports(sock, target_ip, start_port, end_port);

    close(sock);
    return 0;
}

int scan_ports(int sock, int target_ip, int start_port, int end_port) {
    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(start_port);
    target_addr.sin_addr.s_addr = target_ip;

    for (int i = start_port; i <= end_port; i++) {
        if (connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            char buffer[BUFFER_SIZE];
            snprintf(buffer, BUFFER_SIZE, "Port %d is open.\n", i);
            write(sock, buffer, strlen(buffer));
        } else {
            char buffer[BUFFER_SIZE];
            snprintf(buffer, BUFFER_SIZE, "Port %d is closed.\n", i);
            write(sock, buffer, strlen(buffer));
        }
    }

    return 0;
}