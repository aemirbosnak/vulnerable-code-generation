//FormAI DATASET v1.0 Category: Port Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void scan_port(char *address, int start_port, int end_port);

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Usage: %s <IP address> <start port> <end port> \n", argv[0]);
        exit(1);
    }

    char *address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    scan_port(address, start_port, end_port);

    return 0;
}

void scan_port(char *address, int start_port, int end_port) {
    int sockfd;
    struct sockaddr_in target;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Cannot create socket");
        exit(1);
    }

    // Set address and port of target
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(address);

    // Scan ports in range
    for(int port = start_port; port <= end_port; port++) {
        target.sin_port = htons(port);

        // Attempt to connect to port
        if(connect(sockfd, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d: Open\n", port);
        }
        else {
            printf("Port %d: Closed\n", port);
        }

        // Close socket to free resources
        close(sockfd);
    }
}