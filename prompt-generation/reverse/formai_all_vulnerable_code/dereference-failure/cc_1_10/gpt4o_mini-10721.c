//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10            // Maximum number of clients
#define BUFFER_SIZE 1024          // Buffer size for messages
#define SERVER_PORT 8080          // Default server port

// Function prototypes
void *handle_client(void *client_socket);
void start_server(int port);
void print_usage(const char *prog_name);

int main(int argc, char *argv[]) {
    int port = SERVER_PORT;

    if (argc > 1) {
        port = atoi(argv[1]);
        if (port <= 0 || port > 65535) {
            fprintf(stderr, "Invalid port number. Using default port %d\n", SERVER_PORT);
            port = SERVER_PORT;
        }
    }

    start_server(port);
    return 0;
}

void start_server(int port) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t tid;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", port);

    // Accept clients in a loop
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        printf("Client connected!\n");

        // Create a thread for each client
        pthread_create(&tid, NULL, handle_client, (void *)(intptr_t)client_socket);
        pthread_detach(tid); // Free resources when thread finishes
    }

    close(server_socket);
}

void *handle_client(void *client_socket) {
    int sock = (intptr_t)client_socket;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the received string
        printf("Received: %s", buffer);

        // Echo back the message
        send(sock, buffer, bytes_received, 0);
    }

    if (bytes_received == 0) {
        printf("Client disconnected.\n");
    } else {
        perror("recv failed");
    }
    close(sock);
    return NULL;
}

// Print usage information
void print_usage(const char *prog_name) {
    printf("Usage: %s [port]\n", prog_name);
}