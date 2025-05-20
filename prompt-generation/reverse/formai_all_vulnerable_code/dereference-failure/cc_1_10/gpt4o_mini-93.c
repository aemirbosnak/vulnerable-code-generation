//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>

#define TIMEOUT 1

void scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;
    struct timeval tv;

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set timeout for socket operations
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);
    
    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    // Attempt to connect to the port
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        // Port is closed or not accessible
        close(sock);
        return;
    }

    // If we reach here, the port is open
    printf("Port %d is open\n", port);
    close(sock);
}

void usage(const char *prog_name) {
    printf("Usage: %s <IP Address> <Start Port> <End Port>\n", prog_name);
    printf("Example: %s 192.168.1.1 1 1024\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *target_ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Validating port range
    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Must be between 1 and 65535 and start must be less than or equal to end.\n");
        return EXIT_FAILURE;
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, target_ip);

    for (int port = start_port; port <= end_port; port++) {
        scan_port(target_ip, port);
    }

    printf("Scanning complete!\n");
    return EXIT_SUCCESS;
}