//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct chat_server {
    int sock;
    int num_clients;
    struct chat_client *clients;
};

struct chat_client {
    int sock;
    char name[50];
    char message[100];
};

void init_server(struct chat_server *server) {
    server->sock = socket(AF_INET, SOCK_STREAM, 0);
    server->num_clients = 0;
    server->clients = calloc(1, sizeof(struct chat_client));
}

void init_client(struct chat_client *client) {
    client->sock = socket(AF_INET, SOCK_STREAM, 0);
    client->name[0] = '\0';
    client->message[0] = '\0';
}

void handle_client(struct chat_server *server, struct chat_client *client) {
    char buffer[100];
    int bytes_read;

    // Read message from client
    bytes_read = read(client->sock, buffer, 100);
    if (bytes_read > 0) {
        // Print message to all clients
        printf("Client %s says: %s\n", client->name, buffer);
        send(server->sock, buffer, bytes_read, 0);
    }

    // Read name from client
    bytes_read = read(client->sock, client->name, 50);
    if (bytes_read > 0) {
        // Print name to all clients
        printf("New client %s joined the chat\n", client->name);
    }
}

void handle_server(struct chat_server *server) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock;

    // Accept incoming connections
    client_sock = accept(server->sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock > 0) {
        struct chat_client *new_client = calloc(1, sizeof(struct chat_client));
        new_client->sock = client_sock;
        handle_client(server, new_client);
    }
}

int main() {
    struct chat_server server;
    init_server(&server);

    while (1) {
        handle_server(&server);
    }

    return 0;
}