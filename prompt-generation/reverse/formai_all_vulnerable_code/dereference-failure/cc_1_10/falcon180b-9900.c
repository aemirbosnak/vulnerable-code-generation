//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./port_scanner <IP Address> <Start Port> <End Port>\n");
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Invalid port range!\n");
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

    char buffer[BUFFER_SIZE];
    int bytes_received;

    for (int port = start_port; port <= end_port; port++) {
        server_addr.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open!\n", port);
            close(sock);
            sock = socket(AF_INET, SOCK_STREAM, 0);
        } else {
            printf("Port %d is closed.\n", port);
        }
    }

    close(sock);
    return 0;
}