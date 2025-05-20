//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT_RANGE 65535

// Function to check if a port is open
int is_port_open(char *ip, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    int ret = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));
    if (ret == 0) {
        close(sockfd);
        return 1;
    } else {
        close(sockfd);
        return 0;
    }
}

// Function to scan a range of ports
void scan_ports(char *ip, int start_port, int end_port) {
    for (int port = start_port; port <= end_port; port++) {
        if (is_port_open(ip, port)) {
            printf("Port %d is open\n", port);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <ip> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 0 || start_port > PORT_RANGE || end_port < 0 || end_port > PORT_RANGE) {
        printf("Invalid port range\n");
        return 1;
    }

    scan_ports(ip, start_port, end_port);

    return 0;
}