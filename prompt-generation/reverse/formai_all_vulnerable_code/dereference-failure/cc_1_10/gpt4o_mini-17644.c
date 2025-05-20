//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SERVER_IP "127.0.0.1"  // Configurable: Server IP
#define SERVER_PORT 8080        // Configurable: Server port
#define MAX_CLIENTS 10          // Configurable: Max clients allowed
#define BUFFER_SIZE 256         // Configurable: Buffer size for messages

typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void broadcast_message(char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    
    while ((bytes_received = recv(client->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the string
        printf("Client %d: %s", client->socket, buffer);
        broadcast_message(buffer, client->socket);
    }

    close(client->socket);
    free(client);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(client_addr);
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed:");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);
    
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed:");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed:");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on %s:%d...\n", SERVER_IP, SERVER_PORT);

    while (1) {
        client_t *client = (client_t *)malloc(sizeof(client_t));
        client->socket = accept(server_socket, (struct sockaddr *)&client->address, &addr_size);
        if (client->socket < 0) {
            perror("Accept failed:");
            free(client);
            continue;
        }

        // Lock and add to clients list
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (!clients[i]) {
                clients[i] = client;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        printf("Client connected: %d\n", client->socket);
        
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, client) != 0) {
            perror("Thread creation failed:");
            free(client);
        }
        
        // Detach thread, so we don't need to join later
        pthread_detach(tid);
    }

    close(server_socket);
    return 0;
}