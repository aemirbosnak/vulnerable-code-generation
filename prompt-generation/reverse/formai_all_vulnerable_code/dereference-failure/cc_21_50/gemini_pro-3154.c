//GEMINI-pro DATASET v1.0 Category: Networking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_NAME_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024

// Structure to store client information
typedef struct {
    int socket;
    char name[MAX_NAME_LENGTH];
} Client;

// Array of clients
Client clients[MAX_CLIENTS];

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified a port number
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the port number from the user
    int port = atoi(argv[1]);

    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    // Bind the socket to the port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Main loop
    while (1) {
        // Accept incoming connections
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Get the client's name
        char name[MAX_NAME_LENGTH];
        if (recv(client_socket, name, MAX_NAME_LENGTH, 0) == -1) {
            perror("recv");
            close(client_socket);
            continue;
        }

        // Add the client to the array of clients
        int i;
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket == 0) {
                clients[i].socket = client_socket;
                strcpy(clients[i].name, name);
                break;
            }
        }

        // Send a welcome message to the client
        char welcome_message[MAX_MESSAGE_LENGTH];
        sprintf(welcome_message, "Welcome to the chat server, %s!\n", name);
        if (send(client_socket, welcome_message, strlen(welcome_message), 0) == -1) {
            perror("send");
            close(client_socket);
            continue;
        }

        // Broadcast the new client's name to all other clients
        char broadcast_message[MAX_MESSAGE_LENGTH];
        sprintf(broadcast_message, "%s has joined the chat.\n", name);
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket != 0 && clients[i].socket != client_socket) {
                if (send(clients[i].socket, broadcast_message, strlen(broadcast_message), 0) == -1) {
                    perror("send");
                    close(clients[i].socket);
                    continue;
                }
            }
        }

        // Handle incoming messages from the client
        while (1) {
            char message[MAX_MESSAGE_LENGTH];
            if (recv(client_socket, message, MAX_MESSAGE_LENGTH, 0) == -1) {
                perror("recv");
                close(client_socket);
                break;
            }

            // Broadcast the message to all other clients
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i].socket != 0 && clients[i].socket != client_socket) {
                    if (send(clients[i].socket, message, strlen(message), 0) == -1) {
                        perror("send");
                        close(clients[i].socket);
                        continue;
                    }
                }
            }
        }

        // Remove the client from the array of clients
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket == client_socket) {
                clients[i].socket = 0;
                strcpy(clients[i].name, "");
                break;
            }
        }

        // Broadcast the client's departure to all other clients
        char departure_message[MAX_MESSAGE_LENGTH];
        sprintf(departure_message, "%s has left the chat.\n", name);
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket != 0) {
                if (send(clients[i].socket, departure_message, strlen(departure_message), 0) == -1) {
                    perror("send");
                    close(clients[i].socket);
                    continue;
                }
            }
        }
    }

    // Close the server socket
    close(server_socket);

    return EXIT_SUCCESS;
}