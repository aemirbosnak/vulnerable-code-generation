//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LEN 1024

// Client structure
typedef struct {
    int sockfd;
    char username[32];
} Client;

// Server structure
typedef struct {
    int sockfd;
    Client clients[MAX_CLIENTS];
    int num_clients;
} Server;

// Function to create a new server
Server* create_server(int port) {
    // Allocate memory for the server
    Server* server = (Server*)malloc(sizeof(Server));

    // Create the server socket
    server->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sockfd < 0) {
        perror("Error creating server socket");
        return NULL;
    }

    // Set the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind the server socket to the address
    if (bind(server->sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server socket");
        close(server->sockfd);
        return NULL;
    }

    // Listen for incoming connections
    if (listen(server->sockfd, MAX_CLIENTS) < 0) {
        perror("Error listening for incoming connections");
        close(server->sockfd);
        return NULL;
    }

    return server;
}

// Function to accept a new client
Client* accept_client(Server* server) {
    // Accept a new connection
    int newsockfd = accept(server->sockfd, NULL, NULL);
    if (newsockfd < 0) {
        perror("Error accepting new connection");
        return NULL;
    }

    // Allocate memory for the new client
    Client* client = (Client*)malloc(sizeof(Client));

    // Set the client's socket
    client->sockfd = newsockfd;

    // Read the client's username
    int n = read(client->sockfd, client->username, 32);
    if (n < 0) {
        perror("Error reading client's username");
        close(client->sockfd);
        return NULL;
    }

    // Add the client to the server's list of clients
    server->clients[server->num_clients++] = *client;

    return client;
}

// Function to handle a client
void handle_client(Client* client, Server* server) {
    // Buffer for receiving messages
    char msg[MAX_MSG_LEN];

    // Loop until the client disconnects
    while (1) {
        // Read a message from the client
        int n = read(client->sockfd, msg, MAX_MSG_LEN);
        if (n < 0) {
            perror("Error reading message from client");
            close(client->sockfd);
            return;
        } else if (n == 0) {
            // Client has disconnected
            printf("Client %s has disconnected\n", client->username);
            close(client->sockfd);
            return;
        }

        // Send the message to all other clients
        for (int i = 0; i < server->num_clients; i++) {
            if (server->clients[i].sockfd != client->sockfd) {
                n = write(server->clients[i].sockfd, msg, n);
                if (n < 0) {
                    perror("Error sending message to client");
                    close(server->clients[i].sockfd);
                    return;
                }
            }
        }
    }
}

// Main function
int main(int argc, char* argv[]) {
    // Check if the port was specified
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create the server
    Server* server = create_server(atoi(argv[1]));
    if (server == NULL) {
        return 1;
    }

    // Main loop
    while (1) {
        // Accept a new client
        Client* client = accept_client(server);
        if (client == NULL) {
            continue;
        }

        // Handle the client in a new thread
        pthread_t thread;
        pthread_create(&thread, NULL, (void*)handle_client, client);
    }

    // Cleanup
    close(server->sockfd);
    for (int i = 0; i < server->num_clients; i++) {
        close(server->clients[i].sockfd);
    }
    free(server);
    return 0;
}