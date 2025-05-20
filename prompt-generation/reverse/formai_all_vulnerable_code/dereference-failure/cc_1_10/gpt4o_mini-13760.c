//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg);
void send_message_to_all(const char *message, int sender_socket);

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("[SERVER] Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("[SERVER] Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("[SERVER] Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("[SERVER] Waiting for connections...\n");

    while (1) {
        new_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len);
        if (new_socket < 0) {
            perror("[SERVER] Accept failed");
            continue;
        }

        printf("[SERVER] New connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        client_t *client = malloc(sizeof(client_t));
        client->socket = new_socket;
        client->address = client_address;

        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (!clients[i]) {
                clients[i] = client;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, client) != 0) {
            perror("[SERVER] Error creating thread");
            free(client);
        }
    }
    
    return 0;
}

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(client->socket, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("[CLIENT %d] %s", client->socket, buffer);
        send_message_to_all(buffer, client->socket);
    }

    if (bytes_read <= 0) {
        printf("[SERVER] Client %d disconnected\n", client->socket);
        close(client->socket);
        free(client);
    }

    return NULL;
}

void send_message_to_all(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket != sender_socket) {
            write(clients[i]->socket, message, strlen(message));
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}