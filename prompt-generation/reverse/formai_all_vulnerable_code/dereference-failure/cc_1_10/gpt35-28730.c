//FormAI DATASET v1.0 Category: Port Scanner ; Style: Ada Lovelace
// Ada Lovelace-inspired C Port Scanner
// Author: [Your Name Here]

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to check if a port is open
bool portIsOpen(char *ip, int port) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *msg = "Hello from the other side!";
    char buffer[1024] = {0};
    
    // Create socket file descriptor
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return false;
    }
    
    // Set server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if(inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return false;
    }
    
    // Connect to server
    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Port %d is closed on %s\n", port, ip);
        return false;
    }
    
    // Send and receive data
    send(sock, msg, strlen(msg), 0);
    valread = read(sock, buffer, 1024);
    printf("Port %d is open on %s\n", port, ip);
    close(sock);
    return true;
}

int main(int argc, char **argv) {
    int min_port, max_port;
    
    // Get IP address and port range from command line arguments
    char *ip = argv[1];
    if(argc < 4) {
        printf("Usage: %s <IP address> <minimum port> <maximum port>\n", argv[0]);
        return 1;
    } else {
        min_port = atoi(argv[2]);
        max_port = atoi(argv[3]);
    }
    
    // Scan port range
    for(int port = min_port; port <= max_port; port++) {
        portIsOpen(ip, port);
    }
    
    return 0;
}