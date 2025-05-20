//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Structure to hold client data
struct client_data {
    int socket;
    struct sockaddr_in address;
};

// Function to log messages
void log_message(const char *message) {
    printf("[LOG]: %s\n", message);
}

// Function to handle client requests
void *client_handler(void *arg) {
    struct client_data *client = (struct client_data *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    log_message("Client connected!");
    while ((bytes_read = recv(client->socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        log_message("Received message from client:");
        printf("%s\n", buffer);

        // Echo the message back to the client
        send(client->socket, buffer, bytes_read, 0);
    }

    log_message("Client disconnected!");
    close(client->socket);
    free(client);
    return NULL;
}

// Function to create a server and manage clients
void create_server() {
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    pthread_t thread_id;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to the address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind Failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen Failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    log_message("Server is up and running, waiting for connections...");

    while (1) {
        // Accept clients
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_length)) < 0) {
            perror("Accept Failed");
            continue;
        }

        log_message("New client connected!");

        struct client_data *client = malloc(sizeof(struct client_data));
        client->socket = client_fd;
        client->address = client_address;

        // Create a new thread for the client
        if (pthread_create(&thread_id, NULL, client_handler, (void *)client) != 0) {
            log_message("Failed to create thread for client!");
            close(client_fd);
            free(client);
        }
        
        pthread_detach(thread_id); // Allow thread to be cleaned up once done
    }

    close(server_fd);
}

// Main function
int main() {
    create_server();
    return 0;
}