//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <target> <port-range>\n", argv[0]);
        return 1;
    }

    // Parse target IP address and port range
    char *target = argv[1];
    int start_port = atoi(strtok(argv[2], "-"));
    int end_port = atoi(strtok(NULL, "-"));
    if (start_port <= 0 || end_port <= 0 || start_port > end_port) {
        printf("Invalid port range: %s\n", argv[2]);
        return 2;
    }

    // Create a socket for scanning
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 3;
    }

    // Set up the target address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(start_port);
    if (inet_pton(AF_INET, target, &addr.sin_addr) != 1) {
        perror("inet_pton");
        return 4;
    }

    // Loop through the port range
    for (int port = start_port; port <= end_port; port++) {
        // Connect to the port
        addr.sin_port = htons(port);
        int connfd = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));

        // Check if the port is open
        if (connfd >= 0) {
            printf("[+] Port %d is open\n", port);
            close(connfd);
        } else {
            printf("[-] Port %d is closed\n", port);
        }
    }

    // Clean up
    close(sockfd);
    return 0;
}