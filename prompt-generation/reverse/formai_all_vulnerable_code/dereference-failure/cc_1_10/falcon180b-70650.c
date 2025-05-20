//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    int port;
    char ip[1024];
    char *host;
    int num_ports;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Number of Ports>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    num_ports = atoi(argv[2]);

    if (num_ports > MAX_PORTS) {
        printf("Error: Number of ports must be less than or equal to 65535.\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(0);
    inet_pton(AF_INET, host, &server.sin_addr);

    for (port = 1; port <= num_ports; port++) {
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open.\n", port);
        } else {
            printf("Port %d is closed.\n", port);
        }
    }

    close(sock);
    return 0;
}