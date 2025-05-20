//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <time.h>

#define MAX_PORT 65535
#define MIN_PORT 1
#define BUFFER_SIZE 1024

void scan_port(char *ip, int port) {
    int sock;
    struct sockaddr_in server;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Could not create socket");
        return;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    // Set a timeout for the connection
    struct timeval timeout;
    timeout.tv_sec = 1; // 1 second
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof timeout);

    // Try to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Hooray! Port %d is open on %s!\n", port, ip);
    } else {
        printf("Oops! Port %d is closed on %s.\n", port, ip);
    }

    close(sock);
}

void display_banner() {
    printf("=====================================\n");
    printf("     🎉 Happy Port Scanner 🎉       \n");
    printf("=====================================\n");
}

int main(int argc, char *argv[]) {
    char *target_ip;
    int start_port = MIN_PORT, end_port = MAX_PORT;

    // Check for correct usage
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <ip_address> [start_port] [end_port]\n", argv[0]);
        return EXIT_FAILURE;
    }

    target_ip = argv[1];
    if (argc >= 3) {
        start_port = atoi(argv[2]);
    }
    if (argc >= 4) {
        end_port = atoi(argv[3]);
    }

    // Validate port range
    if (start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Invalid port range! Please use ports between %d and %d\n", MIN_PORT, MAX_PORT);
        return EXIT_FAILURE;
    }

    display_banner();

    // Start the scanning
    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, target_ip);
    clock_t start_time = clock();

    for (int port = start_port; port <= end_port; port++) {
        scan_port(target_ip, port);
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("🎉 Finished scanning! Total time: %.2f seconds 🎉\n", elapsed_time);
    printf("=====================================\n");

    return EXIT_SUCCESS;
}