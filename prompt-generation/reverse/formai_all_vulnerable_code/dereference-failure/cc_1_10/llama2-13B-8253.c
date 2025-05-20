//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024  // range of ports to scan
#define IP_ADDRESS "192.168.1.100" // IP address to scan

// Structure to store port and IP address information
typedef struct {
    int port;
    char ip[16];
} port_info_t;

// Function to scan for open ports on a given IP address
void scan_ports(port_info_t *ports, int num_ports, const char *ip_address) {
    struct sockaddr_in server_addr;
    socklen_t len = sizeof(server_addr);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    int i = 0;

    // Initialize server address with IP address and port range
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(0);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    // Loop through port range and perform connect() operation
    for (i = 0; i < num_ports; i++) {
        server_addr.sin_port = htons(i + 1);
        if (connect(sock, (struct sockaddr *)&server_addr, len) == 0) {
            // Port is open, store IP address and port number in structure
            ports[i].port = ntohs(server_addr.sin_port);
            strcpy(ports[i].ip, ip_address);
        }
    }

    // Close socket
    close(sock);
}

int main(int argc, char *argv[]) {
    // Check if user provided IP address and port range
    if (argc != 3) {
        printf("Usage: %s <IP_ADDRESS> <PORT_RANGE>\n", argv[0]);
        return 1;
    }

    // Initialize port information structure
    port_info_t *ports = (port_info_t *)malloc(sizeof(port_info_t) * PORT_RANGE);

    // Scan for open ports on IP address
    scan_ports(ports, PORT_RANGE, IP_ADDRESS);

    // Print open ports and their IP addresses
    for (int i = 0; i < PORT_RANGE; i++) {
        printf("%d %s\n", ports[i].port, ports[i].ip);
    }

    // Free memory
    free(ports);

    return 0;
}