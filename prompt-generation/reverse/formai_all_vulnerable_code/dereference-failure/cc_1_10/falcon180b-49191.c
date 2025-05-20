//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_CLIENTS 20
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int num_clients = 0;
int max_clients = 0;

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            close(client_socket);
            printf("Client disconnected\n");
            pthread_exit(0);
        }

        printf("Client sent: %s\n", buffer);
    }
}

void accept_connections(int server_socket) {
    while (num_clients < max_clients) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_len);

        if (client_socket < 0) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        client_sockets[num_clients] = client_socket;
        num_clients++;

        printf("Client connected\n");
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket: %s\n", strerror(errno));
        return 2;
    }

    if (listen(server_socket, BACKLOG) < 0) {
        printf("Error listening on socket: %s\n", strerror(errno));
        return 3;
    }

    printf("Server started on port %d\n", PORT);

    accept_connections(server_socket);

    return 0;
}