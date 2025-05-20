//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
    int proxy_socket, client_socket, server_socket;
    struct sockaddr_in proxy_addr, client_addr, server_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <proxy_port> <server_addr>\n", argv[0]);
        return 1;
    }

    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);

    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(atoi(argv[1]));
    proxy_addr.sin_addr.s_addr = INADDR_ANY;

    bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr));

    listen(proxy_socket, 5);

    while (1) {
        client_socket = accept(proxy_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(8080);
        server_addr.sin_addr.s_addr = inet_addr(argv[2]);

        server_socket = socket(AF_INET, SOCK_STREAM, 0);

        connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

        while ((recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            send(server_socket, buffer, strlen(buffer), 0);
        }

        close(server_socket);
        close(client_socket);
    }

    return 0;
}