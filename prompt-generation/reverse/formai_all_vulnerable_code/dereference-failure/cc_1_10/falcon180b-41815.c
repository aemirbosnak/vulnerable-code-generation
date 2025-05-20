//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int scan_ports(int start_port, int end_port, char *ip_address);

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./port_scanner <start_port> <end_port> <ip_address>\n");
        return 1;
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);
    char *ip_address = argv[3];

    scan_ports(start_port, end_port, ip_address);

    return 0;
}

int scan_ports(int start_port, int end_port, char *ip_address) {
    int sockfd, port;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_address);

    for (port = start_port; port <= end_port; port++) {
        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
            snprintf(buffer, BUFFER_SIZE, "Port %d is open\n", port);
            write(1, buffer, strlen(buffer));
        } else {
            snprintf(buffer, BUFFER_SIZE, "Port %d is closed\n", port);
            write(1, buffer, strlen(buffer));
        }
    }

    close(sockfd);

    return 0;
}