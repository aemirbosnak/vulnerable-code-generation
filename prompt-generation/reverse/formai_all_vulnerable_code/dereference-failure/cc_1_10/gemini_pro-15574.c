//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10
#define MAX_DATA_SIZE 1024

struct client_data {
    int sockfd;
    char *name;
};

struct server_data {
    int sockfd;
    int num_clients;
    struct client_data clients[MAX_CLIENTS];
};

void send_message_to_all_clients(struct server_data *server, char *message) {
    for (int i = 0; i < server->num_clients; i++) {
        send(server->clients[i].sockfd, message, strlen(message), 0);
    }
}

void handle_new_client(struct server_data *server, int new_sockfd) {
    // Get the client's name
    char name[MAX_DATA_SIZE];
    recv(new_sockfd, name, MAX_DATA_SIZE, 0);

    // Add the client to the server's list of clients
    server->clients[server->num_clients].sockfd = new_sockfd;
    server->clients[server->num_clients].name = strdup(name);
    server->num_clients++;

    // Send a welcome message to the new client
    char welcome_message[MAX_DATA_SIZE];
    sprintf(welcome_message, "Welcome to the chat server, %s!", name);
    send(new_sockfd, welcome_message, strlen(welcome_message), 0);

    // Send a message to all other clients that a new client has joined
    char new_client_message[MAX_DATA_SIZE];
    sprintf(new_client_message, "%s has joined the chat!", name);
    send_message_to_all_clients(server, new_client_message);
}

void handle_client_message(struct server_data *server, int client_sockfd) {
    // Get the message from the client
    char message[MAX_DATA_SIZE];
    recv(client_sockfd, message, MAX_DATA_SIZE, 0);

    // Send the message to all other clients
    send_message_to_all_clients(server, message);
}

void handle_client_disconnect(struct server_data *server, int client_sockfd) {
    // Find the client in the server's list of clients
    int client_index = -1;
    for (int i = 0; i < server->num_clients; i++) {
        if (server->clients[i].sockfd == client_sockfd) {
            client_index = i;
            break;
        }
    }

    // If the client was found, remove them from the list
    if (client_index != -1) {
        for (int i = client_index + 1; i < server->num_clients; i++) {
            server->clients[i - 1] = server->clients[i];
        }
        server->num_clients--;

        // Send a message to all other clients that the client has left
        char client_left_message[MAX_DATA_SIZE];
        sprintf(client_left_message, "%s has left the chat!", server->clients[client_index].name);
        send_message_to_all_clients(server, client_left_message);
    }
}

int main(int argc, char *argv[]) {
    // Parse command line arguments
    int port = 8080;
    if (argc > 1) {
        port = atoi(argv[1]);
    }

    // Create a server socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server socket to reuse the address and port
    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind the server socket to the port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Create a server data structure
    struct server_data server;
    server.sockfd = sockfd;
    server.num_clients = 0;

    // Main server loop
    while (1) {
        // Accept a new connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (new_sockfd < 0) {
            perror("accept");
            continue;
        }

        // Handle the new client
        handle_new_client(&server, new_sockfd);
    }

    // Close the server socket
    close(sockfd);

    return EXIT_SUCCESS;
}