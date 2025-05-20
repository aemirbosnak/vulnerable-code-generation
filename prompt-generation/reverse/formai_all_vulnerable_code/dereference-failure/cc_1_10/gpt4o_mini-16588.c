//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    client_t *client = (client_t *)arg;
    int bytes_read;

    while ((bytes_read = read(client->socket, buffer, sizeof(buffer)-1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Received: %s", buffer);

        // Broadcast the message to all clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] != NULL && clients[i]->socket != client->socket) {
                write(clients[i]->socket, buffer, bytes_read);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Cleanup client
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == client) {
            clients[i] = NULL;  // Remove client from the list
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    free(client);
    return NULL;
}

void add_client(client_t *client) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == NULL) {
            clients[i] = client;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

int main() {
    int server_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len = sizeof(client_address);
    pthread_t tid;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for clients
    if (listen(server_socket, 3) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        client_t *new_client = malloc(sizeof(client_t));
        new_client->socket = accept(server_socket, (struct sockaddr *)&new_client->address, &client_len);
        if (new_client->socket < 0) {
            perror("Accept failed");
            free(new_client);
            continue;
        }

        printf("Client connected from %s:%d\n", inet_ntoa(new_client->address.sin_addr), ntohs(new_client->address.sin_port));
        add_client(new_client);
        pthread_create(&tid, NULL, handle_client, (void *)new_client);
        pthread_detach(tid); // Automatically reclaim memory when thread exits
    }

    close(server_socket);
    return 0;
}