//FormAI DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define START_PORT 1
#define END_PORT 1024
#define TIMEOUT 1000

/* Function to print the usage of the program*/
void print_usage() {
    printf("Usage: ./port_scanner [IP address]\n");
}

/* Function to print the result of the port scan*/
void print_result(int port, const char* status) {
    printf("Port %d: %s\n", port, status);
}

/* Function to scan a single port*/
void scan_port(char* ip_address, int port) {
    // Create a socket for the scan
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket for port %d: %s\n", port, strerror(errno));
        return;
    }
    
    // Set timeout for the socket
    struct timeval tv;
    tv.tv_sec = TIMEOUT / 1000;
    tv.tv_usec = (TIMEOUT % 1000) * 1000;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0 ||
        setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv)) < 0) {
        printf("Error setting timeout for port %d: %s\n", port, strerror(errno));
        return;
    }
    
    // Set up the address struct
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &addr.sin_addr);
    
    // Connect to the port
    if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        print_result(port, "Closed");
    } else {
        print_result(port, "Open");
    }
    
    // Close the socket
    close(sockfd);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        print_usage();
        return 1;
    }
    
    char* ip_address = argv[1];
    printf("Starting port scan on %s...\n", ip_address);
    
    // Loop through the ports and scan each one
    for (int port = START_PORT; port <= END_PORT; port++) {
        scan_port(ip_address, port);
    }
    
    printf("Port scan complete!\n");
    return 0;
}