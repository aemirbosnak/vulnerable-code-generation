//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535

#define CHECK_PORT(port) (port > 0 && port <= 65535)

int main(int argc, char *argv[]) {
    int port;
    char *host;
    int sock;

    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);

    if (!CHECK_PORT(port)) {
        printf("Invalid port number.\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Failed to create socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to connect: %s\n", strerror(errno));
        close(sock);
        exit(1);
    }

    close(sock);

    printf("Port %d is open.\n", port);

    return 0;
}