//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

// A self-referential struct to represent a client
typedef struct Client {
    int sockfd;         // Socket file descriptor
    struct sockaddr_in addr;  // Socket address
    char *name;         // Client's name
    struct Client *next; // Pointer to the next client in the list
} Client;

// A self-referential struct to represent the server
typedef struct Server {
    int sockfd;         // Socket file descriptor
    struct sockaddr_in addr;  // Socket address
    Client *clients;     // List of connected clients
} Server;

// Function to create a new client
Client *create_client(int sockfd, struct sockaddr_in addr) {
    Client *client = malloc(sizeof(Client));
    if (!client) {
        perror("malloc");
        exit(1);
    }
    client->sockfd = sockfd;
    client->addr = addr;
    client->name = NULL;
    client->next = NULL;
    return client;
}

// Function to add a client to the server's list of clients
void add_client(Server *server, Client *client) {
    client->next = server->clients;
    server->clients = client;
}

// Function to remove a client from the server's list of clients
void remove_client(Server *server, Client *client) {
    Client *prev = NULL;
    Client *curr = server->clients;
    while (curr) {
        if (curr == client) {
            if (prev) {
                prev->next = curr->next;
            } else {
                server->clients = curr->next;
            }
            free(client->name);
            free(client);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Function to send a message to all clients
void broadcast(Server *server, char *message) {
    Client *client = server->clients;
    while (client) {
        send(client->sockfd, message, strlen(message), 0);
        client = client->next;
    }
}

// Function to handle a client's request
void handle_client(Server *server, Client *client) {
    char buffer[256];
    while (1) {
        int n = recv(client->sockfd, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            break;
        }
        buffer[n] = '\0';
        if (!client->name) {
            client->name = malloc(n + 1);
            strcpy(client->name, buffer);
            broadcast(server, "New client joined: ");
            broadcast(server, client->name);
            broadcast(server, "\n");
            continue;
        }
        broadcast(server, client->name);
        broadcast(server, ": ");
        broadcast(server, buffer);
        broadcast(server, "\n");
    }
    remove_client(server, client);
    close(client->sockfd);
}

// Function to start the server
void start_server(int port) {
    Server server;
    server.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server.sockfd < 0) {
        perror("socket");
        exit(1);
    }
    server.addr.sin_family = AF_INET;
    server.addr.sin_port = htons(port);
    server.addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server.sockfd, (struct sockaddr *)&server.addr, sizeof(server.addr)) < 0) {
        perror("bind");
        exit(1);
    }
    if (listen(server.sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }
    server.clients = NULL;
    while (1) {
        struct sockaddr_in addr;
        socklen_t addrlen = sizeof(addr);
        int sockfd = accept(server.sockfd, (struct sockaddr *)&addr, &addrlen);
        if (sockfd < 0) {
            perror("accept");
            continue;
        }
        Client *client = create_client(sockfd, addr);
        add_client(&server, client);
        handle_client(&server, client);
    }
    close(server.sockfd);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    int port = atoi(argv[1]);
    start_server(port);
    return 0;
}