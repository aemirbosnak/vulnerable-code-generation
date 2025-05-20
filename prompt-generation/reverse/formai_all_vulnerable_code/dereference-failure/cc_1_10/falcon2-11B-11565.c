//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation error");
        return 1;
    }

    // Set up the socket's address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080); // The port that the server is listening on
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // The server's IP address

    // Bind the socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding error");
        return 1;
    }

    // Listen for incoming connections
    int backlog = 5;
    if (listen(server_socket, backlog) < 0) {
        perror("Listen error");
        return 1;
    }

    // Accept a connection from a client
    int client_socket = accept(server_socket, NULL, NULL);
    if (client_socket < 0) {
        perror("Accept error");
        return 1;
    }

    // Read the request from the client
    char request[1024];
    int bytes_read = read(client_socket, request, sizeof(request));
    if (bytes_read < 0) {
        perror("Read error");
        return 1;
    }

    // Send the request to the server
    char response[1024];
    snprintf(response, sizeof(response), "HTTP/1.1 200 OK\r\n\r\nHello, world!");
    write(client_socket, response, strlen(response));

    // Read the response from the server
    bytes_read = read(client_socket, response, sizeof(response));
    if (bytes_read < 0) {
        perror("Read error");
        return 1;
    }

    // Send the response back to the client
    write(client_socket, response, strlen(response));

    // Close the client socket
    close(client_socket);

    // Clean up and exit
    close(server_socket);
    return 0;
}