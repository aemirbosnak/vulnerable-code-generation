//FormAI DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

// Function to scan a port on a given IP address
void scan_port(char *ip_address, int port) {
    // Creating a socket to connect to the IP address on the given port
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        printf("Failed to create socket. Error: %d", errno);
        exit(1);
    }
    
    // Setting up the socket address for the IP address and port
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_port = htons(port);
    
    // Connecting to the socket
    int result = connect(sock_fd, (struct sockaddr *)&server, sizeof(server));
    if (result == 0) {
        printf("Port %d open on %s\n", port, ip_address);
    }
    
    // Closing the socket
    close(sock_fd);
}

int main(int argc, char *argv[]) {
    // Checking that the correct number of arguments are provided
    if (argc != 3) {
        printf("Usage: portscanner ip_address port_range\n");
        return 1;
    }
    
    // Extracting the IP address and port range from the command line arguments
    char *ip_address = argv[1];
    char *port_range = argv[2];
    
    // Parsing the port range into the start and end port numbers
    char *start_port_str = strtok(port_range, "-");
    char *end_port_str = strtok(NULL, "-");
    int start_port = atoi(start_port_str);
    int end_port = atoi(end_port_str);
    
    // Scanning the ports in the given range on the given IP address
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip_address, port);
    }
    
    return 0;
}