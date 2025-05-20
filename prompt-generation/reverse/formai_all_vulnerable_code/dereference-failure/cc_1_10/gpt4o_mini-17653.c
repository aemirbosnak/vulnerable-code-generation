//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <pthread.h>
#include <signal.h>

// Define constants
#define PORT 8080
#define BUFFER_SIZE 2048
#define MAX_CONNECTIONS 100

// Function to handle client requests
void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    ssize_t read_size;

    // Initial greet message
    char *greeting = "Welcome to the Imaginative Firewall! Type 'exit' to disconnect.\n";
    send(sock, greeting, strlen(greeting), 0);

    while ((read_size = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        // Null terminate the received data
        buffer[read_size] = '\0';

        // Check for "exit" command
        if (strcmp(buffer, "exit\n") == 0) {
            char *farewell = "Goodbye! Your connection has been terminated.\n";
            send(sock, farewell, strlen(farewell), 0);
            break;
        }

        // Basic command simulation
        printf("Received: %s", buffer);
        char *response = "Your message has reached the Imaginative Firewall!\n";
        send(sock, response, strlen(response), 0);
    }

    if (read_size == 0) {
        printf("Client disconnected.\n");
        fflush(stdout);
    } else {
        perror("recv failed");
    }

    close(sock);
    free(client_socket);
    return NULL;
}

// Function to initiate the firewall server
void start_firewall() {
    int server_fd, new_socket, *new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t thread_id;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set firewall address info
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Set the socket to listen for connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Imaginative Firewall running on port %d...\n", PORT);
    
    // Accept clients in a loop
    while (1) {
        new_sock = malloc(1);
        *new_sock = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (*new_sock < 0) {
            perror("Accept failed");
            free(new_sock);
            continue;
        }

        printf("New client connected!\n");

        // Create a thread to handle the client
        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_sock) < 0) {
            perror("Could not create thread");
            free(new_sock);
        }
    }

    // Cleanup
    close(server_fd);
}

// Signal handler for graceful shutdown
void sigint_handler(int sig) {
    printf("\nShutting down the Imaginative Firewall gracefully...\n");
    exit(0);
}

// Entry point of the program
int main() {
    // Register signal handler
    signal(SIGINT, sigint_handler);

    // Start the firewall server
    start_firewall();

    return 0;
}