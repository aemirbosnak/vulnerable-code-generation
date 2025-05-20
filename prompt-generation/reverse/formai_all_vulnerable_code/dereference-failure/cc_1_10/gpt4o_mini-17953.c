//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

static int client_count = 0;
static int client_sockets[MAX_CLIENTS];

void *handle_client(void *socket_desc);
void broadcast_message(char *message, int sender_socket);

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t thread_id;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Chat server started. Waiting for connections...\n");

    // Accept clients in a loop
    while ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len))) {
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = new_socket;
            printf("New client connected\n");

            // Create a new thread for the client
            if (pthread_create(&thread_id, NULL, handle_client, (void *)&new_socket) < 0) {
                perror("Could not create thread");
                exit(EXIT_FAILURE);
            }
        } else {
            printf("Max clients connected. Rejecting new client.\n");
            close(new_socket);
        }
    }

    if (new_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    close(server_socket);
    return 0;
}

void *handle_client(void *socket_desc) {
    int client_socket = *(int *)socket_desc;
    char message[BUFFER_SIZE];
    int read_size;

    while ((read_size = read(client_socket, message, sizeof(message) - 1)) > 0) {
        message[read_size] = '\0'; // Null-terminate the string
        printf("Client: %s", message);
        broadcast_message(message, client_socket);
        memset(message, 0, BUFFER_SIZE); // Clear message buffer
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
        close(client_socket);
        return 0;
    } else {
        perror("recv failed");
        return 0;
    }
}

void broadcast_message(char *message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}