//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

void *client_handler(void *);

int clients[MAX_CLIENTS];
int client_count = 0;

pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;

void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] != sender_socket) {
            send(clients[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&client_mutex);
}

void *client_handler(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[read_size] = '\0';  // Null-terminate string
        printf("Received: %s\n", buffer);
        broadcast_message(buffer, sock);
    }

    // Remove client from clients array
    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] == sock) {
            clients[i] = clients[client_count - 1]; // Move last client to this position
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&client_mutex);
    
    close(sock);
    free(client_socket);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    printf("Chat server listening on port %d...\n", PORT);
    
    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        pthread_mutex_lock(&client_mutex);
        if (client_count >= MAX_CLIENTS) {
            printf("Maximum clients reached. Connection rejected.\n");
            close(new_socket);
            pthread_mutex_unlock(&client_mutex);
            continue;
        }
        clients[client_count++] = new_socket;
        pthread_mutex_unlock(&client_mutex);

        pthread_t thread_id;
        int *new_sock = malloc(1);
        *new_sock = new_socket;
        if (pthread_create(&thread_id, NULL, client_handler, (void *)new_sock) != 0) {
            perror("Could not create thread");
            free(new_sock);
        }
        pthread_detach(thread_id);
    }

    return 0;
}