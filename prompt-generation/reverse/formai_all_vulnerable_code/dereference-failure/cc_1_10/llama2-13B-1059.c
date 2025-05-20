//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

// Structure to store client information
struct client_info {
    int sock;
    char name[50];
};

// Function to create a new client socket
int create_client_socket(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating client socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding client socket");
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Function to handle client requests
void handle_client_requests(int sock) {
    char buffer[1024];
    int bytes_read;

    while (1) {
        // Receive data from client
        bytes_read = recv(sock, buffer, 1024, 0);
        if (bytes_read < 0) {
            perror("Error receiving data from client");
            exit(EXIT_FAILURE);
        }

        // Print received message
        printf("Received message from client: %s\n", buffer);

        // Handle request
        if (strcmp(buffer, "GET /") == 0) {
            char *message = "Hello, world!";
            send(sock, message, strlen(message), 0);
        } else if (strcmp(buffer, "GET /hello") == 0) {
            char *message = "Hello, client!";
            send(sock, message, strlen(message), 0);
        } else {
            printf("Invalid request\n");
        }
    }
}

// Function to create a new server socket
int create_server_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 3) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    return sock;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    int sock = create_server_socket();

    struct client_info *clients = malloc(sizeof(struct client_info));
    int client_sock = 0;

    while (1) {
        // Accept new client connection
        client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("Error accepting client connection");
            exit(EXIT_FAILURE);
        }

        struct client_info *new_client = malloc(sizeof(struct client_info));
        new_client->sock = client_sock;
        strcpy(new_client->name, "New client");
        clients = realloc(clients, (client_sock + 1) * sizeof(struct client_info));
        clients[client_sock] = *new_client;

        handle_client_requests(client_sock);
    }

    return 0;
}