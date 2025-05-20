//FormAI DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // Get IP address and range of ports to scan from command line arguments
    if (argc != 3) {
        printf("Usage: %s <IP address> <port range e.g 1-65535>\n", argv[0]);
        return 0;
    }
    char* ip_addr = argv[1];
    char* port_range = argv[2];
    int start_port = atoi(strtok(port_range, "-"));
    int end_port = atoi(strtok(NULL, "-"));
    
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }
    
    // Set socket timeout to 1 second
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("Error setting socket timeout");
        return 1;
    }
    
    // Scan each port in the range
    for (int port = start_port; port <= end_port; port++) {
        // Set up server address struct
        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, ip_addr, &server_addr.sin_addr);
        
        // Connect to server
        int status = connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr));
        if (status < 0) {
            // Port is closed
            // Do nothing
        }
        else {
            // Port is open
            printf("Port %d is open\n", port);
        }
    }
    
    // Close socket
    close(sockfd);
    return 0;
}