//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10
#define BUF_SIZE 1024

// Helper function to send a response to the client
void send_response(int client_socket, char* response) {
    write(client_socket, response, strlen(response));
}

// Helper function to receive a request from the client
char* recv_request(int client_socket) {
    char* request = malloc(BUF_SIZE);
    read(client_socket, request, BUF_SIZE);
    return request;
}

// Function to handle a client connection
void handle_client(int client_socket) {
    char* request = recv_request(client_socket);
    char* response;

    // Determine the type of request and generate the appropriate response
    if (strstr(request, "GET / HTTP/1.1")) {
        response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, world!</h1></body></html>";
    } else {
        response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<html><body><h1>404 Not Found</h1></body></html>";
    }

    // Send the response to the client
    send_response(client_socket, response);

    // Close the client socket
    close(client_socket);
}

// Function to start the server
void start_server(int port) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind the server socket to the address
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections and handle them in a loop
    while (1) {
        client_addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("accept");
            exit(1);
        }

        handle_client(client_socket);
    }

    // Close the server socket
    close(server_socket);
}

// Main function
int main(int argc, char** argv) {
    // Check if the port number was provided
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Start the server
    start_server(atoi(argv[1]));

    return 0;
}