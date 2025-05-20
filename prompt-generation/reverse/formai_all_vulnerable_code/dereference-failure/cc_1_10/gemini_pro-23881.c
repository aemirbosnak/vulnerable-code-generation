//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>

#define PORT 8080
#define MAX_CONNECTIONS 5
#define MAX_BUFFER_SIZE 1024

// Global variables
int server_socket_fd;
int client_socket_fds[MAX_CONNECTIONS];
int num_connections = 0;

// Function to handle client connections
void handle_client(int client_socket_fd) {
    char buffer[MAX_BUFFER_SIZE];
    int num_bytes_received;

    // Receive data from the client
    num_bytes_received = recv(client_socket_fd, buffer, MAX_BUFFER_SIZE, 0);

    // Check if the client has disconnected
    if (num_bytes_received == 0) {
        printf("Client disconnected\n");
        close(client_socket_fd);
        return;
    }

    // Parse the client request
    char *command = strtok(buffer, " ");
    char *argument = strtok(NULL, " ");

    // Handle the client request
    if (strcmp(command, "ON") == 0) {
        // Turn on the light
        printf("Turning on the light\n");
        send(client_socket_fd, "OK", 2, 0);
    } else if (strcmp(command, "OFF") == 0) {
        // Turn off the light
        printf("Turning off the light\n");
        send(client_socket_fd, "OK", 2, 0);
    } else if (strcmp(command, "STATUS") == 0) {
        // Get the light status
        printf("Getting the light status\n");
        send(client_socket_fd, "ON", 2, 0);
    } else {
        // Send an error message
        printf("Invalid command\n");
        send(client_socket_fd, "ERROR", 5, 0);
    }

    // Close the client connection
    close(client_socket_fd);
}

// Function to handle new client connections
void handle_new_connection(int server_socket_fd) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_socket_fd;

    // Accept the new connection
    client_socket_fd = accept(server_socket_fd, (struct sockaddr *) &client_addr, &client_addr_len);
    if (client_socket_fd < 0) {
        perror("accept");
        return;
    }

    // Add the new connection to the list of active connections
    client_socket_fds[num_connections] = client_socket_fd;
    num_connections++;

    // Create a new thread to handle the client connection
    pthread_t client_thread;
    pthread_create(&client_thread, NULL, (void *) handle_client, (void *) client_socket_fd);
}

// Function to initialize the server
void init_server() {
    struct sockaddr_in server_addr;

    // Create the server socket
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    // Bind the server socket to the server address
    if (bind(server_socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket_fd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(1);
    }
}

// Function to handle Ctrl+C
void handle_sigint(int signum) {
    // Close the server socket
    close(server_socket_fd);

    // Close all client connections
    for (int i = 0; i < num_connections; i++) {
        close(client_socket_fds[i]);
    }

    // Exit the program
    exit(0);
}

// Main function
int main() {
    // Initialize the server
    init_server();

    // Handle Ctrl+C
    signal(SIGINT, handle_sigint);

    // Main loop
    while (1) {
        // Handle new client connections
        handle_new_connection(server_socket_fd);
    }

    return 0;
}