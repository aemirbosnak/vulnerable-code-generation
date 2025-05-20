//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 4096
#define LISTEN_PORT 8080
#define TARGET_HOST "127.0.0.1"
#define TARGET_PORT 80

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in listen_addr, client_addr;
    socklen_t client_addr_size;
    char buffer[BUF_SIZE];
    int bytes_received, bytes_sent;

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(LISTEN_PORT);

    if (bind(listen_socket, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        return 1;
    }

    if (listen(listen_socket, 5) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        return 1;
    }

    printf("HTTP proxy listening on port %d\n", LISTEN_PORT);

    while (1) {
        client_addr_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);
            if (bytes_received <= 0) {
                printf("Client disconnected\n");
                break;
            }

            printf("Received %d bytes from client\n", bytes_received);

            bytes_sent = send(client_socket, buffer, bytes_received, 0);
            if (bytes_sent <= 0) {
                printf("Error sending data to client: %s\n", strerror(errno));
                break;
            }
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}