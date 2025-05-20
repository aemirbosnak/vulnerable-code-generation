//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_RANGE_MAX 65535

void port_scanner(int sock, int start_port, int end_port)
{
    int port;
    for (port = start_port; port <= end_port; port++) {
        if (port == start_port) {
            printf("Scanning port %d...\n", port);
        }
        int addrlen = sizeof(struct sockaddr_in);
        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(struct sockaddr_in));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

        int result = connect(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in));
        if (result == 0) {
            printf("Port %d is open.\n", port);
        } else {
            printf("Port %d is closed.\n", port);
        }
    }
}

int main(int argc, char *argv[])
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port > end_port) {
        printf("Invalid port range.\n");
        exit(1);
    }

    if (start_port < 1 || start_port > PORT_RANGE_MAX) {
        printf("Invalid start port.\n");
        exit(1);
    }

    if (end_port < 1 || end_port > PORT_RANGE_MAX) {
        printf("Invalid end port.\n");
        exit(1);
    }

    port_scanner(sock, start_port, end_port);

    close(sock);
    return 0;
}