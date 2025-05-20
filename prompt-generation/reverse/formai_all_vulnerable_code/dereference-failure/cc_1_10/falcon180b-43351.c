//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./port_scanner <ip_address> <port_range>\n");
        exit(1);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS - 1;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(start_port);

    int status = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (status == -1) {
        printf("Connection failed\n");
        close(sock);
        exit(1);
    }

    printf("Scanning ports from %d to %d\n", start_port, end_port);

    for (int port = start_port; port <= end_port; port++) {
        server_addr.sin_port = htons(port);

        status = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

        if (status == 0) {
            printf("Port %d is open\n", port);
            close(sock);
            exit(0);
        } else {
            if (errno!= ECONNREFUSED) {
                printf("Error connecting to port %d: %s\n", port, strerror(errno));
                close(sock);
                exit(1);
            }
        }
    }

    printf("All ports are closed\n");
    close(sock);
    exit(0);
}