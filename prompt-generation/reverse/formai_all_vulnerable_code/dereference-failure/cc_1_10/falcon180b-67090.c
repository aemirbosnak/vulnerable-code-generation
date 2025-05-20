//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUF_SIZE 1024

void print_usage() {
    printf("Usage:./port_scanner <IP_Address> <Start_Port> <End_Port>\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage();
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Invalid port range\n");
        return 1;
    }

    int max_fd;
    struct sockaddr_in server;
    int opt = 1;
    char buffer[BUF_SIZE];
    fd_set master_fds, read_fds;

    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);

    for (int i = start_port; i <= end_port; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error creating socket\n");
            return 1;
        }

        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr(ip_address);
        server.sin_port = htons(i);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", i);
            close(sock);
        } else {
            printf("Port %d is closed\n", i);
            close(sock);
        }
    }

    return 0;
}