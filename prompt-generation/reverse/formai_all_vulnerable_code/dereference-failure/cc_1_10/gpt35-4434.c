//FormAI DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_PORTS 65535  // maximum number of ports to scan

// function to check if a port is open
int is_port_open(const char *ip, int port) {
    struct sockaddr_in address;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 0;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip);
    address.sin_port = htons(port);
    int result = connect(sock, (struct sockaddr *)&address, sizeof(address));
    if (result != -1) {
        close(sock);
        return 1;
    }
    return 0;
}

// function to scan a range of ports
void scan_ports(const char *ip, int start_port, int end_port) {
    for (int port = start_port; port <= end_port; port++) {
        if (is_port_open(ip, port)) {
            printf("%d: open\n", port);
        } else {
            printf("%d: closed\n", port);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 4) {
        printf("usage: %s <ip_address> [start_port end_port]\n", argv[0]);
        return 1;
    }
    char *ip = argv[1];
    int start_port = 1;
    int end_port = MAX_PORTS;
    if (argc == 4) {
        start_port = atoi(argv[2]);
        end_port = atoi(argv[3]);
        if (start_port < 1 || end_port > MAX_PORTS || start_port > end_port) {
            printf("invalid port range\n");
            return 1;
        }
    }
    printf("Scanning ports %d-%d on %s...\n", start_port, end_port, ip);
    scan_ports(ip, start_port, end_port);
    return 0;
}