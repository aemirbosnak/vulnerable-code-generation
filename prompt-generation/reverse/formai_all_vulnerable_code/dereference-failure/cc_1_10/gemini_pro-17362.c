//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

// Function to scan a single port on a host
int scan_port(char *host, int port) {
    struct sockaddr_in addr;
    int sockfd, ret;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Set up the sockaddr_in struct
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    // Connect to the host
    ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    // Close the socket
    close(sockfd);

    // Return 0 if the port is open, -1 otherwise
    return 0;
}

// Function to scan a range of ports on a host
void scan_host(char *host, int start_port, int end_port) {
    int i;

    printf("Scanning host %s: \n", host);

    for (i = start_port; i <= end_port; i++) {
        if (scan_port(host, i) == 0) {
            printf("Port %d is open\n", i);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    char *host;
    int start_port, end_port;

    // Check if the user provided enough arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the host, start port, and end port from the command line
    host = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    // Scan the host
    scan_host(host, start_port, end_port);

    return EXIT_SUCCESS;
}