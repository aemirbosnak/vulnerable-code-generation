//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 100
#define MAX_MSG_LEN 1024

// Client structure
typedef struct client {
    int sockfd;
    char name[32];
    char msg[MAX_MSG_LEN];
    int msg_len;
} client_t;

// Server structure
typedef struct server {
    int sockfd;
    struct sockaddr_in addr;
    client_t clients[MAX_CLIENTS];
    int num_clients;
} server_t;

// Create a new server
server_t *server_new(int port) {
    server_t *server = malloc(sizeof(server_t));
    if (server == NULL) {
        perror("malloc");
        return NULL;
    }

    // Create a new socket
    server->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sockfd == -1) {
        perror("socket");
        free(server);
        return NULL;
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(server->sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        close(server->sockfd);
        free(server);
        return NULL;
    }

    // Bind the socket to the address
    server->addr.sin_family = AF_INET;
    server->addr.sin_port = htons(port);
    server->addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server->sockfd, (struct sockaddr *)&server->addr, sizeof(server->addr)) == -1) {
        perror("bind");
        close(server->sockfd);
        free(server);
        return NULL;
    }

    // Listen for incoming connections
    if (listen(server->sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        close(server->sockfd);
        free(server);
        return NULL;
    }

    // Initialize the clients
    for (int i = 0; i < MAX_CLIENTS; i++) {
        server->clients[i].sockfd = -1;
        server->clients[i].name[0] = '\0';
        server->clients[i].msg[0] = '\0';
        server->clients[i].msg_len = 0;
    }

    // Set the number of clients to 0
    server->num_clients = 0;

    return server;
}

// Free a server
void server_free(server_t *server) {
    // Close the socket
    close(server->sockfd);

    // Free the clients
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->clients[i].sockfd != -1) {
            close(server->clients[i].sockfd);
        }
    }

    // Free the server
    free(server);
}

// Accept a new client
int server_accept_client(server_t *server) {
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);

    // Accept a new connection
    int client_sockfd = accept(server->sockfd, (struct sockaddr *)&addr, &addr_len);
    if (client_sockfd == -1) {
        perror("accept");
        return -1;
    }

    // Find an empty client slot
    int client_index = -1;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->clients[i].sockfd == -1) {
            client_index = i;
            break;
        }
    }

    // If there are no empty client slots, return an error
    if (client_index == -1) {
        close(client_sockfd);
        return -1;
    }

    // Add the client to the server
    server->clients[client_index].sockfd = client_sockfd;
    server->clients[client_index].name[0] = '\0';
    server->clients[client_index].msg[0] = '\0';
    server->clients[client_index].msg_len = 0;
    server->num_clients++;

    return client_index;
}

// Remove a client
void server_remove_client(server_t *server, int client_index) {
    // Close the client socket
    close(server->clients[client_index].sockfd);

    // Clear the client data
    server->clients[client_index].sockfd = -1;
    server->clients[client_index].name[0] = '\0';
    server->clients[client_index].msg[0] = '\0';
    server->clients[client_index].msg_len = 0;
    server->num_clients--;
}

// Handle a client
void server_handle_client(server_t *server, int client_index) {
    // Receive the client message
    int nbytes = recv(server->clients[client_index].sockfd, server->clients[client_index].msg, MAX_MSG_LEN, 0);
    if (nbytes <= 0) {
        // The client has disconnected
        server_remove_client(server, client_index);
        return;
    }

    // Set the message length
    server->clients[client_index].msg_len = nbytes;

    // Handle the message
    if (server->clients[client_index].msg[0] == '/') {
        // Handle a command
        if (strcmp(server->clients[client_index].msg, "/quit") == 0) {
            // The client wants to quit
            server_remove_client(server, client_index);
            return;
        } else if (strcmp(server->clients[client_index].msg, "/name") == 0) {
            // The client wants to change their name
            if (nbytes > 6) {
                strncpy(server->clients[client_index].name, server->clients[client_index].msg + 6, 32);
            }
            return;
        } else {
            // The client sent an invalid command
            char msg[] = "Invalid command\n";
            send(server->clients[client_index].sockfd, msg, strlen(msg), 0);
            return;
        }
    } else {
        // Handle a normal message
        // Broadcast the message to all clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (server->clients[i].sockfd != -1 && i != client_index) {
                send(server->clients[i].sockfd, server->clients[client_index].msg, nbytes, 0);
            }
        }
    }
}

// Run the server
void server_run(server_t *server) {
    // Main loop
    while (1) {
        // Check for new clients
        int client_index = server_accept_client(server);
        if (client_index == -1) {
            continue;
        }

        // Handle the client
        server_handle_client(server, client_index);
    }
}

// Main function
int main(int argc, char **argv) {
    // Check the arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create a new server
    server_t *server = server_new(atoi(argv[1]));
    if (server == NULL) {
        return 1;
    }

    // Run the server
    server_run(server);

    // Free the server
    server_free(server);

    return 0;
}