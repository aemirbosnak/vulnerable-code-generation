//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

void handle_connection(int client_socket);
bool send_data(int socket, const char* data);
bool receive_data(int socket, char* buffer, size_t buffer_size);

int main(int argc, char const *argv[]) {
    
    // Create the socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create server socket");
        return EXIT_FAILURE;
    }
    
    // Initialize the address struct
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket to the address
    if (bind(server_socket, (struct sockaddr*)&address, sizeof(address)) == -1) {
        perror("Failed to bind server socket");
        return EXIT_FAILURE;
    }
    
    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Failed to listen for connections");
        return EXIT_FAILURE;
    }
    
    printf("Server listening on port %d\n", PORT);
    
    // Accept incoming connections
    struct sockaddr_in client_address;
    int client_socket;
    socklen_t address_size = sizeof(client_address);
    while ((client_socket = accept(server_socket, (struct sockaddr*)&client_address, &address_size))) {
        
        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // Handle the client's requests
        handle_connection(client_socket);
        
        printf("Client disconnected\n");
        
        // Clean up the client socket
        close(client_socket);
    }
    
    // Clean up the server socket
    close(server_socket);
    
    return EXIT_SUCCESS;
}

void handle_connection(int client_socket) {
    
    char buffer[MAX_BUFFER_SIZE];
    
    while (true) {
        
        // Receive client request
        if (!receive_data(client_socket, buffer, MAX_BUFFER_SIZE)) {
            printf("Failed to receive data from client\n");
            break;
        }
        
        // Process client request
        if (strcmp(buffer, "quit") == 0) {
            printf("Client requested to quit\n");
            break;
        }
        else if (strcmp(buffer, "hello") == 0) {
            printf("Client said hello\n");
            if (!send_data(client_socket, "Hello, client!")) {
                printf("Failed to send data to client\n");
                break;
            }
        }
        else {
            printf("Unknown command from client\n");
            if (!send_data(client_socket, "Unknown command!")) {
                printf("Failed to send data to client\n");
                break;
            }
        }
        
    }
}

bool send_data(int socket, const char* data) {
    
    size_t data_length = strlen(data);
    size_t bytes_sent = 0;
    
    while (bytes_sent < data_length) {
        
        ssize_t result = send(socket, data + bytes_sent, data_length - bytes_sent, 0);
        
        if (result == -1) {
            perror("Failed to send data to socket");
            return false;
        }
        
        bytes_sent += (size_t)result;
    }
    
    return true;
}

bool receive_data(int socket, char* buffer, size_t buffer_size) {
    
    size_t bytes_received = 0;
    
    while (bytes_received < buffer_size) {
        
        ssize_t result = recv(socket, buffer + bytes_received, buffer_size - bytes_received, 0);
        
        if (result == -1) {
            perror("Failed to receive data from socket");
            return false;
        }
        else if (result == 0) {
            printf("Client disconnected unexpectedly\n");
            return false;
        }
        
        bytes_received += (size_t)result;
        
        // Check for end of message
        if (bytes_received >= 2 && buffer[bytes_received - 2] == '\r' && buffer[bytes_received - 1] == '\n') {
            buffer[bytes_received - 2] = '\0';
            break;
        }
    }
    
    return true;
}