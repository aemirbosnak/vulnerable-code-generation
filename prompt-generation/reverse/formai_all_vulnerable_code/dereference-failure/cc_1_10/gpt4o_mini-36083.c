//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
    free(arg);

    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null terminate the string
        printf("Client: %s\n", buffer);
        
        // Broadcast message to all clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] != 0 && clients[i] != client_socket) {
                send(clients[i], buffer, bytes_read, 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    close(client_socket);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == client_socket) {
            clients[i] = 0; // Remove client
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    return NULL;
}

int main() {
    // Initialize clients array
    memset(clients, 0, sizeof(clients));

    int server_socket, *new_sock;
    struct sockaddr_in server_address, client_address;
    socklen_t client_addr_length = sizeof(client_address);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Could not create socket");
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        return 1;
    }

    // Listen
    listen(server_socket, MAX_CLIENTS);
    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_addr_length);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Client connected: %d\n", client_socket);

        // Add new client to array
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == 0) {
                clients[i] = client_socket;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        // Create a new thread for the client
        pthread_t thread;
        new_sock = malloc(1);
        *new_sock = client_socket;
        if (pthread_create(&thread, NULL, handle_client, new_sock) != 0) {
            perror("Could not create thread");
            free(new_sock);
        }
    }

    close(server_socket);
    return 0;
}