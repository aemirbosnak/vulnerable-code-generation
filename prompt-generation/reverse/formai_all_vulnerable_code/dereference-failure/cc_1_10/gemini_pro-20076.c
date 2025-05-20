//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

// A simple port scanner that scans a range of ports on a target IP address.
int main(int argc, char** argv) {
    // Check if the user provided the correct number of arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <target IP address> <start port> <end port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the target IP address.
    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);

    // Parse the start and end ports.
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Scan the ports.
    for (int port = start_port; port <= end_port; port++) {
        // Set the target port.
        target.sin_port = htons(port);

        // Connect to the target port.
        if (connect(sockfd, (struct sockaddr*)&target, sizeof(target)) == 0) {
            // The port is open.
            printf("Port %d is open.\n", port);
        } else {
            // The port is closed.
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed.\n", port);
            } else {
                perror("connect");
                return EXIT_FAILURE;
            }
        }
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}