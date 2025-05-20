//FormAI DATASET v1.0 Category: Chat server ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define PORT 12345
#define BUFFER_SIZE 1024

void handle_client(int client_socket);

int main() {
    int server_socket;
    int client_socket;
    int opt_val = 1;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    socklen_t client_address_size;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        fprintf(stderr, "Error creating server socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof(opt_val)) == -1) {
        fprintf(stderr, "Error setting socket options: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Bind server socket to port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        fprintf(stderr, "Error binding server socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        fprintf(stderr, "Error listening for connections: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Chat server listening on port %d...\n", PORT);

    // Handle incoming client connections
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket == -1) {
            fprintf(stderr, "Error accepting client connection: %s\n", strerror(errno));
            continue;
        }

        printf("Accepted client connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        handle_client(client_socket);

        close(client_socket);
        printf("Closed client connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    }

    close(server_socket);
    printf("Chat server closed\n");

    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Send welcome message to client
    strcpy(buffer, "Welcome to the chat server! Type 'exit' to disconnect.\n");
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive messages from client
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_read == -1) {
            fprintf(stderr, "Error receiving data from client: %s\n", strerror(errno));
            break;
        }

        if (bytes_read == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Received message from client: %s", buffer);

        // Check for exit command from client
        if (strncmp(buffer, "exit", 4) == 0) {
            printf("Client requested to disconnect\n");
            break;
        }

        // Send message to all connected clients
        send(client_socket, buffer, strlen(buffer), 0);
    }
}