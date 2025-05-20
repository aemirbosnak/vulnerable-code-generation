//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_PORT 65535
#define TIMEOUT 1

void scan_port(const char *hostname, int port) {
    int sock;
    struct sockaddr_in sa;
    struct addrinfo hints, *res;
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // Use IPv4
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; // For wildcard IP address

    if (getaddrinfo(hostname, NULL, &hints, &res) != 0) {
        perror("getaddrinfo failed");
        return;
    }

    sa = *(struct sockaddr_in *)res->ai_addr;
    sa.sin_port = htons(port);

    sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock < 0) {
        perror("Socket creation failed");
        freeaddrinfo(res);
        return;
    }

    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));

    if (connect(sock, (struct sockaddr *)&sa, sizeof(sa)) == 0) {
        printf("Port %d: OPEN\n", port);
    } else {
        if (errno == ECONNREFUSED) {
            printf("Port %d: CLOSED\n", port);
        }
        // For other errors (e.g. timeout), we consider it 'FILTERED' or ignore
    }

    close(sock);
    freeaddrinfo(res);
}

void scan_ports(const char *hostname, int start_port, int end_port) {
    if (start_port < 0 || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Ports must be between 0 and %d.\n", MAX_PORT);
        return;
    }

    for (int port = start_port; port <= end_port; port++) {
        scan_port(hostname, port);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Validate port range
    if (start_port < 0 || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Invalid port range specified.\n");
        exit(EXIT_FAILURE);
    }

    printf("Scanning host: %s from port %d to %d\n", hostname, start_port, end_port);
    scan_ports(hostname, start_port, end_port);
    
    return 0;
}