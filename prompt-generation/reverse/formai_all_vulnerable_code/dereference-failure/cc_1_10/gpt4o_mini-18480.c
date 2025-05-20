//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: mathematical
#include <stdio.h>      // To perform standard input and output
#include <stdlib.h>     // For memory allocation and process control
#include <string.h>     // For string comparisons and manipulations
#include <unistd.h>     // For the close() function
#include <arpa/inet.h>  // For sockaddr_in structure
#include <netinet/in.h> // For INADDR_ANY constant
#include <sys/socket.h> // For socket functions

// Function for calculating prime status
int is_prime(int number) {
    if (number <= 1) return 0;
    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) return 0;
    }
    return 1;
}

// Function to perform a port scan on the specified host and port range
void port_scan(const char *hostname, int start_port, int end_port) {
    struct sockaddr_in target;
    int sock;
    target.sin_family = AF_INET;
    
    // Convert host from string to IP address
    if (inet_pton(AF_INET, hostname, &target.sin_addr) <= 0) {
        perror("Invalid address");
        return;
    }
    
    // Iterate through the ports
    for (int port = start_port; port <= end_port; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        
        if (sock < 0) {
            perror("Socket creation failed");
            return;
        }
        
        target.sin_port = htons(port); // Set the port number
        
        // Attempt to connect to the port
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d: Open\n", port);
        } else {
            printf("Port %d: Closed\n", port);
        }
        
        close(sock); // Close the socket
    }
}

// Function to display a welcome message
void display_welcome() {
    printf("========================================\n");
    printf("           PORT SCANNER                 \n");
    printf("========================================\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check if arguments are provided
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    display_welcome(); // Display welcome message

    // Parse command line arguments
    const char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Ensure start_port and end_port are within valid range
    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Please use 1-65535.\n");
        return EXIT_FAILURE;
    }

    // Perform a prime check before scanning to add a mathematical touch
    if (is_prime(end_port)) {
        printf("End port %d is a prime number. Initiating advanced scan...\n", end_port);
        port_scan(hostname, start_port, end_port);
    } else {
        printf("End port %d is not a prime number. Proceeding with normal scan...\n", end_port);
        port_scan(hostname, start_port, end_port);
    }

    return EXIT_SUCCESS; // Successful execution
}