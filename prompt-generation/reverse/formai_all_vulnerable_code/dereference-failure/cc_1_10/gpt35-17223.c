//FormAI DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) { // Check if user provided IP address and range
        printf("Usage: %s IP_ADDRESS PORT_RANGE\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create TCP socket
    if (sockfd == -1) { // Check for errors
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr)); // Zero out memory
    target_addr.sin_family = AF_INET; // IPv4 address family
    
    if (inet_pton(AF_INET, argv[1], &target_addr.sin_addr) != 1) { // Convert IP address to binary form
        fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    char *delim = strchr(argv[2], '-'); // Check if range is specified
    int start_port, end_port;
    if (delim != NULL) { // Range is specified
        *delim = '\0'; // Replace delimiter with null terminator
        start_port = atoi(argv[2]);
        end_port = atoi(delim + 1); // Point after delimiter
    } else { // Single port
        start_port = atoi(argv[2]);
        end_port = start_port + 1; // Only scan one port
    }
    
    printf("Scanning %s ports %d-%d...\n", argv[1], start_port, end_port - 1);
    for (int port = start_port; port < end_port; port++) {
        target_addr.sin_port = htons(port); // Set target port
        
        if (connect(sockfd, (struct sockaddr *) &target_addr, sizeof(target_addr)) == 0) { // Check if connection was successful
            printf("Port %d open\n", port);
        } else {
            // perror("connect"); // Uncomment to display error message for closed ports
        }
    }

    close(sockfd); // Close socket
    printf("Scan completed!\n");

    return 0;
}