//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void handle_client(int client_socket);
void log_event(const char *message);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    int opt = 1;
    
    // Create socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Define server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    log_event("Firewall is running...");

    while (1) {
        // Accept a new client
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        log_event("New client connected");

        // Handle the client
        if (!fork()) { // In the child process
            close(server_socket); // Close listening socket in child
            handle_client(client_socket);
            close(client_socket);
            exit(0);
        }
        close(client_socket); // Close socket for the parent
    }

    // This part should never be reached
    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t read_size;

    // Loop to receive messages from the client
    while ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null terminate the received string

        // Simple filtering logic (firewall rule)
        if (strstr(buffer, "BLOCK") != NULL) {
            log_event("Blocked message received from client.");
            const char *response = "Your message was blocked!\n";
            send(client_socket, response, strlen(response), 0);
            continue;
        }

        // Log and echo back accepted messages
        log_event("Message accepted from client.");
        send(client_socket, buffer, read_size, 0);
    }

    if (read_size == 0) {
        log_event("Client disconnected.");
    } else if (read_size < 0) {
        perror("recv failed");
    }
}

void log_event(const char *message) {
    // Log events to the console with a timestamp
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline

    printf("[%s] %s\n", timestamp, message);
}