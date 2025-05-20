//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in listen_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int buffer_size;

    if (argc!= 2) {
        printf("Usage: %s [port]\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    listen_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_socket, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        printf("Error listening socket\n");
        exit(1);
    }

    printf("Proxy server started on port %d\n", atoi(argv[1]));

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        buffer_size = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (buffer_size <= 0) {
            printf("Error receiving data\n");
            close(client_socket);
            continue;
        }

        send(client_socket, buffer, buffer_size, 0);
        close(client_socket);
    }

    return 0;
}