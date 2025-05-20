//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_MSG 100
#define BUFFER_SIZE 1000

// Function declarations
void* handle_client(void* arg);
void* handle_server(void* arg);

// Global variables
int num_clients = 0;
int server_socket;
char buffer[BUFFER_SIZE];

int main() {
    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Set the socket to be reusable
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Create a server address structure
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(5000);

    // Bind the socket to the address
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    // Listen for incoming connections
    listen(server_socket, MAX_CLIENTS);

    // Start server thread
    pthread_t server_thread;
    pthread_create(&server_thread, NULL, handle_server, NULL);

    // Main loop
    while (1) {
        // Accept a new connection
        int client_socket = accept(server_socket, NULL, NULL);

        // Start a new thread to handle the client
        pthread_t client_thread;
        pthread_create(&client_thread, NULL, handle_client, (void*) client_socket);

        // Increase the number of clients
        num_clients++;
    }

    // Join the server thread
    pthread_join(server_thread, NULL);

    // Close the socket
    close(server_socket);

    return 0;
}

void* handle_client(void* arg) {
    int client_socket = *((int*) arg);

    // Accept a message from the client
    bzero(buffer, BUFFER_SIZE);
    int n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error: Client disconnected\n");
        return NULL;
    }

    // Print the received message
    printf("Received message from client: %s\n", buffer);

    // Send a response back to the client
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, "Thank you for connecting!\n");
    send(client_socket, buffer, strlen(buffer), 0);

    // Close the client socket
    close(client_socket);

    return NULL;
}

void* handle_server(void* arg) {
    int server_socket = *((int*) arg);

    // Main loop
    while (1) {
        // Accept a new connection
        int client_socket = accept(server_socket, NULL, NULL);

        // Start a new thread to handle the client
        pthread_t client_thread;
        pthread_create(&client_thread, NULL, handle_client, (void*) client_socket);

        // Increase the number of clients
        num_clients++;
    }

    return NULL;
}