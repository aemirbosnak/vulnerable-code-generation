//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535

void scan_ports(int sock, struct sockaddr_in *server, int start_port, int end_port) {
    int port;
    for (port = start_port; port <= end_port; port++) {
        if (connect(sock, (struct sockaddr *)server, sizeof(struct sockaddr)) == -1) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Port %d is open\n", port);
            close(sock);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./port_scanner <IP address> <start port> <end port>\n");
        return 1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[3]));

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Invalid port range\n");
        close(sock);
        return 1;
    }

    scan_ports(sock, &server, start_port, end_port);

    close(sock);
    return 0;
}