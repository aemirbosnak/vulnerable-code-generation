//FormAI DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
    // Check if the correct number of arguments was passed
    if (argc != 4) {
        printf("Usage: portscanner [host] [start port] [end port]\n");
        return EXIT_FAILURE;
    }
    
    // Parse the input arguments
    char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    
    // Create a socket
    int socket_id = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_id == -1) {
        printf("Error: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    
    // Resolve the hostname
    struct in_addr *addr = malloc(sizeof(struct in_addr));
    if (inet_pton(AF_INET, host, addr) != 1) {
        printf("Error: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    
    // Loop over all ports in the given range
    for (int port = start_port; port <= end_port; port++) {
        // Create a sockaddr_in struct with the IP address and port
        struct sockaddr_in sockaddr;
        sockaddr.sin_family = AF_INET;
        sockaddr.sin_port = htons(port);
        sockaddr.sin_addr = *addr;
        
        // Try to connect to the port
        if (connect(socket_id, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) != -1) {
            printf("Port %d is open\n", port);
            close(socket_id);
            socket_id = socket(AF_INET, SOCK_STREAM, 0);
            if (socket_id == -1) {
                printf("Error: %s\n", strerror(errno));
                return EXIT_FAILURE;
            }
        } else {
            printf("Port %d is closed\n", port);
        }
    }
    
    return EXIT_SUCCESS;
}