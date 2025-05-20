//FormAI DATASET v1.0 Category: Port Scanner ; Style: Linus Torvalds
/*
 * C Port Scanner
 * Written in the style of Linus Torvalds
 *
 * This program scans a specified host for open TCP ports
 * and reports which ports are open.
 *
 * Usage:
 * ./portscanner <host> <start_port> <end_port>
 *
 * Example:
 * ./portscanner localhost 1 1024
 *
 * Author: [Your Name Here]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>

#define MAX_PORT 65535
#define BUFFER_SIZE 1024

void usage(char *name) {
    printf("Usage: %s <host> <start_port> <end_port>\n", name);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        usage(argv[0]);
    }

    struct sockaddr_in target;
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > MAX_PORT) {
        printf("Invalid port range (1-%d)\n", MAX_PORT);
        exit(1);
    }

    int sockfd;
    int i = start_port;
    char buffer[BUFFER_SIZE];

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    inet_pton(AF_INET, host, &target.sin_addr);

    printf("Scanning %s ports %d-%d\n", host, start_port, end_port);

    for (i = start_port; i <= end_port; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
        target.sin_port = htons(i);
        if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) < 0) {
            /* Port is closed */
            close(sockfd);
            continue;
        }
        /* Port is open */
        printf("Port %d is open.\n", i);
        close(sockfd);
    }

    printf("Scan complete.\n");

    return 0;
}