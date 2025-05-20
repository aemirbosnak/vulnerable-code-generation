//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void *client_handler(void *socket_desc);

int clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex;

int main() {
    int server_socket, new_socket, *new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Could not create socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        return 1;
    }

    listen(server_socket, 3);
    printf("Listening on port %d...\n", PORT);

    pthread_mutex_init(&clients_mutex, NULL);

    while ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len))) {
        pthread_mutex_lock(&clients_mutex);
        clients[client_count++] = new_socket;
        pthread_mutex_unlock(&clients_mutex);

        pthread_t client_thread;
        new_sock = malloc(1);
        *new_sock = new_socket;

        if (pthread_create(&client_thread, NULL, client_handler, (void *)new_sock) < 0) {
            perror("Could not create thread");
            return 1;
        }

        printf("Client connected: %d\n", new_socket);
    }

    if (new_socket < 0) {
        perror("Accept failed");
        return 1;
    }

    close(server_socket);
    return 0;
}

void *client_handler(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Client %d: %s", sock, buffer);
        // Send the message to all clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < client_count; ++i) {
            if (clients[i] != sock) {
                send(clients[i], buffer, read_size, 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    if (read_size == 0) {
        printf("Client disconnected: %d\n", sock);
    } else if (read_size == -1) {
        perror("recv failed");
    }

    close(sock);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; ++i) {
        if (clients[i] == sock) {
            clients[i] = clients[client_count - 1];
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    free(socket_desc);
    return 0;
}