//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <pthread.h>

#define PORT 5555
#define MAX_CLIENTS 10

// Global variables
int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

// Function prototypes
void handle_client(int client_socket);
void handle_client_message(int client_socket, char *message);
void cleanup();

int main() {
    // Create a server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(1);
    }

    // Set the server socket options
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("Error setting server socket options");
        exit(1);
    }

    // Bind the server socket to the port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding server socket to port");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    // Set up signal handler for SIGINT
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = cleanup;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error setting up signal handler for SIGINT");
        exit(1);
    }

    // Main server loop
    while (1) {
        // Accept incoming connections
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket == -1) {
            perror("Error accepting incoming connection");
            continue;
        }

        // Add the client socket to the list of client sockets
        client_sockets[num_clients] = client_socket;
        num_clients++;

        // Create a new thread to handle the client
        pthread_t thread;
        if (pthread_create(&thread, NULL, (void *)handle_client, (void *)client_socket) != 0) {
            perror("Error creating thread to handle client");
            close(client_socket);
            continue;
        }
    }

    return 0;
}

void handle_client(int client_socket) {
    // Receive messages from the client
    while (1) {
        char message[1024];
        int message_len = recv(client_socket, message, 1024, 0);
        if (message_len == -1) {
            perror("Error receiving message from client");
            break;
        } else if (message_len == 0) {
            // Client disconnected
            break;
        }

        // Handle the message
        handle_client_message(client_socket, message);
    }

    // Close the client socket
    close(client_socket);

    // Remove the client socket from the list of client sockets
    int i;
    for (i = 0; i < num_clients; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = client_sockets[num_clients - 1];
            num_clients--;
            break;
        }
    }
}

void handle_client_message(int client_socket, char *message) {
    // Parse the message
    char *command = strtok(message, " ");
    char *args = strtok(NULL, "");

    // Handle the command
    if (strcmp(command, "on") == 0) {
        // Turn on the light
        printf("Turning on the light\n");
        send(client_socket, "OK", 2, 0);
    } else if (strcmp(command, "off") == 0) {
        // Turn off the light
        printf("Turning off the light\n");
        send(client_socket, "OK", 2, 0);
    } else if (strcmp(command, "status") == 0) {
        // Get the light status
        printf("Getting the light status\n");
        send(client_socket, "OK", 2, 0);
    } else {
        // Invalid command
        printf("Invalid command\n");
        send(client_socket, "ERROR", 5, 0);
    }
}

void cleanup() {
    // Close the server socket
    close(server_socket);

    // Close all the client sockets
    int i;
    for (i = 0; i < num_clients; i++) {
        close(client_sockets[i]);
    }

    exit(0);
}