//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535

void scan_ports(int sockfd, char *ip_address, int start_port, int end_port) {
    int i;
    char buffer[1024];
    struct sockaddr_in addr;
    int addr_size = sizeof(addr);

    for (i = start_port; i <= end_port; i++) {
        addr.sin_family = AF_INET;
        addr.sin_port = htons(i);
        addr.sin_addr.s_addr = inet_addr(ip_address);

        if (connect(sockfd, (struct sockaddr *)&addr, addr_size) == 0) {
            printf("Port %d is open\n", i);
        } else {
            printf("Port %d is closed\n", i);
        }
    }
}

int main(int argc, char *argv[]) {
    int sockfd;
    char ip_address[16];
    int start_port, end_port;

    if (argc!= 5) {
        printf("Usage:./port_scanner <ip_address> <start_port> <end_port>\n");
        return 1;
    }

    strcpy(ip_address, argv[1]);
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Invalid port range\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    scan_ports(sockfd, ip_address, start_port, end_port);

    close(sockfd);

    return 0;
}