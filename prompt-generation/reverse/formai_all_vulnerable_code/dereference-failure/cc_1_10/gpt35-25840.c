//FormAI DATASET v1.0 Category: Chat server ; Style: interoperable
/* 
  Title: Interoperable Chat Server
  Description: This is a C program for implementing a basic chat server between a client and a server with two-way communication.
  Developer: [Your Name/Developer Name]
  Date: [Date of Development]
  Last Modified: [Date of Last Modification]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 30

// Client structure
typedef struct {
    char *username;
    int socket;
    struct sockaddr_in address;
    pthread_t thread_id;
} client_t;

client_t *clients[MAX_CLIENTS];

// Function to broadcast messages to all connected clients
void broadcast(client_t *sender, char *message) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i] != sender) {
            write(clients[i]->socket, message, strlen(message));
        }
    }
}

// Function to handle incoming client messages
void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char message[1024];

    while (1) {
        memset(message, 0, 1024);

        int bytes_read = read(client->socket, message, 1024);

        if (bytes_read <= 0) {
            break; // Client disconnected
        }

        broadcast(client, message);
    }

    close(client->socket);

    // Remove client from list of active clients
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == client) {
            clients[i] = NULL;
            break;
        }
    }

    free(client->username);
    free(client);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len;

    // Initialize list of clients
    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i] = NULL;
    }

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Set server socket options
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Bind server socket to address and port
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept incoming connection
        client_address_len = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);

        if (client_socket < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Create client structure
        client_t *client = (client_t *)malloc(sizeof(client_t));
        client->socket = client_socket;
        client->address = client_address;

        // Receive client's username
        char username[100];
        memset(username, 0, 100);
        read(client_socket, username, 100);
        client->username = strdup(username);

        // Add client to list of clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == NULL) {
                clients[i] = client;
                pthread_create(&client->thread_id, NULL, handle_client, (void *)client);
                break;
            }
        }
    }

    return 0;
}