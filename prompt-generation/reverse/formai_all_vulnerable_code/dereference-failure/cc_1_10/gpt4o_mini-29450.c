//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#define MAX_PORT 65535
#define MIN_PORT 1

void print_statistics(int scanned_ports, int open_ports, int closed_ports) {
    printf("\nStatistics:\n");
    printf("Total Ports Scanned: %d\n", scanned_ports);
    printf("Open Ports: %d\n", open_ports);
    printf("Closed Ports: %d\n", closed_ports);
}

int scan_port(const char *ip_address, int port) {
    int sock;
    struct sockaddr_in server;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Could not create socket: %s\n", strerror(errno));
        return -1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_address, &server.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address: %s\n", ip_address);
        close(sock);
        return -1;
    }

    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    close(sock);
    
    if (result < 0) {
        return 0; // Closed
    }
    return 1; // Open
}

void scan_ports(const char *ip_address, int start_port, int end_port) {
    int open_ports = 0;
    int closed_ports = 0;

    printf("Scanning ports %d to %d on %s...\n", start_port, end_port, ip_address);
    for (int port = start_port; port <= end_port; port++) {
        int status = scan_port(ip_address, port);
        if (status == 1) {
            printf("Port %d: OPEN\n", port);
            open_ports++;
        } else if (status == 0) {
            printf("Port %d: CLOSED\n", port);
            closed_ports++;
        }
    }
    
    print_statistics(start_port - end_port + 1, open_ports, closed_ports);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Port range must be between %d and %d, and start port must be less than or equal to end port.\n", MIN_PORT, MAX_PORT);
        exit(EXIT_FAILURE);
    }

    scan_ports(ip_address, start_port, end_port);
    return 0;
}