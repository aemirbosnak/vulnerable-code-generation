//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to check if a port is open
int is_port_open(char *ip, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return -1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        return 0;
    }

    // Close the socket
    close(sockfd);

    // Port is open
    return 1;
}

// Function to scan a range of ports
void scan_ports(char *ip, int start_port, int end_port) {
    int i;

    // Scan each port in the range
    for (i = start_port; i <= end_port; i++) {
        if (is_port_open(ip, i)) {
            printf("Port %d is open\n", i);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    char *ip;
    int start_port, end_port;

    // Check if the user has provided all the necessary arguments
    if (argc != 4) {
        printf("Usage: %s <ip> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    // Get the IP address, start port, and end port from the user
    ip = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    // Scan the ports
    scan_ports(ip, start_port, end_port);

    return 0;
}