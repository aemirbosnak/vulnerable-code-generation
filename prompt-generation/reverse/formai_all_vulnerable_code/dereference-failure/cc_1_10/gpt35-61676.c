//FormAI DATASET v1.0 Category: Port Scanner ; Style: detailed
/*
 * A unique C Port Scanner example program
 * By [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define constants
#define TIMEOUT_SEC 1
#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    // Check for correct number of arguments, 2 expected (IP address and port range)
    if(argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <port range (e.g. 1-1000)>\n", argv[0]);
        exit(1);
    }

    // Parse arguments
    char *ip_addr_str = argv[1];
    char *port_range_str = argv[2];
    char *port_start_str = strtok(port_range_str, "-");
    char *port_end_str = strtok(NULL, "-");
    int port_start = atoi(port_start_str);
    int port_end = atoi(port_end_str);

    // Validate IP address
    struct sockaddr_in sa;
    if(inet_pton(AF_INET, ip_addr_str, &(sa.sin_addr)) != 1) {
        fprintf(stderr, "Invalid IP address: %s\n", ip_addr_str);
        exit(1);
    }

    // Create socket for TCP connection
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("Could not create socket");
        exit(1);
    }

    // Set timeout for socket
    struct timeval tv;
    tv.tv_sec = TIMEOUT_SEC;
    tv.tv_usec = 0;
    if(setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("Could not set timeout on socket");
        exit(1);
    }

    // Scan ports
    for(int port = port_start; port <= port_end; port++) {
        // Set up socket address struct
        struct sockaddr_in sa;
        sa.sin_family = AF_INET;
        sa.sin_addr.s_addr = inet_addr(ip_addr_str);
        sa.sin_port = htons(port);

        // Attempt to connect
        if(connect(sock, (struct sockaddr*)&sa, sizeof(sa)) == 0) {
            printf("Port %d is open.\n", port);
        }
    }

    // Close socket
    close(sock);

    return 0;
}