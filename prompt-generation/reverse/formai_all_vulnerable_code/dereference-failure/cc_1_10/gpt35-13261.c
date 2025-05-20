//FormAI DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void scan_host(const char * host, int start_port, int end_port) {
    // Create socket
    int sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        perror("Could not create socket");
        return;
    }
    // Set timeout
    struct timeval timeout;
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    // Scan ports
    for (int port = start_port; port <= end_port; port++) {
        // Prepare sockaddr_in structure
        struct sockaddr_in server;
        server.sin_addr.s_addr = inet_addr(host);
        server.sin_family = AF_INET;
        server.sin_port = htons(port);

        // Connect
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
            printf("Port %d: CLOSED\n", port);
        } else {
            printf("Port %d: OPEN\n", port);
            close(sock);
            // Re-create socket for next port
            sock = socket(AF_INET , SOCK_STREAM , 0);
            if (sock == -1) {
                perror("Could not create socket");
                return;
            }
            setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
        }
    }
    // Done scanning
    printf("Scan complete.\n");
    close(sock);
}

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    const char* host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || start_port > 65535) {
        fprintf(stderr, "Invalid start_port\n");
        return 1;
    }
    if (end_port < 1 || end_port > 65535) {
        fprintf(stderr, "Invalid end_port\n");
        return 1;
    }
    if (start_port > end_port) {
        fprintf(stderr, "Start port cannot be greater than end port\n");
        return 1;
    }

    printf("Scanning host %s from port %d to %d\n", host, start_port, end_port);

    scan_host(host, start_port, end_port);

    return 0;
}