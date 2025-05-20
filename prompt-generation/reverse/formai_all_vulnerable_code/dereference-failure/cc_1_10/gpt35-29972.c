//FormAI DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        exit(0);
    }

    int start_port = atoi(argv[2]), end_port = atoi(argv[2]);
    if (start_port < 0 || end_port < start_port || end_port > 65535) {
        printf("Invalid port range.\n");
        exit(0);
    }

    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;

    if (inet_pton(AF_INET, argv[1], &target_addr.sin_addr) <= 0) {
        printf("Invalid IP address.\n");
        exit(0);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    printf("Scanning...\n");

    int success_count = 0;
    for (int port = start_port; port <= end_port; ++port) {
        target_addr.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            printf("%d open\n", port);
            success_count++;
        }
    }

    if (success_count == 0) {
        printf("No open ports found.\n");
    }

    close(sock);
    return 0;
}