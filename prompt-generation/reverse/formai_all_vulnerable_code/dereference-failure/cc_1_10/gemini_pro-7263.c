//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

// Macros for colors
#define RED   "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE  "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN  "\x1B[36m"
#define RESET "\x1B[0m"

// Function to scan a single port
int scan_port(char *ip, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Creating a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    // Setting up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return -1;
    }

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        return 0;
    }

    // Closing the socket
    close(sockfd);
    return 1;
}

// Function to scan a range of ports
void scan_ports(char *ip, int start_port, int end_port) {
    int i;

    printf(GREEN"Scanning ports %d to %d on %s...\n"RESET, start_port, end_port, ip);

    for (i = start_port; i <= end_port; i++) {
        if (scan_port(ip, i)) {
            printf(GREEN"Port %d open\n"RESET, i);
        } else {
            printf(RED"Port %d closed\n"RESET, i);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf(RED"Usage: %s <ip> <start_port> <end_port>\n"RESET, argv[0]);
        return 1;
    }

    scan_ports(argv[1], atoi(argv[2]), atoi(argv[3]));

    return 0;
}