//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_CLIENTS 100
#define MAX_MSG_LEN 1024

// Client structure
struct client {
    int sockfd;
    char name[32];
};

// Server structure
struct server {
    int sockfd;
    struct client clients[MAX_CLIENTS];
    int num_clients;
};

// Create a new server
struct server *create_server(int port) {
    struct server *server = malloc(sizeof(struct server));
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

    // Bind the socket to the port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    if (bind(server->sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        close(server->sockfd);
        free(server);
        return NULL;
    }

    // Listen for connections
    if (listen(server->sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        close(server->sockfd);
        free(server);
        return NULL;
    }

    server->num_clients = 0;

    return server;
}

// Free a server
void free_server(struct server *server) {
    // Close the socket
    close(server->sockfd);

    // Free the clients
    for (int i = 0; i < server->num_clients; i++) {
        close(server->clients[i].sockfd);
    }

    // Free the server
    free(server);
}

// Add a new client to the server
int add_client(struct server *server, int sockfd, char *name) {
    // Check if the server is full
    if (server->num_clients >= MAX_CLIENTS) {
        return -1;
    }

    // Add the client to the server
    server->clients[server->num_clients].sockfd = sockfd;
    strcpy(server->clients[server->num_clients].name, name);
    server->num_clients++;

    return 0;
}

// Remove a client from the server
int remove_client(struct server *server, int sockfd) {
    // Find the client in the server
    int index = -1;
    for (int i = 0; i < server->num_clients; i++) {
        if (server->clients[i].sockfd == sockfd) {
            index = i;
            break;
        }
    }

    // Check if the client was found
    if (index == -1) {
        return -1;
    }

    // Remove the client from the server
    for (int i = index; i < server->num_clients - 1; i++) {
        server->clients[i] = server->clients[i + 1];
    }
    server->num_clients--;

    return 0;
}

// Handle a new connection
void handle_connection(struct server *server, int sockfd) {
    // Read the client's name
    char name[32];
    int n = read(sockfd, name, sizeof(name));
    if (n <= 0) {
        perror("read");
        close(sockfd);
        return;
    }

    // Add the client to the server
    if (add_client(server, sockfd, name) == -1) {
        perror("add_client");
        close(sockfd);
        return;
    }

    // Send a welcome message to the client
    char welcome_msg[] = "Welcome to the chat server!\n";
    if (write(sockfd, welcome_msg, strlen(welcome_msg)) == -1) {
        perror("write");
        close(sockfd);
        return;
    }

    // Broadcast the client's name to all other clients
    char broadcast_msg[128];
    sprintf(broadcast_msg, "%s has joined the chat\n", name);
    for (int i = 0; i < server->num_clients; i++) {
        if (server->clients[i].sockfd != sockfd) {
            if (write(server->clients[i].sockfd, broadcast_msg, strlen(broadcast_msg)) == -1) {
                perror("write");
                close(server->clients[i].sockfd);
                return;
            }
        }
    }

    // Handle the client's messages
    while (1) {
        // Read the client's message
        char msg[MAX_MSG_LEN];
        n = read(sockfd, msg, sizeof(msg));
        if (n <= 0) {
            perror("read");
            close(sockfd);
            return;
        }

        // Broadcast the client's message to all other clients
        for (int i = 0; i < server->num_clients; i++) {
            if (server->clients[i].sockfd != sockfd) {
                if (write(server->clients[i].sockfd, msg, strlen(msg)) == -1) {
                    perror("write");
                    close(server->clients[i].sockfd);
                    return;
                }
            }
        }
    }
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create the server
    struct server *server = create_server(atoi(argv[1]));
    if (server == NULL) {
        return 1;
    }

    // Handle connections
    while (1) {
        // Accept a new connection
        int sockfd = accept(server->sockfd, NULL, NULL);
        if (sockfd == -1) {
            perror("accept");
            continue;
        }

        // Handle the new connection in a separate thread
        pthread_t thread;
        if (pthread_create(&thread, NULL, (void *(*)(void *))handle_connection, (void *)server) != 0) {
            perror("pthread_create");
            close(sockfd);
            continue;
        }

        // Detach the thread
        pthread_detach(thread);
    }

    // Free the server
    free_server(server);

    return 0;
}