//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *client_handler(void *socket_desc) {
    int sock = *(int*)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;
    
    // Send a welcome message to the client
    char *welcome_message = "Welcome to the echo server!\n";
    write(sock, welcome_message, strlen(welcome_message));
    
    // Keep listening for messages from the client
    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the received string
        
        // Echo the message back
        write(sock, buffer, read_size);
        
        // Optional: Print the received message on the server console
        printf("Client: %s", buffer);
    }
    
    if (read_size == 0) {
        printf("Client disconnected\n");
    } else {
        perror("recv failed");
    }
    
    // Cleanup and close this client socket
    close(sock);
    free(socket_desc);
    return NULL;
}

int main() {
    int server_fd, client_sock, *new_sock;
    struct sockaddr_in server, client;
    socklen_t client_size = sizeof(client);
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        return 1;
    }
    
    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }
    
    // Listen for incoming connections
    listen(server_fd, 3);
    printf("Server is listening on port %d\n", PORT);
    
    // Accept and incoming connection in a loop
    while ((client_sock = accept(server_fd, (struct sockaddr *)&client, &client_size))) {
        printf("Connection accepted\n");
        
        // Create a new thread for handling the client
        pthread_t thread_id;
        new_sock = malloc(1);
        *new_sock = client_sock;
        
        if (pthread_create(&thread_id, NULL, client_handler, (void*) new_sock) < 0) {
            perror("Could not create thread");
            return 1;
        }
        
        // Detach the thread to handle cleanup
        pthread_detach(thread_id);
    }
    
    if (client_sock < 0) {
        perror("Accept failed");
        return 1;
    }
    
    // Closing the server socket
    close(server_fd);
    return 0;
}