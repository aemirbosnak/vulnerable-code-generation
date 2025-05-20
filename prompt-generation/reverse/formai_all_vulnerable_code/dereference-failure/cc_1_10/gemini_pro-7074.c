//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum size of the message that can be sent
#define MAX_MESSAGE_SIZE 1024

// Define the IP address of the server
#define SERVER_IP "127.0.0.1"

// Define the number of clients that can connect to the server
#define MAX_CLIENTS 10

// Define the structure of the client
typedef struct client {
    int socket;
    char name[MAX_MESSAGE_SIZE];
} client_t;

// Define the structure of the server
typedef struct server {
    int socket;
    int num_clients;
    client_t clients[MAX_CLIENTS];
} server_t;

// Create a new client
client_t* create_client(int socket, char* name) {
    client_t* client = malloc(sizeof(client_t));
    client->socket = socket;
    strcpy(client->name, name);
    return client;
}

// Create a new server
server_t* create_server(int port) {
    server_t* server = malloc(sizeof(server_t));
    server->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->socket == -1) {
        perror("Could not create server socket");
        exit(1);
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(port);
    if (bind(server->socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Could not bind server socket");
        exit(1);
    }
    if (listen(server->socket, MAX_CLIENTS) == -1) {
        perror("Could not listen on server socket");
        exit(1);
    }
    server->num_clients = 0;
    return server;
}

// Accept a new client connection
client_t* accept_client(server_t* server) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_socket = accept(server->socket, (struct sockaddr*)&client_addr, &client_addr_len);
    if (client_socket == -1) {
        perror("Could not accept client connection");
        return NULL;
    }
    char* client_name = malloc(MAX_MESSAGE_SIZE);
    if (recv(client_socket, client_name, MAX_MESSAGE_SIZE, 0) == -1) {
        perror("Could not receive client name");
        close(client_socket);
        return NULL;
    }
    client_t* client = create_client(client_socket, client_name);
    server->clients[server->num_clients++] = *client;
    return client;
}

// Send a message to all clients
void send_message_to_all_clients(server_t* server, char* message) {
    for (int i = 0; i < server->num_clients; i++) {
        if (send(server->clients[i].socket, message, strlen(message), 0) == -1) {
            perror("Could not send message to client");
        }
    }
}

// Close a client connection
void close_client_connection(server_t* server, client_t* client) {
    for (int i = 0; i < server->num_clients; i++) {
        if (server->clients[i].socket == client->socket) {
            close(server->clients[i].socket);
            server->clients[i] = server->clients[server->num_clients - 1];
            server->num_clients--;
            break;
        }
    }
}

// Main function
int main() {
    // Create a new server
    server_t* server = create_server(PORT);
    
    // Loop forever, accepting new client connections and sending messages
    while (1) {
        // Accept a new client connection
        client_t* client = accept_client(server);
        if (client == NULL) {
            continue;
        }
        
        // Send a welcome message to the new client
        char* welcome_message = "Welcome to the chat server!\n";
        if (send(client->socket, welcome_message, strlen(welcome_message), 0) == -1) {
            perror("Could not send welcome message to client");
            close_client_connection(server, client);
            continue;
        }
        
        // Send a message to all clients that a new client has joined
        char* new_client_message = client->name;
        strcat(new_client_message, " has joined the chat.\n");
        send_message_to_all_clients(server, new_client_message);
        
        // Loop forever, receiving messages from the client and sending them to all other clients
        while (1) {
            // Receive a message from the client
            char* message = malloc(MAX_MESSAGE_SIZE);
            if (recv(client->socket, message, MAX_MESSAGE_SIZE, 0) == -1) {
                perror("Could not receive message from client");
                close_client_connection(server, client);
                break;
            }
            
            // Send the message to all other clients
            send_message_to_all_clients(server, message);
        }
    }
    
    // Close the server socket
    close(server->socket);
    
    // Free the allocated memory
    for (int i = 0; i < server->num_clients; i++) {
        free(server->clients[i].name);
    }
    free(server);
    
    return 0;
}