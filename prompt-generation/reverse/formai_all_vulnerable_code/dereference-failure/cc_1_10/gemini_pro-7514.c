//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>

// Port scanner function
void scan_ports(char *hostname, int start_port, int end_port) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Iterate through the ports
    for (int port = start_port; port <= end_port; port++) {
        // Create a sockaddr_in structure
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr = *(struct in_addr *)host->h_addr_list[0];

        // Connect to the port
        int result = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
        if (result == 0) {
            // Port is open
            printf("Port %d is open\n", port);
        }
    }

    // Close the socket
    close(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 4) {
        printf("Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    // Get the hostname, start port, and end port from the command line
    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Scan the ports
    scan_ports(hostname, start_port, end_port);

    return 0;
}