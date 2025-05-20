//FormAI DATASET v1.0 Category: Port Scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Check for correct number of command-line arguments
    if (argc != 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        printf("Example: %s 192.168.1.1 0-65535\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];

    // Parse the port range
    char *port_range = argv[2];
    char *port_start_str = strtok(port_range, "-");
    char *port_end_str = strtok(NULL, "");

    // Convert port range strings to integers
    int port_start = atoi(port_start_str);
    int port_end = atoi(port_end_str);

    // Create a socket for each port in the range and attempt to connect
    for (int port = port_start; port <= port_end; port++) {
        // Create a socket
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("Error creating socket");
            return 1;
        }

        // Create an address structure for the IP address and port
        struct sockaddr_in target_addr;
        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_port = htons(port);
        if (inet_pton(AF_INET, ip_address, &target_addr.sin_addr) != 1) {
            perror("Error converting IP address");
            return 1;
        }

        // Attempt to connect to the target address and port
        if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d is open\n", port);
        }

        // Close the socket
        close(sockfd);
    }

    return 0;
}