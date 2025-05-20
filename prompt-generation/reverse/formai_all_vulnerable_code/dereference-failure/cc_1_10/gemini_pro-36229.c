//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the maximum number of ports to scan
#define MAX_PORTS 100

// Function to check if a port is open on a given hostname
int isPortOpen(char *hostname, int port) {
    // Create a socket and connect to the hostname on the specified port
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }
    
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return -1;
    }
    
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == 0) {
        // The port is open
        close(sockfd);
        return 1;
    } else {
        // The port is closed
        close(sockfd);
        return 0;
    }
}

// Function to scan a range of ports on a given hostname
void portScan(char *hostname, int startPort, int endPort) {
    // Check if the hostname is valid
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Invalid hostname %s\n", hostname);
        return;
    }
    
    // Check if the start and end ports are valid
    if (startPort < 0 || startPort > 65535 || endPort < 0 || endPort > 65535) {
        printf("Invalid port range %d-%d\n", startPort, endPort);
        return;
    }
    
    // Scan the range of ports
    for (int port = startPort; port <= endPort; port++) {
        if (isPortOpen(hostname, port)) {
            printf("Port %d is open on %s\n", port, hostname);
        }
    }
}

// Main function
int main(int argc, char **argv) {
    // Check if the number of arguments is correct
    if (argc != 4) {
        printf("Usage: %s <hostname> <startPort> <endPort>\n", argv[0]);
        return 1;
    }
    
    // Parse the hostname, start port, and end port
    char *hostname = argv[1];
    int startPort = atoi(argv[2]);
    int endPort = atoi(argv[3]);
    
    // Scan the range of ports
    portScan(hostname, startPort, endPort);
    
    return 0;
}