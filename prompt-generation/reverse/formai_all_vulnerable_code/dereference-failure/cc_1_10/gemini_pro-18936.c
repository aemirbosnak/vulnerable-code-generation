//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>

// Display usage information
void usage(char *program_name) {
    printf("Usage: %s <hostname> <port_range_start> <port_range_end>\n", program_name);
    printf("Example: %s google.com 1 100\n", program_name);
}

// Check if a given port is open
int is_port_open(char *hostname, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }

    // Set up the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        close(sockfd);
        return -1;
    }

    // The port is open
    close(sockfd);
    return 0;
}

// Scan a range of ports for a given hostname
void port_scan(char *hostname, int start_port, int end_port) {
    int port;

    // Iterate over the range of ports
    for (port = start_port; port <= end_port; port++) {
        // Check if the port is open
        if (is_port_open(hostname, port) == 0) {
            // The port is open
            printf("Port %d is open\n", port);
        }
    }
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc != 4) {
        usage(argv[0]);
        return 1;
    }

    // Get the hostname, start port, and end port from the command line arguments
    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Check if the provided start port and end port are within a valid range
    if (start_port < 0 || start_port > 65535 || end_port < 0 || end_port > 65535 || start_port > end_port) {
        printf("Invalid port range\n");
        return 1;
    }

    // Perform the port scan
    port_scan(hostname, start_port, end_port);

    return 0;
}