//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// Function to scan a range of ports on a given IP address
int scan_ports(char *ip, int start_port, int end_port) {
    // Create a socket for the scan
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket()");
        return -1;
    }

    // Set the socket address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(start_port);

    // Scan the range of ports
    int num_open_ports = 0;
    for (int port = start_port; port <= end_port; port++) {
        // Set the socket address for the current port
        addr.sin_port = htons(port);

        // Connect to the port
        int ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
        if (ret == 0) {
            // The port is open
            printf("Port %d is open\n", port);
            num_open_ports++;
        }
    }

    // Close the socket
    close(sockfd);

    return num_open_ports;
}

int main(int argc, char **argv) {
    // Check the arguments
    if (argc != 4) {
        printf("Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        return -1;
    }

    // Scan the ports
    int num_open_ports = scan_ports(argv[1], atoi(argv[2]), atoi(argv[3]));

    // Print the results
    printf("Found %d open ports\n", num_open_ports);

    return 0;
}