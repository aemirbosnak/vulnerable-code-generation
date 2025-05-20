//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Structure to represent a client connection
typedef struct {
    int sock;   // Socket descriptor
    char name[50]; // Client name
} client_t;

// Function to create a client connection
client_t *create_client(int sock) {
    client_t *client = (client_t *)malloc(sizeof(client_t));
    client->sock = sock;
    return client;
}

// Function to send a message to a client
void send_message(int sock, char *message) {
    send(sock, message, strlen(message), 0);
}

// Function to receive a message from a client
char *receive_message(int sock) {
    char buffer[BUFFER_SIZE];
    recv(sock, buffer, BUFFER_SIZE, 0);
    return buffer;
}

// Function to handle client connections
void handle_clients(int sock) {
    // Accept incoming client connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        accept(sock, (struct sockaddr *)&client_addr, &client_len);

        // Create a new client structure
        client_t *client = create_client(client_addr.sin_port);

        // Print the client's name and address
        printf("New client connection from %s:%d\n",
            inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle client messages
        while (1) {
            char *message = receive_message(client->sock);
            printf("Received message from client: %s\n", message);

            // Send a response message back to the client
            send_message(client->sock, "Hello, client!");
        }
    }
}

int main() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a specific address and port
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Handle client connections
    while (1) {
        handle_clients(sock);
    }

    return 0;
}