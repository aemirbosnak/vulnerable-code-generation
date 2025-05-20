//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORT 65535
#define MIN_PORT 1

void scan_port(const char *ip, int port) {
    int sockfd;
    struct sockaddr_in addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set the address structure
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    // Try to connect to the port
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is OPEN\n", port);
    } else {
        // If connection fails with ECONNREFUSED, the port is closed
        if (errno == ECONNREFUSED) {
            printf("Port %d is CLOSED\n", port);
        } else {
            printf("Port %d is filtered or unreachable\n", port);
        }
    }

    // Close the socket
    close(sockfd);
}

void print_usage(const char *program_name) {
    printf("Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", program_name);
    printf("Example: %s 127.0.0.1 20 80\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Validate port range
    if (start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Error: Ports must be between %d and %d, and start port must be less than or equal to end port.\n", MIN_PORT, MAX_PORT);
        return EXIT_FAILURE;
    }

    printf("Starting port scan on %s from port %d to %d...\n", ip, start_port, end_port);

    // Scan the ports
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip, port);
        // Sleep a little to avoid overwhelming the system; you can adjust this
        usleep(100000); // 100 milliseconds
    }

    printf("Port scan completed!\n");
    return EXIT_SUCCESS;
}