//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <proxy_port> <destination_ip>\n", argv[0]);
        return 1;
    }

    int proxy_port = atoi(argv[1]);
    char *destination_ip = argv[2];

    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(proxy_port);
    proxy_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(proxy_socket, 5) == -1) {
        perror("listen");
        return 1;
    }

    printf("Proxy server listening on port %d\n", proxy_port);

    while (1) {
        int client_socket = accept(proxy_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        char buffer[BUFFER_SIZE];
        int bytes_received = 0;

        while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            send(client_socket, buffer, bytes_received, 0);
        }

        close(client_socket);
    }

    return 0;
}