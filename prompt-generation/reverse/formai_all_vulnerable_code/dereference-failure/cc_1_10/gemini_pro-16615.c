//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to handle HTTP requests
void handle_request(int client_socket) {
    // Read the HTTP request from the client
    char request[1024];
    recv(client_socket, request, sizeof(request), 0);

    // Parse the HTTP request
    char *method = strtok(request, " ");
    char *uri = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Check if the request is valid
    if (strcmp(method, "GET") != 0) {
        send(client_socket, "HTTP/1.1 405 Method Not Allowed\r\n\r\n", 33, 0);
        return;
    }

    if (strcmp(version, "HTTP/1.1") != 0) {
        send(client_socket, "HTTP/1.1 505 HTTP Version Not Supported\r\n\r\n", 43, 0);
        return;
    }

    // Send the HTTP response
    char response[1024];
    sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\nHello, world!", strlen("Hello, world!"));
    send(client_socket, response, strlen(response), 0);

    // Close the client socket
    close(client_socket);
}

// Main function
int main() {
    // Create a server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the server socket to be reusable
    int reuseaddr = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr)) == -1) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    // Bind the server socket to the port 8080
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept incoming connections
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Handle the HTTP request
        handle_request(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return EXIT_SUCCESS;
}