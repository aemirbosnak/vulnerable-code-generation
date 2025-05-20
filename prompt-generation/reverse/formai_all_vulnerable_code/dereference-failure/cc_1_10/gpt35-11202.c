//FormAI DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to check if a port is open on a specific host
int check_port(char* target_ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0); // Create a socket

    // Define the address
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(target_ip);
    address.sin_port = htons(port);

    // Attempt to connect
    if (connect(sock, (struct sockaddr*)&address, sizeof(address)) >= 0) {
        close(sock); // Close the socket
        return 1; // Port is open
    }
    else {
        close(sock); // Close the socket
        return 0; // Port is closed
    }
}

// Function to display the usage information
void usage(char* program_name) {
    printf("Usage: %s <target IP> <starting port> <ending port>\n", program_name);
    printf("Example: %s 127.0.0.1 80 443\n", program_name);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 4) { // Check if the correct number of command line arguments were given
        usage(argv[0]); // Display the usage information
        return 1; // Exit with an error
    }

    char* target_ip = argv[1]; // Get the target IP address
    int start_port = atoi(argv[2]); // Get the starting port number
    int end_port = atoi(argv[3]); // Get the ending port number

    if (start_port < 1 || end_port > 65535 || start_port > end_port) { // Check if the port range is valid
        printf("Invalid port range!\n"); // Display an error message
        usage(argv[0]); // Display the usage information
        return 1; // Exit with an error
    }

    printf("Starting port scanner on %s...\n", target_ip);
    printf("Scanning range from %d to %d...\n", start_port, end_port);

    // Loop through each port in the range
    for (int port = start_port; port <= end_port; port++) {
        if (check_port(target_ip, port)) { // Check if the current port is open
            printf("Port %d is open!\n", port); // Display a message if the port is open
        }
    }

    printf("Scan complete!\n"); // Display a message when the scan is complete

    return 0; // Exit successfully
}