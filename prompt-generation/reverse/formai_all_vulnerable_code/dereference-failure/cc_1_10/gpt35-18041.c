//FormAI DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_PORTS 65535
#define MAX_CONCURRENCY 50

int count_open;
int total_ports;
int current_port;
int concurrency;
struct sockaddr_in target;

void scan_port(int port) {
    int sockfd, status;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    // Set timeout for connect
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv) < 0) {
        perror("Failed to set timeout");
        exit(1);
    }

    target.sin_port = htons(port);
    status = connect(sockfd, (struct sockaddr*)&target, sizeof(target));
    if (status < 0) {
        close(sockfd);
    } else {
        printf("Port %d is open.\n", port);
        count_open++;
        close(sockfd);
    }
}

int main(int argc, char* argv[]) {
    int i, j;

    if (argc != 3) {
        printf("Usage: %s <ip> <concurrency>\n", argv[0]);
        exit(1);
    }

    int ip_len = strlen(argv[1]);
    char ip[ip_len + 1];
    strcpy(ip, argv[1]);

    if (!inet_aton(ip, &target.sin_addr)) {
        printf("Invalid IP address.\n");
        exit(1);
    }

    concurrency = atoi(argv[2]);
    if (concurrency <= 0 || concurrency > MAX_CONCURRENCY) {
        printf("Concurrency value must be between 1 and %d.\n", MAX_CONCURRENCY);
        exit(1);
    }

    count_open = 0;
    total_ports = MAX_PORTS;
    current_port = 1;

    printf("Scanning port range 1-%d with concurrency %d...\n", MAX_PORTS, concurrency);
    clock_t begin = clock();

    while (current_port <= total_ports) {
        for (i = 0; i < concurrency; i++) {
            if (current_port > total_ports) {
                break;
            }
            int pid = fork();
            if (pid < 0) {
                perror("Failed to create child process");
            }
            if (pid == 0) {
                scan_port(current_port);
                exit(0);
            }
            current_port++;
        }
        // Wait for all child processes to complete
        for (j = 0; j < concurrency && current_port <= total_ports; j++) {
            wait(NULL);
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Scan complete. %d open ports found in %.2f seconds.\n", count_open, time_spent);

    return 0;
}