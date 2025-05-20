//FormAI DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *hostname;
    int start_port, end_port;
    struct hostent *host;
    struct sockaddr_in sock_addr;
    int sockfd, result;
    
    // Check if arguments are provided
    if (argc != 4) {
        printf("Usage: %s hostname start_port end_port\n", argv[0]);
        exit(1);
    }
    
    // Get the hostname, start port and end port from command line arguments
    hostname = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);
    
    // Get host information
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Unable to resolve hostname: %s\n", hostname);
        exit(1);
    }
    
    // Initialize socket address structure
    memset(&sock_addr, 0, sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    memcpy(&sock_addr.sin_addr, host->h_addr, host->h_length);
    
    // Loop through all ports
    for (int port = start_port; port <= end_port; port++) {
        // Create socket
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            printf("Unable to create socket.\n");
            exit(1);
        }
        
        // Set socket timeout to 1 second
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;
        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
            printf("Unable to set socket timeout.\n");
            exit(1);
        }
        
        // Connect to the remote host
        sock_addr.sin_port = htons(port);
        result = connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr));
        if (result == 0) {
            printf("Port %d is open.\n", port);
        } else {
            printf("Port %d is closed.\n", port);
        }
        
        // Close the socket
        close(sockfd);
    }
    
    return 0;
}