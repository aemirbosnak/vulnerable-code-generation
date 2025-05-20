//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

struct client {
    int sockfd;
    char name[50];
};

struct chat_server {
    int sockfd;
    struct sockaddr_in servaddr;
    struct client clients[MAX_CLIENTS];
    int num_clients;
};

// Create a new chat server
struct chat_server *create_chat_server(int port) {
    struct chat_server *server = malloc(sizeof(struct chat_server));
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

    // Set up the server address
    memset(&server->servaddr, 0, sizeof(server->servaddr));
    server->servaddr.sin_family = AF_INET;
    server->servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    server->servaddr.sin_port = htons(port);

    // Bind the socket to the server address
    if (bind(server->sockfd, (struct sockaddr *)&server->servaddr, sizeof(server->servaddr)) == -1) {
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

    server->num_clients = 0;

    return server;
}

// Free the resources associated with a chat server
void free_chat_server(struct chat_server *server) {
    close(server->sockfd);
    free(server);
}

// Add a new client to a chat server
int add_client(struct chat_server *server, int sockfd, char *name) {
    if (server->num_clients >= MAX_CLIENTS) {
        return -1;
    }

    server->clients[server->num_clients].sockfd = sockfd;
    strcpy(server->clients[server->num_clients].name, name);
    server->num_clients++;

    return 0;
}

// Remove a client from a chat server
void remove_client(struct chat_server *server, int sockfd) {
    int i;

    for (i = 0; i < server->num_clients; i++) {
        if (server->clients[i].sockfd == sockfd) {
            server->clients[i] = server->clients[server->num_clients - 1];
            server->num_clients--;
            break;
        }
    }
}

// Broadcast a message to all clients in a chat server
void broadcast_message(struct chat_server *server, int sockfd, char *msg) {
    int i;

    for (i = 0; i < server->num_clients; i++) {
        if (server->clients[i].sockfd != sockfd) {
            send(server->clients[i].sockfd, msg, strlen(msg), 0);
        }
    }
}

// Handle a new connection to a chat server
void handle_connection(struct chat_server *server, int sockfd) {
    char buffer[MAX_MSG_SIZE];
    char name[50];
    int n;

    // Receive the client's name
    n = recv(sockfd, name, sizeof(name), 0);
    if (n == -1) {
        perror("recv");
        close(sockfd);
        return;
    }

    // Add the client to the server
    if (add_client(server, sockfd, name) == -1) {
        send(sockfd, "Server is full", 14, 0);
        close(sockfd);
        return;
    }

    // Send a welcome message to the client
    send(sockfd, "Welcome to the chat server", 26, 0);

    // Broadcast the client's name to all other clients
    sprintf(buffer, "%s has joined the chat", name);
    broadcast_message(server, sockfd, buffer);

    // Receive messages from the client
    while (1) {
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n == -1) {
            perror("recv");
            remove_client(server, sockfd);
            close(sockfd);
            return;
        } else if (n == 0) {
            // Client has disconnected
            remove_client(server, sockfd);
            close(sockfd);
            return;
        }

        // Broadcast the message to all other clients
        sprintf(buffer, "%s: %s", name, buffer);
        broadcast_message(server, sockfd, buffer);
    }
}

// Main function
int main(int argc, char **argv) {
    struct chat_server *server;
    int sockfd;
    struct sockaddr_in cliaddr;
    socklen_t clilen;
    pid_t pid;

    // Create a new chat server
    server = create_chat_server(5000);
    if (server == NULL) {
        return EXIT_FAILURE;
    }

    // Accept incoming connections
    while (1) {
        clilen = sizeof(cliaddr);
        sockfd = accept(server->sockfd, (struct sockaddr *)&cliaddr, &clilen);
        if (sockfd == -1) {
            perror("accept");
            continue;
        }

        // Create a new process to handle the connection
        pid = fork();
        if (pid == -1) {
            perror("fork");
            close(sockfd);
            continue;
        } else if (pid == 0) {
            // Child process
            close(server->sockfd);
            handle_connection(server, sockfd);
            exit(EXIT_SUCCESS);
        } else {
            // Parent process
            close(sockfd);
        }
    }

    // Free the resources associated with the chat server
    free_chat_server(server);

    return EXIT_SUCCESS;
}