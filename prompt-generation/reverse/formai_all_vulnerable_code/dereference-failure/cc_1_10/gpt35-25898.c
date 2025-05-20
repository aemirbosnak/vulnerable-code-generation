//FormAI DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to scan for open ports using a TCP connection
void scanPort(char *ip_address, int port_num) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;

    // Set up socket address
    address.sin_family = AF_INET;
    address.sin_port = htons(port_num);
    inet_pton(AF_INET, ip_address, &address.sin_addr);

    // Connect to port
    int conn_result = connect(sock, (struct sockaddr *)&address, sizeof(address));

    // Check if connection was successful
    if (conn_result == 0) {
        printf("Port %d: Open\n", port_num);
    } else {
        printf("Port %d: Closed\n", port_num);
    }

    // Clean up socket
    close(sock);
}

int main(int argc, char *argv[]) {
    int start_port, end_port;

    // Check if user provided correct number of arguments
    if (argc != 4) {
        printf("Usage: %s <ip address> <starting port> <ending port>\n", argv[0]);
        return 1;
    }

    // Parse IP address and starting & ending port numbers from command-line arguments
    char *ip_address = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    // Scan each port between the starting and ending ports inclusively
    for (int port_num = start_port; port_num <= end_port; port_num++) {
        scanPort(ip_address, port_num);
    }

    return 0;
}