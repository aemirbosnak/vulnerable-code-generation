//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: shape shifting
// Ping Pong Network Tester

// Imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Pong Function
static void pong(int socket, struct sockaddr_in* addr) {
    size_t addrlen = sizeof(*addr);
    printf("Pong!\n");
    if (sendto(socket, "Pong!", strlen("Pong!") + 1, 0, (struct sockaddr*) addr, addrlen) < 0) {
        perror("Sendto Error");
        exit(EXIT_FAILURE);
    }
}

// Ping Function
static int ping(const char* ip, int port) {
    // Create Socket
    int socket_fd;
    if ((socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket Error");
        exit(EXIT_FAILURE);
    }

    // Set Socket Options
    int broadcast = 1;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) < 0) {
        perror("Setsockopt Error");
        exit(EXIT_FAILURE);
    }

    // Set Timeout
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("Setsockopt Error");
        exit(EXIT_FAILURE);
    }

    // Set Socket Address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    // Send Ping
    if (sendto(socket_fd, "Ping!", strlen("Ping!") + 1, 0, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
        perror("Sendto Error");
        exit(EXIT_FAILURE);
    }

    // Receive Pong
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    struct sockaddr_in addr_recv;
    size_t addrlen = sizeof(addr_recv);
    if (recvfrom(socket_fd, buffer, sizeof(buffer), 0, (struct sockaddr*) &addr_recv, &addrlen) < 0) {
        return 0; // Assume Timeout
    }

    // Check if Pong
    if (strcmp(buffer, "Pong!") == 0) {
        return 1; // Pong Received
    } else {
        return -1; // Invalid Response
    }
}

// Main Function
int main(int argc, char** argv) {
    // Usage: ping <ip> <port> <duration> <interval>
    if (argc < 5) {
        printf("Usage: %s <ip> <port> <duration> <interval>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse Arguments
    const char* ip = argv[1];
    int port = atoi(argv[2]);
    int duration = atoi(argv[3]);
    int interval = atoi(argv[4]);

    // Create Socket
    int socket_fd;
    if ((socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket Error");
        exit(EXIT_FAILURE);
    }

    // Set Socket Options
    int broadcast = 1;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) < 0) {
        perror("Setsockopt Error");
        exit(EXIT_FAILURE);
    }

    // Main Loop
    int success = 0;
    int total = 0;
    time_t start = time(NULL);
    while ((time(NULL) - start) < duration) {
        total++;
        int result = ping(ip, port);
        if (result) {
            success++;
            printf("Success: %d/%d\n", success, total);
        } else {
            printf("Timeout\n");
        }
        sleep(interval);
    }

    // Print Results
    printf("\n--------------------\n");
    printf("Ping Results:\n");
    printf("- IP: %s\n", ip);
    printf("- Port: %d\n", port);
    printf("- Duration: %d seconds\n", duration);
    printf("- Interval: %d seconds\n", interval);
    printf("- Success Rate: %.2f%%\n", (float) success / total * 100);
    printf("--------------------\n");

    // Cleanup
    close(socket_fd);
    return EXIT_SUCCESS;
}