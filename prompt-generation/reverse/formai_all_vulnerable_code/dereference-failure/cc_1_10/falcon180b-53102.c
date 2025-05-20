//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *ip;
    int port;
    int i, num_open_ports = 0;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage:./port_scanner <IP Address> <Port Range>\n");
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    for (i = 1; i <= MAX_PORTS; i++) {
        if (i!= port) {
            server.sin_port = htons(i);
            if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
                num_open_ports++;
                printf("Port %d is open\n", i);
            } else if (errno == ECONNREFUSED) {
                printf("Port %d is closed\n", i);
            } else {
                printf("Error connecting to port %d\n", i);
            }
        }
    }

    close(sock);

    printf("Total number of open ports: %d\n", num_open_ports);

    return 0;
}