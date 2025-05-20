//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

// Function to scan a single port
void scan_port(int sockfd, int port) {
    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    target.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(sockfd, (struct sockaddr *)&target, sizeof(target));

    if (result == 0) {
        printf("Port %d is open.\n", port);
    } else {
        printf("Port %d is closed.\n", port);
    }
}

// Function to scan a range of ports
void scan_ports(int start_port, int end_port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    for (int i = start_port; i <= end_port; i++) {
        scan_port(sockfd, i);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./port_scanner <start_port> <end_port>\n");
        exit(1);
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port > end_port) {
        printf("Error: Start port cannot be greater than end port.\n");
        exit(1);
    }

    scan_ports(start_port, end_port);

    return 0;
}