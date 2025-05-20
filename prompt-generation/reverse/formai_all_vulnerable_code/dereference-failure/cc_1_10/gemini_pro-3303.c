//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 8080

// Function to handle client requests
void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Receive the HTTP request from the client
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv");
        exit(1);
    }

    // Parse the HTTP request and extract the request method and URI
    char *request_line = strtok(buffer, "\r\n");
    char *request_method = strtok(request_line, " ");
    char *request_uri = strtok(NULL, " ");

    // Check if the request method is GET
    if (strcmp(request_method, "GET") != 0) {
        // Send a 405 Method Not Allowed response
        char *response = "HTTP/1.1 405 Method Not Allowed\r\n\r\n";
        send(client_socket, response, strlen(response), 0);
        close(client_socket);
        return;
    }

    // Check if the requested URI is "/"
    if (strcmp(request_uri, "/") == 0) {
        // Send a 200 OK response with the default index page
        char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Welcome to the Simple Web Server!</h1>";
        send(client_socket, response, strlen(response), 0);
    } else {
        // Send a 404 Not Found response
        char *response = "HTTP/1.1 404 Not Found\r\n\r\n";
        send(client_socket, response, strlen(response), 0);
    }

    // Close the client socket
    close(client_socket);
}

// Function to start the server
void start_server() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the server socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming client connections
    if (listen(server_socket, 5) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept incoming client connections
    while (1) {
        client_addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("accept");
            exit(1);
        }

        // Handle the client request in a separate thread
        pthread_t thread;
        pthread_create(&thread, NULL, (void *)handle_client, (void *)client_socket);
    }

    // Close the server socket
    close(server_socket);
}

int main() {
    // Start the server
    start_server();

    return 0;
}