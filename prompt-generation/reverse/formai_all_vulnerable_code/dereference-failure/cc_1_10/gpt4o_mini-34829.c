//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *args);

typedef struct {
    int client_socket;
    struct sockaddr_in client_address;
} client_info_t;

int main() {
    int server_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        // Accept a new connection
        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        
        printf("New connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // Create a thread to handle the client
        pthread_t thread_id;
        client_info_t *client_info = malloc(sizeof(client_info_t));
        client_info->client_socket = client_socket;
        client_info->client_address = client_address;

        if (pthread_create(&thread_id, NULL, handle_client, (void*)client_info) != 0) {
            perror("Thread creation failed");
            close(client_socket);
            free(client_info);
        }
        pthread_detach(thread_id); // Detach the thread for automatic cleanup
    }

    close(server_socket);
    return 0;
}

void *handle_client(void *args) {
    client_info_t *client_info = (client_info_t*)args;
    int client_socket = client_info->client_socket;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Communication loop
    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer)-1, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("Received: %s\n", buffer);

        // Echo the message back
        send(client_socket, buffer, bytes_read, 0);
    }

    if (bytes_read == -1) {
        perror("Recv failed");
    } else {
        printf("Client disconnected\n");
    }

    close(client_socket);
    free(client_info);
    return NULL;
}