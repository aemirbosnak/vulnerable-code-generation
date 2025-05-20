//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int client_sockets[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    free(arg);
    char buffer[BUFFER_SIZE];

    while (1) {
        int read_size = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
        if (read_size <= 0) {
            break; // Client disconnected
        }
        buffer[read_size] = '\0'; // Null-terminate the received string

        printf("Client says: %s\n", buffer);

        // Broadcast message to all clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] != 0 && client_sockets[i] != client_socket) {
                send(client_sockets[i], buffer, read_size, 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    close(client_socket);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = 0; // Remove client socket
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Initialize client sockets array
    memset(client_sockets, 0, sizeof(client_sockets));

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d...\n", PORT);

    while (1) {
        // Accept a new client
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Find a free spot for the new client
        pthread_mutex_lock(&clients_mutex);
        int added = 0;
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = client_socket;
                added = 1;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        if (added) {
            printf("Client connected!\n");
            pthread_t tid;
            int *pclient = malloc(sizeof(int));
            *pclient = client_socket;
            // Create a new thread to handle the client
            if (pthread_create(&tid, NULL, handle_client, pclient) != 0) {
                perror("Thread creation failed");
                close(client_socket);
                free(pclient);
            }
        } else {
            printf("Max clients reached. Connection rejected.\n");
            close(client_socket);
        }
    }

    // Cleanup
    close(server_socket);
    return 0;
}