//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// Function to scan a single port on a given IP address
int scan_port(char *ip, int port) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Set the server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        // Port is closed
        close(sockfd);
        return 0;
    } else {
        // Port is open
        close(sockfd);
        return 1;
    }
}

// Function to scan a range of ports on a given IP address
void scan_ports(char *ip, int start, int end) {
    int i;
    for (i = start; i <= end; i++) {
        if (scan_port(ip, i)) {
            printf("Port %d is open on %s\n", i, ip);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        return -1;
    }

    // Get the IP address, start port, and end port from the command line arguments
    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Scan the range of ports on the given IP address
    scan_ports(ip, start_port, end_port);

    return 0;
}