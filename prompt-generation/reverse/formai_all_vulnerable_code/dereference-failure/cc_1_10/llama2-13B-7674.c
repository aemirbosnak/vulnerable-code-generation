//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_IP_LEN 15
#define MAX_PORTS 1024

struct port_info {
    int port;
    char *ip;
};

void scan_ports(int start_port, int end_port, char *ip_range) {
    struct sockaddr_in server_addr;
    socklen_t server_len = sizeof(server_addr);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    int port = start_port;

    while (port <= end_port) {
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, ip_range, &server_addr.sin_addr);

        if (connect(sock, (struct sockaddr *)&server_addr, server_len) == 0) {
            printf("Found open port %d on %s\n", port, inet_ntoa(server_addr.sin_addr));
        } else {
            printf("Port %d on %s is closed\n", port, inet_ntoa(server_addr.sin_addr));
        }

        port++;
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <start_port> <end_port> <ip_range>\n", argv[0]);
        return 1;
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);
    char *ip_range = argv[3];

    scan_ports(start_port, end_port, ip_range);

    return 0;
}