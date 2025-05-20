//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

// Define the maximum number of ports to scan
#define MAX_PORTS 100

// Define the timeout value for each port scan
#define TIMEOUT_VALUE 1

// Define the banner to print before scanning
#define BANNER "Scanning ports..."

// Define the error message to print if a port is closed
#define CLOSED_MESSAGE "Port %d is closed."

// Define the error message to print if a port is open
#define OPEN_MESSAGE "Port %d is open."

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided an IP address
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    // Get the IP address from the command line
    char *ip_address = argv[1];

    // Create a socket for scanning ports
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Set the timeout value for the socket
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_VALUE;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        return 1;
    }

    // Convert the IP address to a binary format
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    if (inet_pton(AF_INET, ip_address, &addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Print the banner
    printf("%s\n\n", BANNER);

    // Scan the ports
    for (int port = 1; port <= MAX_PORTS; port++) {
        // Set the port number in the socket address
        addr.sin_port = htons(port);

        // Connect to the port
        int result = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));

        // Check if the port is open
        if (result == 0) {
            // Print the open message
            printf(OPEN_MESSAGE, port);
        } else {
            // Check if the error is due to a timeout
            if (errno == ETIMEDOUT) {
                // Print the closed message
                printf(CLOSED_MESSAGE, port);
            } else {
                // Print the error message
                perror("connect");
                return 1;
            }
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}