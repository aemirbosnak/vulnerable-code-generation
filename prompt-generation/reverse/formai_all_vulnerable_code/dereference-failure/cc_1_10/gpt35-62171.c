//FormAI DATASET v1.0 Category: Port Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535

void print_usage(char *program_name);
void scan_ports(char *target_ip, int start_port, int end_port);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    char *target_ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > MAX_PORT) {
        fprintf(stderr, "Invalid port range\n");
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Scanning ports %d to %d on target %s...\n", start_port, end_port, target_ip);

    scan_ports(target_ip, start_port, end_port);

    printf("Scan complete.\n");

    return 0;
}

void print_usage(char *program_name) {
    printf("Usage: %s <target_ip> <start_port> <end_port>\n", program_name);
}

void scan_ports(char *target_ip, int start_port, int end_port) {
    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(target_ip);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    for (int port = start_port; port <= end_port; port++) {
        target_addr.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d: open\n", port);
        }
    }

    close(sock);
}