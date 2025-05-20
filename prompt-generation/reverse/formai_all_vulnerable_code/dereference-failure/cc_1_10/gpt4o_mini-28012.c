//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *arg);
void broadcast_message(const char *message, int sender_socket);
void remove_client(int socket);

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t tid;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Socket creation error\n");
        return 1;
    }

    // Set server address properties
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Bind failed\n");
        return 1;
    }

    // Start listening for connections
    if (listen(server_socket, 3) < 0) {
        fprintf(stderr, "Listen failed\n");
        return 1;
    }

    printf("Chat server started on port %d. Waiting for clients...\n", PORT);

    // Accept clients
    while ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len))) {
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = new_socket;
            printf("New client connected, socket: %d\n", new_socket);

            pthread_create(&tid, NULL, handle_client, (void *)&new_socket);
        } else {
            printf("Maximum clients reached. Connection refused for socket: %d\n", new_socket);
            close(new_socket);
        }
    }

    close(server_socket);
    return 0;
}

void *handle_client(void *arg) {
    int socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(socket, buffer, sizeof(buffer))) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("Client %d says: %s", socket, buffer);
        broadcast_message(buffer, socket);
    }

    remove_client(socket);
    return NULL;
}

void broadcast_message(const char *message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}

void remove_client(int socket) {
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == socket) {
            printf("Client %d disconnected\n", socket);
            close(socket);
            client_sockets[i] = client_sockets[--client_count]; // Replace with last
            return;
        }
    }
}