//FormAI DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#define ERROR -1

int main(int argc, char *argv[])
{
    int sockfd, startport, endport, port;
    int result;
    struct sockaddr_in host_addr;
    struct hostent *host;
 
    if(argc < 2) {
        printf("Usage: %s <hostname or IP>\n", argv[0]);
        return 0;
    }
 
    // Get hostname or ip address
    if((host = gethostbyname(argv[1])) == NULL) {
        printf("Could not resolve hostname: %s\n", argv[1]);
        return 0;
    }
 
    // Start port and End port range
    startport = 1;
    endport = 65535;
 
    // Create socket
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR) {
        perror("Could not create socket");
        return 0;
    }
 
    // Set socket parameters
    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(0);
    host_addr.sin_addr = *((struct in_addr*) host->h_addr);
 
    // Bind socket
    if(bind(sockfd, (struct sockaddr*)&host_addr, sizeof(host_addr)) != 0) {
        printf("Could not bind to socket\n");
        return 0;
    }
 
    // Connect to remote host
    if(connect(sockfd, (struct sockaddr*)&host_addr, sizeof(host_addr)) == ERROR) {
        printf("Could not connect to host: %s\n", argv[1]);
        return 0;
    }
 
    printf("PORT   STATE\n");
 
    // Scan port range
    for(port = startport; port <= endport; port++) {
        // Set socket parameters
        host_addr.sin_family = AF_INET;
        host_addr.sin_port = htons(port);
        host_addr.sin_addr = *((struct in_addr*) host->h_addr);
 
        // Try to connect to port
        result = connect(sockfd, (struct sockaddr*)&host_addr, sizeof(host_addr));
 
        if(result == 0) {
            printf("%-6d open\n", port);
        } else {
            printf("%-6d closed\n", port);
        }
    }
 
    // Close socket
    close(sockfd);
    return 0;
}