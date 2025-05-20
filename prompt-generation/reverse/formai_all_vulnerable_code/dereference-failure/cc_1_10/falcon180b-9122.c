//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

bool is_valid_port(int port) {
    if (port < 1 || port > MAX_PORTS) {
        return false;
    }
    return true;
}

void scan_ports(int start_port, int end_port, char *ip_address) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    for (int i = start_port; i <= end_port; i++) {
        if (!is_valid_port(i)) {
            continue;
        }

        server_addr.sin_port = htons(i);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open.\n", i);
        } else {
            printf("Port %d is closed.\n", i);
        }
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <start_port> <end_port> <ip_address>\n", argv[0]);
        exit(1);
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);
    char *ip_address = argv[3];

    scan_ports(start_port, end_port, ip_address);

    return 0;
}