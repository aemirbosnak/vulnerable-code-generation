//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void *client_handler(void *arg);

typedef struct {
    int socket;
    struct sockaddr_in address;
} client_info;

int main() {
    int server_socket, client_socket, addr_len, opt = 1;
    struct sockaddr_in address;
    pthread_t thread_id;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options for the socket
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Define the server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);
    
    // Accept clients
    while (1) {
        client_info *cli = malloc(sizeof(client_info));
        addr_len = sizeof(cli->address);
        cli->socket = accept(server_socket, (struct sockaddr *)&cli->address, (socklen_t*)&addr_len);
        
        if (cli->socket < 0) {
            perror("Accept failed");
            free(cli);
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(cli->address.sin_addr), ntohs(cli->address.sin_port));

        // Create a separate thread for each client
        if (pthread_create(&thread_id, NULL, client_handler, cli) != 0) {
            perror("Thread creation failed");
            free(cli);
        }
    }

    // Close the server socket (this will never be reached in this example)
    close(server_socket);
    return 0;
}

void *client_handler(void *arg) {
    client_info *cli = (client_info *)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(cli->socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the received string
        printf("Client %s:%d says: %s\n", inet_ntoa(cli->address.sin_addr), ntohs(cli->address.sin_port), buffer);
        
        // Echo the message back to the client
        send(cli->socket, buffer, read_size, 0);
    }

    if (read_size == 0) {
        printf("Client disconnected: %s:%d\n", inet_ntoa(cli->address.sin_addr), ntohs(cli->address.sin_port));
    } else {
        perror("Receive failed");
    }

    // Clean up
    close(cli->socket);
    free(cli);
    return 0;
}