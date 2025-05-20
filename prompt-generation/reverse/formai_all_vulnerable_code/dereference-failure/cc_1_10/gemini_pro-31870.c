//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000
#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

struct client_info {
    int socket_fd;
    char name[MAX_BUFFER_SIZE];
    int is_active;
};

struct server_info {
    int server_fd;
    struct client_info clients[MAX_CLIENTS];
    int num_clients;
};

void create_server(struct server_info *server) {
    // Create a socket
    server->server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->server_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server->server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server->server_fd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

void accept_clients(struct server_info *server) {
    // Accept incoming connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        int client_fd = accept(server->server_fd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        // Add the new client to the list of clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (server->clients[i].is_active == 0) {
                server->clients[i].socket_fd = client_fd;
                strcpy(server->clients[i].name, inet_ntoa(client_addr.sin_addr));
                server->clients[i].is_active = 1;
                server->num_clients++;
                break;
            }
        }

        // Send a welcome message to the new client
        char welcome_message[] = "Welcome to the chat server!";
        send(client_fd, welcome_message, strlen(welcome_message), 0);
    }
}

void broadcast_message(struct server_info *server, char *message, int sender_fd) {
    // Broadcast the message to all clients
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->clients[i].is_active == 1 && server->clients[i].socket_fd != sender_fd) {
            send(server->clients[i].socket_fd, message, strlen(message), 0);
        }
    }
}

void handle_client_messages(struct server_info *server) {
    // Handle messages from clients
    while (1) {
        char buffer[MAX_BUFFER_SIZE];

        // Receive a message from a client
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (server->clients[i].is_active == 1) {
                int num_bytes_received = recv(server->clients[i].socket_fd, buffer, MAX_BUFFER_SIZE, 0);
                if (num_bytes_received == -1) {
                    perror("recv");
                    continue;
                } else if (num_bytes_received == 0) {
                    // Client has disconnected
                    printf("Client %s has disconnected.\n", server->clients[i].name);
                    server->clients[i].is_active = 0;
                    server->num_clients--;
                    continue;
                }

                // Broadcast the message to all other clients
                char message[MAX_BUFFER_SIZE];
                sprintf(message, "%s: %s", server->clients[i].name, buffer);
                broadcast_message(server, message, server->clients[i].socket_fd);
            }
        }
    }
}

void close_server(struct server_info *server) {
    // Close the server socket
    close(server->server_fd);

    // Close all client sockets
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->clients[i].is_active == 1) {
            close(server->clients[i].socket_fd);
        }
    }
}

int main() {
    // Create the server
    struct server_info server;
    create_server(&server);

    // Accept clients
    accept_clients(&server);

    // Handle client messages
    handle_client_messages(&server);

    // Close the server
    close_server(&server);

    return 0;
}