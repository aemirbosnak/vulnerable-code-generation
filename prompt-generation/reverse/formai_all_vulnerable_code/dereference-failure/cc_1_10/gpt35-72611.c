//FormAI DATASET v1.0 Category: Port Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_LENGTH 1024

void displayUsage() {
    printf("\n\nWelcome to the Port Scanner Puzzle!\n\n");
    printf("This program can be used to scan open ports on a specified target.\n\n");
    printf("To use this program, please provide a target IP address and a port range to scan.\n");
    printf("The port range should be specified in the following format: start_port-end_port.\n\n");
    printf("For example, if you want to scan ports 80 to 90 on IP address 192.168.0.1, you would type:\n");
    printf("./port_scanner 192.168.0.1 80-90\n\n");
}

int main(int argc, char *argv[]) {
    // Display the program instructions
    displayUsage();

    // Verify that the user entered the correct number of command-line arguments
    if (argc != 3) {
        printf("Error: too few or too many arguments provided.\n");
        exit(1);
    }

    // Parse the IP address and port range provided by the user
    char *ip_address = argv[1];
    char *port_range = argv[2];

    // Parse the start and end ports from the port range provided by the user
    char *token = strtok(port_range, "-");
    int start_port = atoi(token);
    token = strtok(NULL, "-");
    int end_port = atoi(token);

    // Initialize the socket address structure
    struct sockaddr_in sock_addr;
    memset(&sock_addr, 0, sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(start_port);
    inet_pton(AF_INET, ip_address, &sock_addr.sin_addr);

    // Set up the socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_fd == -1) {
        printf("Error: failed to create socket.\n");
        exit(1);
    }

    // Scan the specified port range for open ports
    int port_number;
    for (port_number = start_port; port_number <= end_port; port_number++) {
        // Update the port number in the socket address structure
        sock_addr.sin_port = htons(port_number);

        // Attempt to connect to the specified port
        int result = connect(sock_fd, (struct sockaddr *)&sock_addr, sizeof(sock_addr));

        // If the connection attempt is successful, display the open port number
        if (result == 0) {
            printf("Port %d is open.\n", port_number);
        }
    }

    // Clean up and exit the program
    close(sock_fd);
    return 0;
}