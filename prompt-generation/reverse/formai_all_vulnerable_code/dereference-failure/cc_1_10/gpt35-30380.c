//FormAI DATASET v1.0 Category: Port Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TIMEOUT 1

// Function to scan a range of ports on a given IP address
void scan_port(char *ip_address, int start_port, int end_port) {
    int sock, port;
    struct sockaddr_in target;

    // Loop through each port in the specified range
    for (port = start_port; port <= end_port; port++) {
        // Create a socket
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Could not create socket\n");
            exit(1);
        }

        // Set the timeout for the socket
        struct timeval timeout;
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;
        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));

        // Set up the target address and port
        target.sin_family = AF_INET;
        target.sin_addr.s_addr = inet_addr(ip_address);
        target.sin_port = htons(port);

        // Try to connect to the specified port
        if (connect(sock, (struct sockaddr*)&target, sizeof(target)) < 0) {
            // Connection failed - port is closed
            printf("Port %d is closed\n", port);
            fflush(stdout);
        }
        else {
            // Connection succeeded - port is open
            printf("Port %d is open\n", port);
            fflush(stdout);

            // Close the socket connection
            close(sock);
        }
    }
}

int main(int argc, char *argv[]) {
    // Make sure the correct number of arguments have been entered
    if (argc != 4) {
        printf("Usage: %s <ip_address> <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    // Get the target IP address and port range from the command line arguments
    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Verify that the start and end ports are valid
    if (start_port < 1 || start_port > 65535 || end_port < 1 || end_port > 65535 || start_port > end_port) {
        printf("Invalid port range\n");
        exit(1);
    }

    // Call the scan_port function to scan the specified range of ports on the target IP address
    scan_port(ip_address, start_port, end_port);

    return 0;
}