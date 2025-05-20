//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

// Function to scan a single port
int scan_port(const char *hostname, int port) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }

    // Create the socket address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr, host->h_addr_list[0], host->h_length);

    // Connect to the port
    int result = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (result == -1) {
        close(sockfd);
        return -1;
    }

    // Close the socket
    close(sockfd);

    // Return success
    return 0;
}

// Function to scan a range of ports
int scan_ports(const char *hostname, int start_port, int end_port) {
    // Iterate over the ports
    for (int port = start_port; port <= end_port; port++) {
        // Scan the port
        int result = scan_port(hostname, port);

        // Print the result
        if (result == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    // Return success
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check the arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Scan the ports
    int result = scan_ports(argv[1], atoi(argv[2]), atoi(argv[3]));

    // Exit
    return result;
}