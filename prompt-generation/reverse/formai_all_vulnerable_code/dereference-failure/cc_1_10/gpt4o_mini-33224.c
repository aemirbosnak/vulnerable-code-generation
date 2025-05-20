//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

void *handle_client(void *client_socket);
void send_message(int client_socket, const char *message);
void close_client_connection(int client_socket);

int main(void) {
    int server_socket, client_socket, *new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    pthread_t thread_id;
    
    // Create the main server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }
    
    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any address
    server_addr.sin_port = htons(PORT); // Specify the port number
    
    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    // Start listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);
    
    addr_size = sizeof(client_addr);
    
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size))) {
        printf("Connection established with client: %s:%d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        
        // Create a new thread for each client connection
        new_sock = malloc(1);
        *new_sock = client_socket;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_sock) != 0) {
            perror("Could not create thread");
            free(new_sock);
        }
        
        // Detach thread to free resources on completion
        pthread_detach(thread_id);
    }
    
    // Close the server socket
    if (client_socket < 0) {
        perror("Accept failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    return 0;
}

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char client_message[BUFFER_SIZE];
    
    // Introduce a bit of humor in the welcome message
    char welcome_msg[] = "Welcome to Knuth’s Quirky Socket Server! Type 'exit' to disconnect.\n";
    send_message(sock, welcome_msg);
    
    // Main loop to receive client messages
    while (1) {
        memset(client_message, 0, sizeof(client_message)); // Clear the buffer
        int read_size = recv(sock, client_message, sizeof(client_message)-1, 0);
        
        if (read_size <= 0) {
            printf("Client disconnected.\n");
            break;
        }
        
        // Print the received message
        printf("Client says: %s", client_message);
        
        // Check for exit command
        if (strcmp(client_message, "exit\n") == 0) {
            send_message(sock, "Goodbye! Hope to see you again!\n");
            break;
        }
        
        // Sending back an acknowledgment
        send_message(sock, "Message received! Keep chatting, friend!\n");
    }

    // Close the client connection
    close_client_connection(sock);
    free(client_socket); // Free the allocated memory for socket
    return 0;
}

void send_message(int client_socket, const char *message) {
    send(client_socket, message, strlen(message), 0);
}

void close_client_connection(int client_socket) {
    printf("Closing connection.\n");
    close(client_socket);
}