//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_BUFFER 1024

int client_sockets[MAX_CLIENTS];

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[MAX_BUFFER];
    int read_size;

    while ((read_size = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the string
        printf("Client %d: %s\n", client_socket, buffer);
        // Broadcast message to all other clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] && client_sockets[i] != client_socket) {
                send(client_sockets[i], buffer, read_size, 0);
            }
        }
    }

    // Handle client disconnection
    printf("Client %d disconnected\n", client_socket);
    close(client_socket);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = 0;
            break;
        }
    }
    return NULL;
}

int main() {
    int server_socket, client_socket, *new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t thread_id;

    // Initialize client sockets
    memset(client_sockets, 0, sizeof(client_sockets));

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Could not create socket");
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    listen(server_socket, 3);
    printf("Chat server started on port %d. Waiting for connections...\n", PORT);

    while (1) {
        // Accept incoming connections
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }
        printf("Client connected: %d\n", client_socket);
        
        // Add new socket to client_sockets array
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = client_socket; // Store client socket
                break;
            }
        }

        // Create a thread for handling client
        new_sock = malloc(1);
        *new_sock = client_socket;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_sock) < 0) {
            perror("Could not create thread");
            free(new_sock);
            return EXIT_FAILURE;
        }
        pthread_detach(thread_id); // Detach thread to avoid memory leak
    }

    close(server_socket);
    return EXIT_SUCCESS;
}