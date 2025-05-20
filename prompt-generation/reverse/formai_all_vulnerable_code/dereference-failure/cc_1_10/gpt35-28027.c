//FormAI DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide an IP address as an argument\n");
        return 1;
    }
    
    char *ip_address = argv[1];
    
    // Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    if (client_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }
    
    // Loop through all possible port numbers
    printf("Scanning ports on %s...\n", ip_address);
    int num_ports_scanned = 0;
    
    for (int port = 1; port <= 65535; port++) {
        // Set up sockaddr_in struct
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(port);
        server_address.sin_addr.s_addr = inet_addr(ip_address);
        
        // Try connecting to the port
        int connect_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));
        
        if (connect_status == -1) {
            // Port is closed
            continue;
        }
        // Port is open!
        printf("Port %d is open!\n", port);
        num_ports_scanned++;
        
        // Close the connection
        close(client_socket);
        // Reset the socket
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
    }
    
    if (num_ports_scanned == 0) {
        printf("No open ports found on %s\n", ip_address);
    }
    
    // Close the socket and exit
    close(client_socket);
    return 0;
}