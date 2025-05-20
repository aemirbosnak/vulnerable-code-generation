//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} client_t;

// Array to store client sockets
client_t *clients[MAX_CLIENTS];
int client_count = 0;

// Function to broadcast messages to all connected clients
void broadcast_message(char *message, int exclude_socket) {
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->socket != exclude_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
}

// Function to handle each client connection
void *client_handler(void *arg) {
    char buffer[BUFFER_SIZE];
    int client_socket = ((client_t *)arg)->socket;
    int read_size;

    // Welcome message
    char welcome_msg[] = "Welcome to the cheerful chat server! Say something!\n";
    send(client_socket, welcome_msg, sizeof(welcome_msg), 0);

    // Main loop to receive messages
    while ((read_size = recv(client_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the string

        // Broadcast the message to other clients
        printf("Received message: %s", buffer);
        broadcast_message(buffer, client_socket);
        memset(buffer, 0, BUFFER_SIZE); // Clear the buffer
    }

    // Remove the client from the list if they disconnect
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->socket == client_socket) {
            close(client_socket);
            free(clients[i]);
            // Shift remaining clients down
            for (int j = i; j < client_count - 1; j++) {
                clients[j] = clients[j + 1];
            }
            client_count--;
            break;
        }
    }
    pthread_exit(NULL);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t thread_id;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("😊 Cheerful chat server started! Waiting for clients to connect...\n");

    // Accept clients in a loop
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len))) {
        printf("🎉 New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if (client_count < MAX_CLIENTS) {
            client_t *new_client = malloc(sizeof(client_t));
            new_client->socket = client_socket;
            new_client->address = client_addr;
            new_client->addr_len = addr_len;
            clients[client_count++] = new_client;

            // Create a thread for the new client
            if (pthread_create(&thread_id, NULL, client_handler, (void *)new_client) < 0) {
                perror("Thread creation failed");
                free(new_client);
            }
        } else {
            printf("😢 Server is full, rejecting the client...\n");
            close(client_socket);
        }
    }

    // Cleanup
    close(server_socket);
    return 0;
}