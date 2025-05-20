//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int port, sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    char *host;

    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    host = argv[1];
    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        return 1;
    }

    printf("Connected to %s:%d\n", host, port);

    for (int i = 1; i <= MAX_PORTS; i++) {
        if (i!= port) {
            send(sock, "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n", 80, 0);
        }
    }

    close(sock);

    return 0;
}