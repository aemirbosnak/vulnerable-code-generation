//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PORT 8080

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
    char name[32];
} client_info;

// List of all clients
client_info *clients[MAX_CLIENTS];

// Function to add a client to the list
void add_client(client_info *client) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == NULL) {
            clients[i] = client;
            return;
        }
    }
}

// Function to remove a client from the list
void remove_client(int socket) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket == socket) {
            free(clients[i]);
            clients[i] = NULL;
            return;
        }
    }
}

// Function to handle client messages
void *handle_client(void *arg) {
    client_info *client = (client_info *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;
    
    printf("A new client has wandered into the room: %s\n", client->name);

    while ((bytes_read = recv(client->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s says: %s", client->name, buffer);

        // Broadcast the message to other clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] && clients[i]->socket != client->socket) {
                send(clients[i]->socket, buffer, bytes_read, 0);
            }
        }
    }
    
    printf("%s has departed from the conversation.\n", client->name);
    remove_client(client->socket);
    close(client->socket);
    free(client);
    return NULL;
}

// Main function
int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    pthread_t tid;

    // Initialize the client list
    memset(clients, 0, sizeof(clients));

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }
    
    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Listen failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    printf("Sherlock's Chatroom is now open for the gathering of minds...\n");

    while (1) {
        int addr_len = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Create new client_info
        client_info *new_client = (client_info *)malloc(sizeof(client_info));
        new_client->socket = client_socket;
        new_client->address = client_addr;
        new_client->addr_len = addr_len;
        snprintf(new_client->name, sizeof(new_client->name), "Client %d", client_socket);

        // Add client to the list
        add_client(new_client);

        // Create a thread to handle the client
        pthread_create(&tid, NULL, handle_client, (void *)new_client);
    }

    // Close server socket
    close(server_socket);
    return EXIT_SUCCESS;
}