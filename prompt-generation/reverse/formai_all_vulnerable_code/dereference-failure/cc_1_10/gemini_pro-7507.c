//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Maximum number of clients
#define MAX_CLIENTS 10

// Port number
#define PORT 8080

// Structure to hold client information
typedef struct client_info {
    int socket_fd;
    char *username;
} client_info;

// Array of client information
client_info clients[MAX_CLIENTS];

// Database of key-value pairs
char *database[100];

// Function to handle client requests
void handle_client(int client_fd) {
    // Receive request from client
    char request[1024];
    recv(client_fd, request, sizeof(request), 0);

    // Parse request
    char *command = strtok(request, " ");
    char *key = strtok(NULL, " ");
    char *value = strtok(NULL, " ");

    // Handle request
    if (strcmp(command, "GET") == 0) {
        // Get value from database
        char *result = database[atoi(key)];

        // Send result to client
        send(client_fd, result, strlen(result), 0);
    } else if (strcmp(command, "SET") == 0) {
        // Set value in database
        database[atoi(key)] = strdup(value);

        // Send confirmation to client
        send(client_fd, "OK", 2, 0);
    } else {
        // Send error message to client
        send(client_fd, "ERROR", 5, 0);
    }

    // Close client connection
    close(client_fd);
}

int main() {
    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept connections and handle requests
    while (1) {
        // Accept connection from client
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        // Add client to array of clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket_fd == 0) {
                clients[i].socket_fd = client_fd;
                clients[i].username = NULL;
                break;
            }
        }

        // Handle client request in a separate thread
        pthread_t thread;
        if (pthread_create(&thread, NULL, (void *) handle_client, (void *) client_fd) < 0) {
            perror("pthread_create");
            continue;
        }
    }

    // Close server socket
    close(server_fd);

    return 0;
}