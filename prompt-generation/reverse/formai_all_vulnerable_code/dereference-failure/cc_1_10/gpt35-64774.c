//FormAI DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int start_port, end_port;
    char *ip_addr;
    int sock;
    struct sockaddr_in addr;
    
    // Check if enough arguments are provided
    if (argc < 4) {
        printf("Usage: %s <start_port> <end_port> <ip_address>\n", argv[0]);
        exit(0);
    }
    
    // Parse input arguments
    start_port = atoi(argv[1]);
    end_port = atoi(argv[2]);
    ip_addr = argv[3];
    
    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    
    // Check if socket creation was successful
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Scanning ports %d - %d on %s:\n", start_port, end_port, ip_addr);
    
    // Initialize sockaddr_in addr structure
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    for (int i = start_port; i <= end_port; i++) {
        addr.sin_port = htons(i);

        // Try to connect to the port
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            printf("Port %d is closed.\n", i);
        } else {
            printf("\033[1;32mPort %d is open.\033[0m\n", i);
            close(sock); // Close the socket
        }

        // Create a new socket
        sock = socket(AF_INET, SOCK_STREAM, 0);
    }

    return 0;
}