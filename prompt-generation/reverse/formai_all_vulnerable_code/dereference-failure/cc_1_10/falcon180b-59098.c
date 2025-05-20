//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    if (argc!= 3) {
        printf("Usage: %s <port> <ip>\n", argv[0]);
        return 1;
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(listen_socket, 5) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        while (1) {
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received == 0) {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            } else if (bytes_received == -1) {
                printf("Error receiving data\n");
                close(client_socket);
                break;
            }

            send(client_socket, buffer, bytes_received, 0);
        }
    }

    close(listen_socket);
    return 0;
}