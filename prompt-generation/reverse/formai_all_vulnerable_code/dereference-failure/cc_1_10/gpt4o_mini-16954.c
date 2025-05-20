//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>

#define PORT 8080
#define MAX_PENDING_CONNECTIONS 5
#define BUFFER_SIZE 4096
#define ALLOWED_IP "192.168.1.100" // Change this to the allowed IP address

// Function to check if the incoming IP matches the allowed IP
int allowed_ip(const char *client_ip) {
    return strcmp(client_ip, ALLOWED_IP) == 0;
}

// Function to handle incoming connections
void handle_connection(int client_socket, struct sockaddr_in client_addr) {
    char buffer[BUFFER_SIZE];
    char *client_ip = inet_ntoa(client_addr.sin_addr);
    
    printf("Connection attempt from %s\n", client_ip);
    
    // Check if the connecting IP is allowed
    if (!allowed_ip(client_ip)) {
        printf("Connection from %s is blocked!\n", client_ip);
        close(client_socket);
        return;
    }
    
    // Allow the connection and communicate with the client
    const char *message = "Welcome to the firewall protected server!\n";
    send(client_socket, message, strlen(message), 0);

    // Read data from the client
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0'; // null-terminate the string
        printf("Received from %s: %s\n", client_ip, buffer);
    }
    
    // Close the client socket
    close(client_socket);
    printf("Connection from %s ended.\n", client_ip);
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Setup server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    server_addr.sin_port = htons(PORT);
    
    // Bind socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    // Start listening
    if (listen(server_socket, MAX_PENDING_CONNECTIONS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Firewall Server is listening on port %d\n", PORT);
    
    while (1) {
        // Accept incoming connection
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // Move to the next iteration
        }
        
        // Handle the connection
        handle_connection(client_socket, client_addr);
    }
    
    // Cleanup
    close(server_socket);
    return 0;
}