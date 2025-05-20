//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>
#include <time.h>

#define TIMEOUT 1
#define MAX_PORT 65535
#define MIN_PORT 1

void scan_port(const char *target_ip, int port) {
    int sockfd;
    struct sockaddr_in target_addr;
    struct timeval tv;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set the timeout for the connection
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));

    // Prepare the target address
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(port);
    inet_pton(AF_INET, target_ip, &target_addr.sin_addr);

    // Attempt to connect to the target port
    if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
        printf("Port %d is OPEN\n", port);
    } else {
        if (errno == ECONNREFUSED) {
            printf("Port %d is CLOSED\n", port);
        } else {
            printf("Port %d is FILTERED\n", port);
        }
    }

    // Close the socket
    close(sockfd);
}

void start_scanning(const char *target_ip, int start_port, int end_port) {
    printf("Starting the exploration into the network territory of %s...\n", target_ip);
    printf("Scanning ports from %d to %d...\n\n", start_port, end_port);

    for (int port = start_port; port <= end_port; port++) {
        printf("Navigating to port %d...\n", port);
        scan_port(target_ip, port);
    }

    printf("\nExploration complete. Safe travels!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *target_ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Port range must be between %d and %d.\n", MIN_PORT, MAX_PORT);
        return EXIT_FAILURE;
    }

    // Start the scanning adventure
    start_scanning(target_ip, start_port, end_port);
    
    return EXIT_SUCCESS;
}