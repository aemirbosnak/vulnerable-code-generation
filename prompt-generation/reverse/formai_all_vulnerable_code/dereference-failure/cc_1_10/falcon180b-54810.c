//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage:./port_scanner <IP Address> <Start Port> <End Port>\n");
    exit(1);
}

int is_valid_port(int port) {
    if (port <= 0 || port > MAX_PORTS) {
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage();
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (!is_valid_port(start_port) ||!is_valid_port(end_port)) {
        printf("Invalid port range\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    for (int i = start_port; i <= end_port; i++) {
        server_addr.sin_port = htons(i);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            close(sock);
            printf("Port %d is open\n", i);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", i);
        } else {
            printf("Error on port %d: %s\n", i, strerror(errno));
        }
    }

    close(sock);
    return 0;
}