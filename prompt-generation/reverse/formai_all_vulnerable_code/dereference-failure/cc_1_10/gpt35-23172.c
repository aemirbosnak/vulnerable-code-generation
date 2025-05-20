//FormAI DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT>\n", argv[0]);
        exit(1);
    }

    int start_port = atoi(argv[2]);
    int current_port = start_port;
    int end_port = 65535;
    char *ip_address = argv[1];

    int sock;
    struct sockaddr_in target;

    memset(&target, 0, sizeof(target));

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation error");
        exit(1);
    }

    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_address);

    printf("Scanning ports %d through %d on host %s...\n\n", start_port, end_port, ip_address);

    // Loop through ports
    while (current_port <= end_port) {
        // Open port
        target.sin_port = htons(current_port);
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is open\n", current_port);
        }

        // Close port
        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0);
        current_port++;
    }

    printf("\nScan completed!\n");
    return 0;
}