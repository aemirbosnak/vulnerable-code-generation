//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

// Structure to hold client details
typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

int client_count = 0;
client_t *clients[MAX_CLIENTS];

void *handle_client(void *arg) {
    client_t *cli = (client_t *)arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        int bytes_received = recv(cli->socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            printf("Client disconnected: %d\n", cli->socket);
            close(cli->socket);
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Client %d: %s", cli->socket, buffer);

        // Echo message back to the client
        send(cli->socket, buffer, bytes_received, 0);
    }

    free(cli);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (client_count < MAX_CLIENTS) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Client connected: %d\n", client_socket);
        client_t *cli = malloc(sizeof(client_t));
        cli->socket = client_socket;
        cli->address = client_addr;
        clients[client_count++] = cli;

        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, cli);
        pthread_detach(tid);
    }

    close(server_socket);
    return 0;
}