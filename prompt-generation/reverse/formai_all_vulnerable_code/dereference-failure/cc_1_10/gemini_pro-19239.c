//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535
#define MAX_HOST_LENGTH 256

// Function to scan a single port
int scan_port(char *host, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Set up the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        close(sockfd);
        return -1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}

// Function to scan a range of ports
int scan_ports(char *host, int start_port, int end_port) {
    int i;

    for (i = start_port; i <= end_port; i++) {
        if (scan_port(host, i) == 0) {
            printf("Port %d is open\n", i);
        }
    }

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    char *host;
    int start_port, end_port;

    // Check the command line arguments
    if (argc != 4) {
        printf("Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        return -1;
    }

    host = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    // Scan the ports
    scan_ports(host, start_port, end_port);

    return 0;
}