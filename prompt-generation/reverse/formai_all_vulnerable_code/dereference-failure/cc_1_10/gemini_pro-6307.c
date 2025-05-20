//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum number of concurrent connections
#define MAX_CONNECTIONS 10

// Structure to store client information
typedef struct {
    int socket_fd;
    struct sockaddr_in address;
    char *request;
} Client;

// Function to handle client requests
void handle_client(Client *client) {
    // Receive the request from the client
    char buffer[1024];
    int bytes_received = recv(client->socket_fd, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("Error receiving request");
        return;
    }
    client->request = malloc(bytes_received + 1);
    memcpy(client->request, buffer, bytes_received);
    client->request[bytes_received] = '\0';

    // Parse the request
    char *method = strtok(client->request, " ");
    char *path = strtok(NULL, " ");
    char *http_version = strtok(NULL, "\r\n");

    // Handle the request
    if (strcmp(method, "GET") == 0) {
        // Send the response
        char response[1024];
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, world!</h1>");
        int bytes_sent = send(client->socket_fd, response, strlen(response), 0);
        if (bytes_sent < 0) {
            perror("Error sending response");
            return;
        }
    } else {
        // Send an error response
        char response[1024];
        sprintf(response, "HTTP/1.1 405 Method Not Allowed\r\nContent-Type: text/html\r\n\r\n<h1>Method Not Allowed</h1>");
        int bytes_sent = send(client->socket_fd, response, strlen(response), 0);
        if (bytes_sent < 0) {
            perror("Error sending response");
            return;
        }
    }

    // Close the connection
    close(client->socket_fd);
    free(client->request);
    free(client);
}

// Main function
int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("Error setting socket options");
        return 1;
    }

    // Bind the socket to the port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket to port");
        return 1;
    }

    // Listen for connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("Error listening for connections");
        return 1;
    }

    // Accept connections
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Create a new client
        Client *client = malloc(sizeof(Client));
        client->socket_fd = client_socket;
        client->address = client_address;
        client->request = NULL;

        // Handle the client in a new thread
        pthread_t thread;
        pthread_create(&thread, NULL, (void *)handle_client, client);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}