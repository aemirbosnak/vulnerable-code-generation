//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 12345
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 256
#define MAX_NAME_SIZE 50

typedef struct {
    int socket;
    char name[MAX_NAME_SIZE];
} client_t;

client_t *clients[MAX_CONNECTIONS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void broadcast_message(const char *message, int exclude_sock) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (clients[i] != NULL && clients[i]->socket != exclude_sock) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE + MAX_NAME_SIZE];

    // Welcome the new knight to the realm
    snprintf(message, sizeof(message), "%s hath joined the chat.\n", client->name);
    broadcast_message(message, client->socket);

    while (1) {
        int recv_result = recv(client->socket, buffer, sizeof(buffer), 0);
        if (recv_result <= 0) {
            break;  // knight disconnected
        }
        buffer[recv_result] = '\0';

        // Create message to broadcast
        snprintf(message, sizeof(message), "%s: %s", client->name, buffer);
        broadcast_message(message, client->socket);
    }

    // Farewell the knight
    snprintf(message, sizeof(message), "%s hath left the chat.\n", client->name);
    broadcast_message(message, client->socket);

    close(client->socket);
    free(client);
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addrlen = sizeof(client_addr);
    pthread_t thread;

    // Enkindle the server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Unable to create socket");
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("Listening failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    printf("The Grand Chat Chamber is now open on port %d!\n", PORT);

    while (1) {
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (new_socket < 0) {
            perror("Connection failed");
            continue;
        }

        client_t *new_client = malloc(sizeof(client_t));
        new_client->socket = new_socket;

        // Request a name from the new knight
        send(new_socket, "What be thy name, noble soul? ", 32, 0);
        recv(new_socket, new_client->name, sizeof(new_client->name), 0);
        new_client->name[strcspn(new_client->name, "\n")] = 0; // Remove newline character

        // Add knight to the roster
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CONNECTIONS; i++) {
            if (clients[i] == NULL) {
                clients[i] = new_client;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        // Spawn a thread for the newly arrived knight to handle messages
        if (pthread_create(&thread, NULL, handle_client, (void *)new_client) != 0) {
            perror("Could not create thread");
            free(new_client);
        }
        pthread_detach(thread); // We don't need to join later
    }

    close(server_socket);
    return EXIT_SUCCESS;
}