//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void error_handling(char *message) {
    perror(message);
    exit(1);
}

void scan_ports(int sockfd, int target_ip, int start_port, int end_port) {
    int port;
    for (port = start_port; port <= end_port; port++) {
        if (connect(sockfd, (struct sockaddr*)&target_ip, sizeof(target_ip)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage:./port_scanner <target_ip> <start_port> <end_port>\n");
        exit(1);
    }

    int target_ip = inet_addr(argv[1]);
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (target_ip == INADDR_NONE) {
        error_handling("Invalid IP address");
    }

    if (start_port > end_port) {
        error_handling("Invalid port range");
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("Error creating socket");
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    scan_ports(sockfd, target_ip, start_port, end_port);

    close(sockfd);
    return 0;
}