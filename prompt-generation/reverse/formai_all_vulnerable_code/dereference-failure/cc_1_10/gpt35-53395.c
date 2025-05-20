//FormAI DATASET v1.0 Category: Port Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define FIRST_PORT 1
#define LAST_PORT 65535

void scanPort(const char *host, int port) {
    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Socket creation error");
        return;
    }
    
    // Set the server address
    struct hostent *server = gethostbyname(host);
    if(server == NULL) {
        perror("Could not resolve host");
        return;
    }
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);
    
    // Try to connect to the server
    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) >= 0) {
        printf("Port %d: Open\n", port);
    }
    
    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if(argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 0;
    }
    
    // Get the hostname to scan
    const char *host = argv[1];
    
    // Scan all ports from 1 to 65535
    for(int port = FIRST_PORT; port <= LAST_PORT; port++) {
        scanPort(host, port);
    }
    
    return 0;
}