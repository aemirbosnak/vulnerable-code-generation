//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 9000
#define MAX_CLIENTS 10

// Structure to store client information
typedef struct client {
    int socket;
    char name[256];
    struct client *next;
} client;

// Global variables
client *clients = NULL;
int num_clients = 0;

// Function to add a new client to the list
void add_client(int socket, char *name) {
    client *new_client = malloc(sizeof(client));
    new_client->socket = socket;
    strcpy(new_client->name, name);
    new_client->next = clients;
    clients = new_client;
    num_clients++;
}

// Function to remove a client from the list
void remove_client(int socket) {
    client *prev = NULL;
    client *curr = clients;
    while (curr != NULL) {
        if (curr->socket == socket) {
            if (prev == NULL) {
                clients = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            num_clients--;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Function to send a message to all clients
void broadcast_message(char *message) {
    client *curr = clients;
    while (curr != NULL) {
        send(curr->socket, message, strlen(message), 0);
        curr = curr->next;
    }
}

// Function to handle client connections
void handle_client(int socket) {
    char buffer[256];
    int recv_bytes;

    // Get the client's name
    recv_bytes = recv(socket, buffer, sizeof(buffer), 0);
    if (recv_bytes <= 0) {
        remove_client(socket);
        return;
    }
    buffer[recv_bytes] = '\0';
    add_client(socket, buffer);

    // Broadcast the client's name to all other clients
    sprintf(buffer, "%s has joined the chat.\n", buffer);
    broadcast_message(buffer);

    // Loop until the client disconnects
    while ((recv_bytes = recv(socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[recv_bytes] = '\0';

        // Broadcast the client's message to all other clients
        sprintf(buffer, "%s: %s\n", clients[socket], buffer);
        broadcast_message(buffer);
    }

    // Remove the client from the list
    remove_client(socket);

    // Broadcast a message to all other clients indicating that the client has left
    sprintf(buffer, "%s has left the chat.\n", clients[socket]);
    broadcast_message(buffer);
}

// Main function
int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return -1;
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the server socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        return -1;
    }

    // Accept incoming connections and handle them
    while (1) {
        client_addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        handle_client(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}