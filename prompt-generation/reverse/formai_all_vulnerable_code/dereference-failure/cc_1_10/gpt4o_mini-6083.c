//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define TIMEOUT 1 // Timeout for socket connection attempt

void scan_port(const char *ip, int port);
void print_usage(const char *program_name);
int is_valid_port(int port);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Validate port numbers
    if (!is_valid_port(start_port) || !is_valid_port(end_port) || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Ports must be between 1 and 65535.\n");
        return 1;
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip);
    time_t start_time = time(NULL);

    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip, port);
    }

    time_t end_time = time(NULL);
    double elapsed_time = difftime(end_time, start_time);
    printf("Scan completed in %.2f seconds.\n", elapsed_time);

    return 0;
}

void scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in target;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Configure target address
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip, &target.sin_addr);

    // Attempt to connect to the target port
    if (connect(sock, (struct sockaddr*)&target, sizeof(target)) == 0) {
        printf("Port %d: OPEN\n", port);
    } else {
        printf("Port %d: CLOSED\n", port);
    }

    // Close socket
    close(sock);
}

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", program_name);
}

int is_valid_port(int port) {
    return port >= 1 && port <= 65535;
}