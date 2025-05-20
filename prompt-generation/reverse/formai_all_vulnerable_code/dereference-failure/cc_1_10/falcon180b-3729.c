//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define PORT 8080
#define BACKLOG 5

// Function to handle client connections
void handle_client(int client_socket) {
    char buffer[1024];
    while (1) {
        memset(buffer, 0, 1024);
        int bytes_received = recv(client_socket, buffer, 1024, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Client %d sent: %s\n", client_socket, buffer);
        send(client_socket, buffer, strlen(buffer), 0);
    }
    close(client_socket);
}

// Function to handle multiple client connections
void handle_clients(int server_socket) {
    struct sockaddr_in client_addr;
    socklen_t client_size = sizeof(client_addr);
    while (1) {
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_size);
        if (client_socket == -1) {
            printf("Error accepting client connection: %s\n", strerror(errno));
            continue;
        }
        printf("Client %d connected\n", client_socket);
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *)handle_client, (void *)client_socket);
    }
}

// Function to start the server
void start_server() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(server_socket, BACKLOG) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server started on port %d\n", PORT);
    handle_clients(server_socket);
}

int main() {
    start_server();
    return 0;
}