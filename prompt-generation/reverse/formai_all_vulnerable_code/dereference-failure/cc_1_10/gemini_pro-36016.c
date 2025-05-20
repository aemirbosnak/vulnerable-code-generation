//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Welcome message for newly connected clients
const char *WELCOME_MSG = "Welcome to ChatLand, the place where pixels meet words!\n";

// Server settings
#define PORT 8080
#define MAX_CLIENTS 100
#define MAX_MSG_SIZE 1024

// Client information
typedef struct {
    int socket;
    char *name;
} Client;

// Server data
typedef struct {
    int server_socket;
    Client clients[MAX_CLIENTS];
    int num_clients;
} Server;

// Initialize the server
Server *init_server() {
    Server *server = malloc(sizeof(Server));
    server->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->server_socket == -1) {
        perror("Error creating server socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server->server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding server socket");
        exit(1);
    }

    if (listen(server->server_socket, MAX_CLIENTS) == -1) {
        perror("Error listening on server socket");
        exit(1);
    }

    server->num_clients = 0;
    return server;
}

// Add a new client to the server
void add_client(Server *server, int socket, char *name) {
    if (server->num_clients >= MAX_CLIENTS) {
        printf("Server is full, can't add more clients\n");
        return;
    }

    Client client;
    client.socket = socket;
    client.name = name;

    server->clients[server->num_clients++] = client;
}

// Remove a client from the server
void remove_client(Server *server, int socket) {
    for (int i = 0; i < server->num_clients; i++) {
        if (server->clients[i].socket == socket) {
            // Shift the remaining clients to the left
            for (int j = i + 1; j < server->num_clients; j++) {
                server->clients[j - 1] = server->clients[j];
            }
            server->num_clients--;
            break;
        }
    }
}

// Send a message to all clients
void broadcast(Server *server, char *message) {
    for (int i = 0; i < server->num_clients; i++) {
        send(server->clients[i].socket, message, strlen(message), 0);
    }
}

// Handle client connections and messages
void handle_clients(Server *server) {
    fd_set read_fds;
    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(server->server_socket, &read_fds);

        for (int i = 0; i < server->num_clients; i++) {
            FD_SET(server->clients[i].socket, &read_fds);
        }

        int activity = select(server->server_socket + 1, &read_fds, NULL, NULL, NULL);
        if (activity == -1) {
            perror("Error in select");
            exit(1);
        }

        // Handle new client connections
        if (FD_ISSET(server->server_socket, &read_fds)) {
            int new_socket = accept(server->server_socket, NULL, NULL);
            if (new_socket == -1) {
                perror("Error accepting new client connection");
                continue;
            }

            char buffer[MAX_MSG_SIZE];
            recv(new_socket, buffer, MAX_MSG_SIZE, 0);
            add_client(server, new_socket, buffer);
            send(new_socket, WELCOME_MSG, strlen(WELCOME_MSG), 0);
            printf("New client connected: %s\n", buffer);
            broadcast(server, "New client joined: ");
            broadcast(server, buffer);
        }

        // Handle messages from existing clients
        for (int i = 0; i < server->num_clients; i++) {
            if (FD_ISSET(server->clients[i].socket, &read_fds)) {
                char buffer[MAX_MSG_SIZE];
                int bytes_received = recv(server->clients[i].socket, buffer, MAX_MSG_SIZE, 0);

                if (bytes_received == -1) {
                    perror("Error receiving message from client");
                    remove_client(server, server->clients[i].socket);
                    broadcast(server, "Client disconnected: ");
                    broadcast(server, server->clients[i].name);
                    continue;
                } else if (bytes_received == 0) {
                    // Client has disconnected
                    remove_client(server, server->clients[i].socket);
                    broadcast(server, "Client disconnected: ");
                    broadcast(server, server->clients[i].name);
                    continue;
                }

                buffer[bytes_received] = '\0';
                printf("%s: %s\n", server->clients[i].name, buffer);
                broadcast(server, server->clients[i].name);
                broadcast(server, ": ");
                broadcast(server, buffer);
            }
        }
    }
}

// Clean up the server
void cleanup_server(Server *server) {
    close(server->server_socket);
    for (int i = 0; i < server->num_clients; i++) {
        close(server->clients[i].socket);
    }
    free(server);
}

int main() {
    Server *server = init_server();
    handle_clients(server);
    cleanup_server(server);
    return 0;
}