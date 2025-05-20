//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum number of ports to scan
#define MAX_PORTS 100

// Define the timeout for each port scan
#define TIMEOUT 1

// Define the function to scan a single port
int scan_port(char *ip_address, int port) {
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
        close(sockfd);
        return -1;
    }

    // Create the sockaddr_in structure
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip_address);

    // Connect to the port
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        close(sockfd);
        return 0;
    }

    // Close the socket
    close(sockfd);

    // Return 1 if the port is open, 0 otherwise
    return 1;
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments
    if (argc < 2) {
        printf("Usage: %s <ip address> [<port> ...]\n", argv[0]);
        return 1;
    }

    // Get the IP address
    char *ip_address = argv[1];

    // Get the ports to scan
    int ports[MAX_PORTS];
    int num_ports = 0;
    for (int i = 2; i < argc; i++) {
        int port = atoi(argv[i]);
        if (port < 0 || port > 65535) {
            printf("Invalid port: %d\n", port);
            return 1;
        }
        ports[num_ports++] = port;
    }

    // Scan the ports
    printf("Scanning ports %d-%d on %s\n", ports[0], ports[num_ports-1], ip_address);
    for (int i = 0; i < num_ports; i++) {
        int port = ports[i];
        int is_open = scan_port(ip_address, port);
        if (is_open) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    return 0;
}