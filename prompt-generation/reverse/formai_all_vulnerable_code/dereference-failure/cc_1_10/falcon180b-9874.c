//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv) {
    int proxy_socket, client_socket, server_socket;
    struct sockaddr_in proxy_addr, client_addr, server_addr;
    char buffer[BUFF_SIZE];

    if (argc!= 3) {
        printf("Usage:./proxy <proxy_port> <server_port>\n");
        exit(1);
    }

    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);

    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(atoi(argv[1]));
    proxy_addr.sin_addr.s_addr = INADDR_ANY;

    bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr));
    listen(proxy_socket, 5);

    printf("Proxy listening on port %s\n", argv[1]);

    while (1) {
        client_socket = accept(proxy_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(atoi(argv[2]));
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        server_socket = socket(AF_INET, SOCK_STREAM, 0);
        connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

        while (1) {
            bzero(buffer, BUFF_SIZE);
            recv(client_socket, buffer, BUFF_SIZE, 0);

            send(server_socket, buffer, strlen(buffer), 0);

            bzero(buffer, BUFF_SIZE);
            recv(server_socket, buffer, BUFF_SIZE, 0);

            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
        close(server_socket);
    }

    return 0;
}