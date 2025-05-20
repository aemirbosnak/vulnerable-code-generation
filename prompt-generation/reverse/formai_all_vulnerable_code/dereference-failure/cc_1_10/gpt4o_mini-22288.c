//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

#define TIMEOUT 1
#define MAX_PORT 65535

// Function to check if a port is open on the given IP
int is_port_open(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 0;
    }
    
    // Set timeout for the socket
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof(tv));
    
    // Define server address
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);
    
    // Attempt to connect
    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    close(sock);
    
    return (result == 0);
}

// Function to scan a range of ports
void scan_ports(const char *ip, int start_port, int end_port) {
    printf("Scanning ports on %s:\n", ip);
    
    for (int port = start_port; port <= end_port; port++) {
        printf("Checking port %d... ", port);
        if (is_port_open(ip, port)) {
            printf("Open\n");
        } else {
            printf("Closed\n");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <ip-address> <start-port> <end-port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > MAX_PORT) {
        fprintf(stderr, "Port numbers must be between 1 and %d.\n", MAX_PORT);
        exit(EXIT_FAILURE);
    }

    if (start_port > end_port) {
        fprintf(stderr, "Start port must be less than or equal to end port.\n");
        exit(EXIT_FAILURE);
    }

    // Start time for duration measuring
    clock_t start_time = clock();
    
    // Scan specified ports
    scan_ports(ip, start_port, end_port);
    
    // End time
    clock_t end_time = clock();
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nPort scan completed in %.2f seconds.\n", time_spent);
    
    return 0;
}