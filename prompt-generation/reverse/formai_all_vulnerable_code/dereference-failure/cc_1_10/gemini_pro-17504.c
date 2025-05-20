//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum size of the request buffer
#define MAX_REQUEST_SIZE 1024

// Define the maximum size of the response buffer
#define MAX_RESPONSE_SIZE 1024

// Define the default response message
#define DEFAULT_RESPONSE "<h1>Welcome to our website!</h1>"

// Main function
int main() {
    // Create a new socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Error listening for connections");
        return 1;
    }

    // Loop forever, accepting connections and sending responses
    while (1) {
        // Accept a new connection
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("Error accepting connection");
            continue;
        }

        // Receive the request from the client
        char request[MAX_REQUEST_SIZE];
        int request_length = recv(client_socket, request, MAX_REQUEST_SIZE, 0);
        if (request_length == -1) {
            perror("Error receiving request");
            continue;
        }

        // Parse the request
        char *method = strtok(request, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");

        // Check if the request is valid
        if (strcmp(method, "GET") != 0) {
            // Send an error response
            char error_response[MAX_RESPONSE_SIZE];
            sprintf(error_response, "HTTP/1.1 405 Method Not Allowed\r\nContent-Type: text/plain\r\nContent-Length: 16\r\n\r\nMethod Not Allowed");
            send(client_socket, error_response, strlen(error_response), 0);

            // Close the client socket
            close(client_socket);

            continue;
        }

        // Send the response to the client
        char response[MAX_RESPONSE_SIZE];
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n%s", strlen(DEFAULT_RESPONSE), DEFAULT_RESPONSE);
        send(client_socket, response, strlen(response), 0);

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}