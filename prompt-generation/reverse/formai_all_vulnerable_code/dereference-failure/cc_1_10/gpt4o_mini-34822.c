//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAXCLIENTS 5
#define BUFFER_SIZE 1024

// Client structure
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} client_t;

// Function to handle client communication
void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    client_t *client = (client_t *)arg;
    int nbytes;

    // Receive and send data
    while ((nbytes = recv(client->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[nbytes] = '\0';  // Null-terminate the string
        printf("Received from client: %s\n", buffer);

        // Echo back the message to the client
        send(client->socket, buffer, nbytes, 0);
    }

    // Handle disconnection
    if (nbytes == 0) {
        printf("Client disconnected: %d\n", client->socket);
    } else {
        perror("recv");
    }

    // Close client socket and free memory
    close(client->socket);
    free(client);
    return NULL;
}

// Main server function
int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    pthread_t thread_id;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAXCLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept clients continuously
    while (1) {
        // Accept a new client
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // Print client IP address
        printf("Client connected: %s:%d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create a new client structure
        client_t *client = malloc(sizeof(client_t));
        client->socket = client_socket;
        client->address = client_addr;
        client->addr_len = client_addr_len;

        // Create a new thread for the client
        if (pthread_create(&thread_id, NULL, handle_client, (void *)client) != 0) {
            perror("Thread creation failed");
            free(client);
        }
        
        // Detach the thread to clean up resources automatically when done
        pthread_detach(thread_id);
    }

    // Close server socket (this will never be reached in this example)
    close(server_socket);
    return 0;
}