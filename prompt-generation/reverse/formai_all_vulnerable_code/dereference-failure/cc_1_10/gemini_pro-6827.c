//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdbool.h>

// Structure for storing host and port information
typedef struct host_port {
    char *host;
    int port;
} host_port;

// Function to scan a single port on a single host
bool scan_port(host_port *hport) {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return false;
    }

    // Set up the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(hport->host);
    serv_addr.sin_port = htons(hport->port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        close(sockfd);
        return false;
    }

    // Close the socket
    close(sockfd);

    // Port is open
    return true;
}

// Main function
int main(int argc, char **argv) {
    // Check for arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Parse host and port
    host_port hport;
    hport.host = argv[1];
    hport.port = atoi(argv[2]);

    // Scan the port
    if (scan_port(&hport)) {
        printf("Port %d on host %s is open\n", hport.port, hport.host);
    } else {
        printf("Port %d on host %s is closed\n", hport.port, hport.host);
    }

    return 0;
}