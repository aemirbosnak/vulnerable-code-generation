//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: authentic
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

// Custom error handling function
void error(char *message) {
    perror(message);
    exit(1);
}

// Function to scan a range of ports on a given host
int port_scanner(char *host, int start_port, int end_port) {
    // Initialize variables
    int sockfd, i;
    struct sockaddr_in addr;
    int port_status;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error creating socket");
    }

    // Set up the socket address structure
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(host);

    // Scan the range of ports
    for (i = start_port; i <= end_port; i++) {
        addr.sin_port = htons(i);

        // Connect to the port
        port_status = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));

        // Check the connection status
        if (port_status == 0) {
            printf("Port %d: Open\n", i);
        } else {
            printf("Port %d: Closed\n", i);
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}

int main(int argc, char *argv[]) {
    // Check if the user provided the correct number of arguments
    if (argc != 4) {
        printf("Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    // Parse the command-line arguments
    char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Scan the ports
    port_scanner(host, start_port, end_port);

    return 0;
}