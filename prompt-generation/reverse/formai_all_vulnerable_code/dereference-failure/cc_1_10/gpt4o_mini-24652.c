//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

void *handle_client(void *socket_desc);

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} client_t;

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    // Define the server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Binding the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        client_t *new_client = malloc(sizeof(client_t));
        new_client->addr_len = addrlen;
        new_client->socket = accept(server_fd, (struct sockaddr *)&new_client->address, 
                                    (socklen_t*)&new_client->addr_len);
        if (new_client->socket < 0) {
            perror("Accept failed");
            free(new_client);
            continue;
        }

        printf("New connection accepted.\n");

        // Create a thread to handle the new client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void*)new_client) != 0) {
            perror("Failed to create thread");
            free(new_client);
            continue;
        }
        
        // Detach the thread so we don't have to join later
        pthread_detach(tid);
    }

    // Close the server socket
    close(server_fd);
    return 0;
}

void *handle_client(void *socket_desc) {
    client_t *client = (client_t *)socket_desc;
    int sock = client->socket;
    char buffer[BUFFER_SIZE];
    int read_size;

    // Communication loop
    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the received data
        printf("Received: %s\n", buffer);

        // Echo the message back to client
        send(sock, buffer, read_size, 0);
    }

    if (read_size == 0) {
        printf("Client disconnected.\n");
    } else if (read_size == -1) {
        perror("Recv failed");
    }

    // Clean up
    free(client);
    close(sock);
    return NULL;
}