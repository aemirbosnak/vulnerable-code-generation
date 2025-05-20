//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function declarations
void *handle_client(void *socket_desc);
void error_handling(const char *message);

int main() {
    int server_fd, client_socket, *new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error_handling("Socket creation failed");
    }
    
    // Preparing the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("Binding failed");
    }
    
    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        error_handling("Listening failed");
    }
    
    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accepting incoming connections
        client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            error_handling("Accept failed");
        }
        
        printf("Connection accepted\n");
        
        // Creating a thread for each client connection
        pthread_t client_thread;
        new_sock = malloc(1);
        *new_sock = client_socket;
        if (pthread_create(&client_thread, NULL, handle_client, (void *)new_sock) < 0) {
            error_handling("Failed to create thread");
        }
        
        // Detaching the thread so that it cleans up after itself
        pthread_detach(client_thread);
    }
    
    close(server_fd);
    return 0;
}

void *handle_client(void *socket_desc) {
    int sock = *(int*)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;
    
    // Communicate with the client
    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        // Null-terminate the received data to make it a proper string
        buffer[read_size] = '\0';
        
        printf("Client: %s\n", buffer);
        
        // Echo the message back to the client
        send(sock, buffer, read_size, 0);
    }
    
    if (read_size == 0) {
        printf("Client disconnected\n");
    } else if (read_size == -1) {
        error_handling("recv failed");
    }
    
    // Clean up
    free(socket_desc);
    close(sock);
    return 0;
}

void error_handling(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}