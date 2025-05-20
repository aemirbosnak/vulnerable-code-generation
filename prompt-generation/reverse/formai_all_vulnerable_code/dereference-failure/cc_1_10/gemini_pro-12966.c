//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// The main function, where the program starts execution
int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments
    if (argc < 3) {
        printf("Usage: %s <target IP> <port range>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the target IP address and port range
    char *target = argv[1];
    int startPort = atoi(argv[2]);
    int endPort = atoi(argv[3]);

    // Create a socket for scanning
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up the target address
    struct sockaddr_in targetAddr;
    memset(&targetAddr, 0, sizeof(targetAddr));
    targetAddr.sin_family = AF_INET;
    targetAddr.sin_port = htons(startPort);
    targetAddr.sin_addr.s_addr = inet_addr(target);

    // Scan the ports in the specified range
    for (int port = startPort; port <= endPort; port++) {
        // Modify the target port
        targetAddr.sin_port = htons(port);

        // Connect to the target port
        int connfd = connect(sockfd, (struct sockaddr *) &targetAddr, sizeof(targetAddr));

        // Check if the connection was successful
        if (connfd == 0) {
            printf("\nElementary, my dear Watson! Port %d is open.\n", port);
        }

        // Close the connection
        close(connfd);
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}