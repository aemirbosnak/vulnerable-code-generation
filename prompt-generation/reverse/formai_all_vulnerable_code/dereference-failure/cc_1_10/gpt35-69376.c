//FormAI DATASET v1.0 Category: Port Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

// Function to scan for open ports
void scan_port(char *ip_address, int start_port, int end_port) {
    int sockfd, status, flags, optval;
    struct sockaddr_in target;
    
    // Loop through all ports in range
    for (int port = start_port; port <= end_port; port++) {
        // Create socket
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            continue;
        }
        
        // Set socket to non-blocking
        flags = fcntl(sockfd, F_GETFL, 0);
        fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
        
        // Set socket options
        optval = 1;
        setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
        
        // Set target address
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        inet_pton(AF_INET, ip_address, &(target.sin_addr));
        
        // Connect to target
        status = connect(sockfd, (struct sockaddr *)&target, sizeof(target));
        
        // Check if connection was successful
        if (status == 0) {
            printf("Port %d is open\n", port);
        } else {
            // Check if connection is in progress
            if (errno == EINPROGRESS) {
                fd_set writefds;
                FD_ZERO(&writefds);
                FD_SET(sockfd, &writefds);
                
                // Wait for connection to complete
                status = select(sockfd + 1, NULL, &writefds, NULL, NULL);
                if (status > 0) {
                    printf("Port %d is open\n", port);
                }
            }
        }
        
        // Close socket
        close(sockfd);
    }
}

int main(int argc, char **argv) {
    // Check for correct number of arguments
    if (argc != 4) {
        printf("Usage: %s <ip_address> <start_port> <end_port>\n", argv[0]);
        return 0;
    }
    
    // Parse arguments
    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Call scan_port function to scan for open ports
    scan_port(ip_address, start_port, end_port);
    
    return 0;
}