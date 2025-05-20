//FormAI DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Get command line arguments
    if (argc < 2) {
        printf("Usage: %s <target_ip> [<start_port> <end_port>]\n", argv[0]);
        return 1;
    }
    char *ip = argv[1];
    int start_port = 1, end_port = 65535;
    if (argc > 2) {
        start_port = atoi(argv[2]);
        if (argc > 3) {
            end_port = atoi(argv[3]);
        }
    }
    // Create socket
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }
    // Set socket options
    int opt = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        return 1;
    }
    // Scan ports
    printf("Scanning %s...\n", ip);
    for (int port = start_port; port <= end_port; port++) {
        struct sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr(ip);
        server.sin_port = htons(port);
        if (connect(sock, (struct sockaddr *)&server , sizeof(server)) >= 0) {
            printf("Port %d: Open\n", port);
            close(sock);
            if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                perror("socket");
                return 1;
            }
            if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
                perror("setsockopt");
                return 1;
            }
        }
    }
    printf("Scan finished\n");
    return 0;
}