//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_PORT 65535
#define TIMEOUT 1

// Function to check if a port is open
int check_port(const char *hostname, int port) {
    int sock;
    struct sockaddr_in server;
    struct timeval timeout;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Set up connection attributes
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Convert hostname to IP address
    struct hostent *host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        herror("gethostbyname failed");
        close(sock);
        return -1;
    }
    server.sin_addr = *((struct in_addr *)host_entry->h_addr_list[0]);

    // Set timeout
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));
    
    // Try to connect to the port
    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    
    close(sock);
    return (result == 0) ? 1 : 0;  // Return 1 if open, 0 if closed
}

// Function to print the results in a cheerful format
void print_results(const char *hostname, int port, int is_open) {
    if (is_open) {
        printf("🎉 Port %d on %s is OPEN! 🎉\n", port, hostname);
    } else {
        printf("🚪 Port %d on %s is CLOSED. 🚪\n", port, hostname);
    }
}

int main(int argc, char *argv[]) {
    // Check if the right number of arguments are provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *hostname = argv[1];
    printf("🚀 Starting port scan on %s...\n", hostname);
    
    // Scan ports from 1 to 65535
    for (int port = 1; port <= MAX_PORT; port++) {
        // Check if the port is open
        int is_open = check_port(hostname, port);
        
        // Print the result
        print_results(hostname, port, is_open);
    }

    printf("🔍 Finished scanning ports on %s! 🎯\n", hostname);
    return EXIT_SUCCESS;
}