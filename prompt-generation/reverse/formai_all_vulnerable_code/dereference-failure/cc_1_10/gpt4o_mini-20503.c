//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg);
void send_message_to_all(const char *message, int sender_socket);
void add_client(client_t *client);
void remove_client(int socket);
void clear_buffer(char *buffer, size_t size);

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
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

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        client_t *new_client = malloc(sizeof(client_t));
        new_client->socket = accept(server_socket, (struct sockaddr *)&new_client->address, &addr_len);
        if (new_client->socket < 0) {
            perror("Accept failed");
            free(new_client);
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(new_client->address.sin_addr), ntohs(new_client->address.sin_port));
        add_client(new_client);

        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, (void *)new_client);
    }

    close(server_socket);
    return 0;
}

void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    client_t *client = (client_t *)arg;
    int bytes_received;

    while ((bytes_received = recv(client->socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received from %s:%d: %s\n", inet_ntoa(client->address.sin_addr), ntohs(client->address.sin_port), buffer);
        send_message_to_all(buffer, client->socket);
    }

    printf("Client disconnected: %s:%d\n", inet_ntoa(client->address.sin_addr), ntohs(client->address.sin_port));
    remove_client(client->socket);
    close(client->socket);
    free(client);
    return NULL;
}

void send_message_to_all(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
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

void remove_client(int socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket == socket) {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}