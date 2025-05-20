//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LEN 1024

// Struct to store client information
typedef struct client_info {
    int socket;
    char username[32];
} client_info;

// Array to store client information
client_info clients[MAX_CLIENTS];

// Function to send a message to all clients
void broadcast_message(char *message) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].socket != 0) {
            send(clients[i].socket, message, strlen(message), 0);
        }
    }
}

// Function to handle client messages
void handle_client(int socket) {
    char buffer[MAX_MSG_LEN];

    // Receive message from client
    recv(socket, buffer, MAX_MSG_LEN, 0);

    // Check if client is quitting
    if (strcmp(buffer, "/quit") == 0) {
        close(socket);
        return;
    }

    // Check if client is sending a message
    if (buffer[0] == '/') {
        // Parse command
        char command[32];
        char username[32];
        sscanf(buffer, "/%s %s", command, username);

        // Handle command
        if (strcmp(command, "/username") == 0) {
            // Update client username
            strcpy(clients[socket].username, username);
            send(socket, "Username updated.", strlen("Username updated."), 0);
        } else if (strcmp(command, "/list") == 0) {
            // Send list of clients to client
            char list[MAX_CLIENTS * 32];
            strcpy(list, "Clients:");
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i].socket != 0) {
                    strcat(list, " ");
                    strcat(list, clients[i].username);
                }
            }
            strcat(list, "\n");
            send(socket, list, strlen(list), 0);
        }
    } else {
        // Broadcast message to all clients
        char message[MAX_MSG_LEN];
        sprintf(message, "%s: %s", clients[socket].username, buffer);
        broadcast_message(message);
    }
}

int main() {
    // Create server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        return 1;
    }

    // Set server socket to be reusable
    int reuse = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1) {
        perror("Error setting socket options");
        return 1;
    }

    // Bind server socket to port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(5000);
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket to port");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Error listening for connections");
        return 1;
    }

    printf("Chat server listening on port 5000\n");

    // Main loop
    fd_set read_fds;
    while (1) {
        // Clear file descriptor set
        FD_ZERO(&read_fds);

        // Add server socket to file descriptor set
        FD_SET(server_socket, &read_fds);

        // Add client sockets to file descriptor set
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket != 0) {
                FD_SET(clients[i].socket, &read_fds);
            }
        }

        // Wait for activity on any socket
        int activity = select(FD_SETSIZE, &read_fds, NULL, NULL, NULL);
        if (activity == -1) {
            perror("Error in select()");
            return 1;
        }

        // Check if there is activity on the server socket
        if (FD_ISSET(server_socket, &read_fds)) {
            // Accept incoming connection
            int client_socket = accept(server_socket, NULL, NULL);
            if (client_socket == -1) {
                perror("Error accepting connection");
                continue;
            }

            // Add client to client array
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i].socket == 0) {
                    clients[i].socket = client_socket;
                    strcpy(clients[i].username, "Unknown");
                    break;
                }
            }

            // Send welcome message to client
            send(client_socket, "Welcome to the chat server!\n", strlen("Welcome to the chat server!\n"), 0);
        }

        // Check if there is activity on any client socket
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket != 0 && FD_ISSET(clients[i].socket, &read_fds)) {
                // Handle client message
                handle_client(clients[i].socket);
            }
        }
    }

    return 0;
}