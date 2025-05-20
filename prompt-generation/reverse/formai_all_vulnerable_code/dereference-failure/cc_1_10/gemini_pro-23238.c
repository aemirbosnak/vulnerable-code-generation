//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

// Function to scan a single port
int scan_port(char *ip, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return -1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        return -1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}

// Function to scan a range of ports
int scan_ports(char *ip, int start_port, int end_port) {
    int i;

    for (i = start_port; i <= end_port; i++) {
        if (scan_port(ip, i) == 0) {
            printf("Port %d is open\n", i);
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <ip> <start_port> <end_port>\n", argv[0]);
        return -1;
    }

    // Get the IP address
    char *ip = argv[1];

    // Get the start and end ports
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Scan the ports
    scan_ports(ip, start_port, end_port);

    return 0;
}