//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Define the maximum number of ports to scan
#define MAX_PORTS 100

// Define the timeout for each port scan
#define TIMEOUT 1

// Function to scan a single port
int scan_port(char *ip, int port) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Set the socket timeout
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        return -1;
    }

    // Create the address to connect to
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    // Connect to the address
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        return 0;
    }

    // Close the socket
    close(sockfd);

    // Return 1 if the port is open, 0 otherwise
    return 1;
}

// Function to scan a range of ports
void scan_ports(char *ip, int start_port, int end_port) {
    // Iterate over the range of ports
    for (int port = start_port; port <= end_port; port++) {
        // Scan the port
        int is_open = scan_port(ip, port);

        // Print the port and whether it is open
        if (is_open) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <ip> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    // Get the IP address
    char *ip = argv[1];

    // Get the start and end ports
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Scan the range of ports
    scan_ports(ip, start_port, end_port);

    // Return 0 to indicate success
    return 0;
}