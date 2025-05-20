//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PORT 65535

void usage(char *prog_name) {
    printf("Usage: %s <target_ip> <port_range_start> <port_range_end>\n", prog_name);
    printf("Example: %s 192.168.1.1 1 100\n", prog_name);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
    }

    char *target_ip = argv[1];
    int port_start = atoi(argv[2]);
    int port_end = atoi(argv[3]);

    if (port_start < 1 || port_start > MAX_PORT) {
        printf("Error: Invalid port range start %d\n", port_start);
        exit(EXIT_FAILURE);
    }

    if (port_end < 1 || port_end > MAX_PORT) {
        printf("Error: Invalid port range end %d\n", port_end);
        exit(EXIT_FAILURE);
    }

    if (port_start > port_end) {
        printf("Error: Port range start must be less than or equal to port range end\n");
        exit(EXIT_FAILURE);
    }

    int sockfd;
    struct sockaddr_in target_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: socket");
        exit(EXIT_FAILURE);
    }

    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(target_ip);
    target_addr.sin_port = htons(port_start);

    printf("Scanning ports %d to %d on %s\n", port_start, port_end, target_ip);

    for (int port = port_start; port <= port_end; port++) {
        target_addr.sin_port = htons(port);

        if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d is open\n", port);
        }
    }

    close(sockfd);

    return EXIT_SUCCESS;
}