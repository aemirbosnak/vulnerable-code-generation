//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// Function to handle HTTP GET requests
void handle_get_request(int client_socket) {
    char request[1024];
    char response[2048];

    // Read the request from the client
    recv(client_socket, request, sizeof(request), 0);

    // Parse the request to get the path
    char *path = strtok(request, " ");

    // Handle the request based on the path
    if (strcmp(path, "/index.html") == 0) {
        // Send the index.html file
        sprintf(response, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<h1>Hello from the web server!</h1>");
    } else {
        // Send a 404 Not Found error
        sprintf(response, "HTTP/1.1 404 Not Found\nContent-Type: text/html\n\n<h1>404 Not Found</h1>");
    }

    // Send the response to the client
    send(client_socket, response, strlen(response), 0);
}

int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Bind the socket to an address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    // Listen for incoming connections
    listen(server_socket, 5);

    while (1) {
        // Accept an incoming connection
        int client_socket = accept(server_socket, NULL, NULL);

        // Handle the client request
        handle_get_request(client_socket);

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}