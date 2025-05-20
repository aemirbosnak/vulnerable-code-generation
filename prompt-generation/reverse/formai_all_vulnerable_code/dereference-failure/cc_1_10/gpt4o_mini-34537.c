//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080              // Standard port number for the service
#define MAX_CLIENTS 5          // Maximum number of clients
#define BUFFER_SIZE 1024        // Size of the message buffer

// Function to handle communication with connected clients
void *handle_client(void *client_socket) {
    int sock = *(int*)client_socket;
    char buffer[BUFFER_SIZE];
    
    // Greetings and introduction
    char *welcome_msg = "Welcome to the Chat Server! Type 'exit' to leave.\n";
    send(sock, welcome_msg, strlen(welcome_msg), 0);

    // Loop for receiving messages
    while (1) {
        memset(buffer, 0, sizeof(buffer)); // Clear buffer
        int bytes_received = recv(sock, buffer, sizeof(buffer), 0);

        // Break if the client has disconnected
        if (bytes_received <= 0) {
            printf("Client disconnected.\n");
            break;
        }
        
        // Output received message to the server console
        printf("Received: %s", buffer);
        
        // Echoing the message to the client
        send(sock, buffer, bytes_received, 0);
        
        // Exit condition
        if (strncmp(buffer, "exit", 4) == 0) {
            printf("Client requested to exit.\n");
            break;
        }
    }

    close(sock); // Closing the client socket
    free(client_socket);
    return NULL;
}

// Main function to initialize the server
int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    // Defining server address structure
    address.sin_family = AF_INET;         // Use IPv4
    address.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP
    address.sin_port = htons(PORT);        // Convert port number to network byte order

    // Binding the socket to the given address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Chat Server is running on port %d.\n", PORT);

    // Server loop to accept clients
    while (1) {
        // Accept a client connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }
        
        printf("New client connected.\n");
        
        // Create a new thread for the client
        pthread_t tid;
        int *client_sock = malloc(sizeof(int));
        *client_sock = new_socket;
        
        if (pthread_create(&tid, NULL, handle_client, (void*)client_sock) != 0) {
            perror("Thread creation failed");
            free(client_sock);
        }
        pthread_detach(tid); // Automatically reclaim resources when thread terminates
    }

    // Cleanup
    close(server_fd); // Closing the server socket
    return 0;
}