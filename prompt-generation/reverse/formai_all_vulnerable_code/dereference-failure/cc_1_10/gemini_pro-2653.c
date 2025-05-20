//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Function to print usage information
void usage() {
    printf("Usage: ./portscanner <target IP address> <start port> <end port>\n");
    printf("Example: ./portscanner 192.168.1.1 1 1024\n");
}

// Function to scan a single port
int scan_port(char *ip, int port) {
    struct sockaddr_in addr;
    int sockfd;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Set the socket address
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    // Attempt to connect to the port
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open\n", port);
        return 0;
    }

    // Close the socket
    close(sockfd);

    return -1;
}

// Function to scan a range of ports
int scan_ports(char *ip, int start_port, int end_port) {
    int i;

    // Scan each port in the range
    for (i = start_port; i <= end_port; i++) {
        scan_port(ip, i);
    }

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    char *ip;
    int start_port, end_port;

    // Check the number of arguments
    if (argc != 4) {
        usage();
        return -1;
    }

    // Get the target IP address
    ip = argv[1];

    // Get the start and end ports
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    // Scan the ports
    scan_ports(ip, start_port, end_port);

    return 0;
}