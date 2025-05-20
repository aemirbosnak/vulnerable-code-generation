//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc, char **argv) {
    int port;
    char *ip;
    int sock;
    struct sockaddr_in server;
    struct hostent *host;
    int i;
    int num_ports;
    int *ports;

    if (argc < 3) {
        printf("Usage: %s <ip> <port1> [<port2>...]\n", argv[0]);
        return 1;
    }

    ip = argv[1];
    port = atoi(argv[2]);
    num_ports = 1;

    if (argc > 3) {
        num_ports = atoi(argv[3]);
    }

    ports = malloc(num_ports * sizeof(int));

    for (i = 0; i < num_ports; i++) {
        ports[i] = port + i;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    host = gethostbyname(ip);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        close(sock);
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(ports[0]);
    memcpy(&server.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to %s:%d\n", ip, ports[0]);
        close(sock);
        return 1;
    }

    for (i = 1; i < num_ports; i++) {
        server.sin_port = htons(ports[i]);
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", ports[i]);
        } else {
            printf("Port %d is closed\n", ports[i]);
        }
    }

    close(sock);
    return 0;
}