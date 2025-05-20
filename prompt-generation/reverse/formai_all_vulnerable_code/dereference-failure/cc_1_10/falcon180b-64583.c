//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535

void scan_ports(int ip, int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(ip);
    server.sin_port = htons(start_port);

    for (int i = start_port; i <= end_port; i++) {
        connect(sock, (struct sockaddr *) &server, sizeof(server));
        if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
            printf("Port %d is open\n", i);
        } else {
            printf("Port %d is closed\n", i);
        }
        close(sock);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./portscanner <IP Address> <Start Port> <End Port>\n");
        return 1;
    }

    int ip = inet_addr(argv[1]);
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (ip == INADDR_NONE) {
        printf("Invalid IP Address\n");
        return 1;
    }

    if (start_port > end_port || start_port < 1 || end_port > MAX_PORTS) {
        printf("Invalid port range\n");
        return 1;
    }

    scan_ports(ip, start_port, end_port);

    return 0;
}