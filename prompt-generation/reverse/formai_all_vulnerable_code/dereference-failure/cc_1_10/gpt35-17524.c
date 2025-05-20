//FormAI DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

void scan_port(char *host, int port) {
    struct sockaddr_in addr;
    int sockfd, result;
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("socket");
        return;
    }
    
    // Set the address
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);
    
    // Connect to the port
    result = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if(result == -1) {
        close(sockfd);
        return;
    }
    
    // Port is open
    printf("Port %d is open\n", port);
    
    // Close the socket
    close(sockfd);
}

int main(int argc, char **argv) {
    char *host;
    int port, i;
    
    if(argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }
    
    // Get the host and port
    host = argv[1];
    port = atoi(argv[2]);
    
    // Scan the port
    scan_port(host, port);
    
    return 0;
}