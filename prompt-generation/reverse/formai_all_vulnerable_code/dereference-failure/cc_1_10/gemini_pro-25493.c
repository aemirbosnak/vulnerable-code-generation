//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_PORTS 100

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <target IP> <start port> <end port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *target_ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Check if the given range is valid
    if (start_port < 0 || start_port > 65535 || end_port < 0 || end_port > 65535 || start_port > end_port) {
        printf("Invalid port range\n");
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket()");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(start_port);
    target_addr.sin_addr.s_addr = inet_addr(target_ip);

    // Loop through the specified range of ports
    for (int port = start_port; port <= end_port; port++) {
        target_addr.sin_port = htons(port);

        // Try to connect to the target port
        if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d is open\n", port);
        }
    }

    close(sockfd);

    return EXIT_SUCCESS;
}