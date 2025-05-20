//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 256

// Structure to hold client details
typedef struct {
    int sock;
    struct sockaddr_in address;
    int addr_len;
} client_t;

// Store client sockets
client_t *clients[MAX_CLIENTS];

// Function to broadcast message to all connected clients
void broadcast_message(const char *message, int exclude_sock) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->sock != exclude_sock) {
            send(clients[i]->sock, message, strlen(message), 0);
        }
    }
}

// Thread function to handle client connection
void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(client->sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0'; // Null terminate string
        printf("Client (%d): %s", client->sock, buffer);

        // Broadcast the received message to all other clients
        broadcast_message(buffer, client->sock);
    }

    // Client disconnected
    close(client->sock);
    free(client);
    return NULL;
}

// Main function for the server
int main() {
    int server_fd, new_client_sock;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t tid;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Configure address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d...\n", PORT);

    while (1) {
        // Accept new client
        client_t *new_client = (client_t *)malloc(sizeof(client_t));
        if ((new_client->sock = accept(server_fd, (struct sockaddr *)&new_client->address, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed");
            free(new_client);
            continue;
        }

        // Add to clients list and create a new thread for the client
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == NULL) {
                clients[i] = new_client;
                pthread_create(&tid, NULL, handle_client, (void *)new_client);
                break;
            }
        }
    }

    // Close server socket
    close(server_fd);
    return 0;
}