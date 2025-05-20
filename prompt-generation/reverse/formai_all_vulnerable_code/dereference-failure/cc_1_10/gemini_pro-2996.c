//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_REQUEST_SIZE 1024

// Client structure
typedef struct {
    int socket;
    struct sockaddr_in addr;
    char request[MAX_REQUEST_SIZE];
    int request_len;
} client_t;

// Global variables
client_t clients[MAX_CLIENTS];
int num_clients = 0;
int server_socket;

// Function to handle client requests
void handle_client(client_t *client) {
    // Parse the request
    char *method = strtok(client->request, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Check if the request is valid
    if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
        // Send a 400 Bad Request response
        char *response = "HTTP/1.1 400 Bad Request\r\n\r\n";
        send(client->socket, response, strlen(response), 0);
        return;
    }

    // Open the requested file
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        // Send a 404 Not Found response
        char *response = "HTTP/1.1 404 Not Found\r\n\r\n";
        send(client->socket, response, strlen(response), 0);
        return;
    }

    // Send a 200 OK response
    char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    send(client->socket, response, strlen(response), 0);

    // Send the file contents
    char buffer[1024];
    while (fread(buffer, 1, sizeof(buffer), file) > 0) {
        send(client->socket, buffer, strlen(buffer), 0);
    }

    // Close the file
    fclose(file);

    // Close the client socket
    close(client->socket);
}

// Function to accept new client connections
void accept_client() {
    // Create a new socket for the client
    int client_socket = accept(server_socket, (struct sockaddr *) &clients[num_clients].addr, (socklen_t *) sizeof(clients[num_clients].addr));
    if (client_socket < 0) {
        perror("accept");
        return;
    }

    // Add the client to the list of clients
    clients[num_clients].socket = client_socket;
    num_clients++;
}

// Main function
int main(int argc, char **argv) {
    // Create a new server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        return 1;
    }

    // Bind the server socket to the address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for client connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        return 1;
    }

    // Main loop
    while (1) {
        // Accept new client connections
        accept_client();

        // Handle client requests
        for (int i = 0; i < num_clients; i++) {
            handle_client(&clients[i]);
        }
    }

    // Close the server socket
    close(server_socket);

    return 0;
}