//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

void scan_ports(int sock, struct sockaddr_in *server, int port_min, int port_max);

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <IP Address> <Port Min> <Port Max>\n", argv[0]);
        return -1;
    }

    char *ip_address = argv[1];
    int port_min = atoi(argv[2]);
    int port_max = atoi(argv[3]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_port = htons(port_min);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return -1;
    }

    scan_ports(sock, &server, port_min, port_max);

    close(sock);
    return 0;
}

void scan_ports(int sock, struct sockaddr_in *server, int port_min, int port_max) {
    for (int i = port_min; i <= port_max; i++) {
        server->sin_port = htons(i);

        if (connect(sock, (struct sockaddr *)server, sizeof(*server)) == 0) {
            printf("Port %d is open\n", i);
        } else {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed\n", i);
            } else {
                printf("Error connecting to port %d\n", i);
            }
        }
    }
}