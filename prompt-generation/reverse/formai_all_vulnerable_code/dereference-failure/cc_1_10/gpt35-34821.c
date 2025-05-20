//FormAI DATASET v1.0 Category: Port Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void scan_port(char *ip, int port);

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: %s <target IP> <port range>\n", argv[0]);
        printf("Example: %s 192.168.0.1 1-1000\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip = argv[1];
    char *port_range = argv[2];

    char *ptr = strtok(port_range, "-");
    int start_port = atoi(ptr);
    ptr = strtok(NULL, "-");
    int end_port = atoi(ptr);

    printf("Scanning host %s for open ports in range %d-%d\n", ip, start_port, end_port);

    for(int port = start_port; port <= end_port; ++port) {
        scan_port(ip, port);
    }

    printf("Scan complete\n");
    return 0;
}

void scan_port(char *ip, int port) {
    int sockfd, rc;
    struct sockaddr_in target_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(port);
    rc = inet_pton(AF_INET, ip, &(target_addr.sin_addr));
    if(rc <= 0) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }

    rc = connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr));
    if(rc < 0) {
        close(sockfd);
        return;
    }

    printf("Port %d open\n", port);
    close(sockfd);
}