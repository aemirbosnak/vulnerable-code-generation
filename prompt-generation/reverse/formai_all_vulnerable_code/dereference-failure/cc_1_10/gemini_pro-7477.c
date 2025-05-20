//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/*
 * This program scans a range of ports on a given IP address.
 * It creates a socket, connects to each port in the range, and prints the
 * port number and the result of the connection attempt.
 */

int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments.
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the IP address and port range from the command line arguments.
    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the socket timeout.
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Connect to each port in the range.
    for (int port = start_port; port <= end_port; port++) {
        // Create a sockaddr_in structure for the target address.
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(ip_address);
        addr.sin_port = htons(port);

        // Connect to the target address.
        int result = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));

        // Print the port number and the result of the connection attempt.
        if (result == 0) {
            printf("Port %d: open\n", port);
        } else {
            printf("Port %d: closed\n", port);
        }
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}