//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server started on port %d\n", PORT);

    int client_sockets[MAX_CLIENTS];
    int num_clients = 0;

    while (1) {
        int new_socket = accept(server_socket, NULL, NULL);
        if (new_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            close(new_socket);
            printf("Maximum number of clients reached\n");
            continue;
        }

        client_sockets[num_clients++] = new_socket;
        printf("Client connected\n");
    }

    return 0;
}