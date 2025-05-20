//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define DEFAULT_PORT 8080
#define DEFAULT_MESSAGE "Hello, Client!"
#define BUFFER_SIZE 1024

// Function to handle client connections
void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    free(arg); // Free the pointer allocated for this thread
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Communicate with the client
    while ((bytes_read = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the received string
        printf("Received from client: %s\n", buffer);

        // Send a configurable response back to the client
        const char *response_message = DEFAULT_MESSAGE;
        send(client_socket, response_message, strlen(response_message), 0);
    }

    // Handle disconnection
    if (bytes_read == -1) {
        perror("recv failed");
    }
    close(client_socket);
    return NULL;
}

// Function to start the server
void start_server(int port) {
    int server_socket, *new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server specs
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

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", port);

    // Accept incoming connections and create a new thread for each
    while (1) {
        new_socket = malloc(sizeof(int)); // Allocate memory for client socket
        if ((*new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            free(new_socket);
            continue;
        }

        printf("Connected with client socket: %d\n", *new_socket);
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, new_socket);
        pthread_detach(thread_id); // Detach thread to avoid memory leak
    }

    close(server_socket);
}

// Client function
void start_client(const char *server_ip, int port) {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Communicate with the server
    while (1) {
        printf("Client: Enter message (type 'exit' to quit): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;  // Remove newline character

        if (strcmp(buffer, "exit") == 0) {
            break; // Exit if user types 'exit'
        }

        send(client_socket, buffer, strlen(buffer), 0);

        // Receive server response
        recv(client_socket, buffer, BUFFER_SIZE, 0);
        printf("Server: %s\n", buffer);
    }

    close(client_socket);
}

// Main function to decide whether to run server or client
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [server|client] [ip_address] [port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *mode = argv[1];
    if (strcmp(mode, "server") == 0) {
        int port = (argc >= 3) ? atoi(argv[2]) : DEFAULT_PORT;
        start_server(port);
    } else if (strcmp(mode, "client") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Usage: %s client [ip_address] [port]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
        const char *server_ip = argv[2];
        int port = atoi(argv[3]);
        start_client(server_ip, port);
    } else {
        fprintf(stderr, "Unknown mode: %s. Use 'server' or 'client'.\n", mode);
        exit(EXIT_FAILURE);
    }

    return 0;
}