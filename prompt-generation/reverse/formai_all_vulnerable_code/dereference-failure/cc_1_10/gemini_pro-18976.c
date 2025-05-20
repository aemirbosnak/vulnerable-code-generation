//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_RANGE 65535
#define MAX_HOSTS 255
#define TIMEOUT 1

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <target IP> <starting port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse command line arguments
    char *target_ip = argv[1];
    int starting_port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }

    // Set the socket timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1) {
        perror("setsockopt() failed");
        return EXIT_FAILURE;
    }

    // Create a sockaddr_in structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(starting_port);
    addr.sin_addr.s_addr = inet_addr(target_ip);

    // Scan ports
    for (int port = starting_port; port <= PORT_RANGE; port++) {
        addr.sin_port = htons(port);

        // Connect to the port
        int ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));

        // Check if the port is open
        if (ret == 0) {
            printf("Port %d is open\n", port);
        }
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}