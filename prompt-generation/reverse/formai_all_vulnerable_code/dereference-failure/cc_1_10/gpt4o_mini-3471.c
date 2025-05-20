//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *client_handler(void *arg);
void broadcast_message(char *message, int current_client);

int main() {
    int server_fd, new_socket, *new_sock;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
            perror("Accept failed");
            close(server_fd);
            exit(EXIT_FAILURE);
        }

        printf("New client connected\n");

        pthread_mutex_lock(&clients_mutex);
        clients[client_count++] = new_socket;
        pthread_mutex_unlock(&clients_mutex);

        pthread_t tid;
        new_sock = malloc(1);
        *new_sock = new_socket;
        if (pthread_create(&tid, NULL, client_handler, (void *)new_sock) != 0) {
            perror("Thread creation failed");
        }
    }

    close(server_fd);
    return 0;
}

void *client_handler(void *arg) {
    int sock = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int valread;

    while ((valread = read(sock, buffer, BUFFER_SIZE-1)) > 0) {
        buffer[valread] = '\0';
        printf("Message from client: %s\n", buffer);
        broadcast_message(buffer, sock);
    }

    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] == sock) {
            clients[i] = clients[--client_count];
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    close(sock);
    printf("Client disconnected\n");
    free(arg);
    return NULL;
}

void broadcast_message(char *message, int current_client) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] != current_client) {
            send(clients[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}