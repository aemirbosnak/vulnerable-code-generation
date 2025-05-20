//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// A simple HTTP proxy

// The maximum size of a request buffer
#define REQUEST_BUFFER_SIZE 4096

// The maximum size of a response buffer
#define RESPONSE_BUFFER_SIZE 4096

// The port number to listen on
#define PORT 8080

// Forward declaration of functions
int handle_client(int client_socket);

int main(int argc, char **argv) {
    // Create a listening socket
    int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket == -1) {
        perror("socket");
        return 1;
    }

    // Bind the socket to the port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(PORT);
    if (bind(listening_socket, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(listening_socket, 5) == -1) {
        perror("listen");
        return 1;
    }

    // Accept incoming connections and handle them in a loop
    while (1) {
        // Accept an incoming connection
        int client_socket = accept(listening_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Handle the client connection in a separate thread
        int *client_socket_ptr = malloc(sizeof(int));
        *client_socket_ptr = client_socket;
        pthread_t thread;
        if (pthread_create(&thread, NULL, (void *(*)(void *))handle_client, (void *)client_socket_ptr) != 0) {
            perror("pthread_create");
            close(client_socket);
            continue;
        }
        pthread_detach(thread);
    }

    // Close the listening socket
    close(listening_socket);

    return 0;
}

int handle_client(int client_socket) {
    // Read the request from the client
    char request_buffer[REQUEST_BUFFER_SIZE];
    int request_length = recv(client_socket, request_buffer, REQUEST_BUFFER_SIZE, 0);
    if (request_length == -1) {
        perror("recv");
        close(client_socket);
        return 1;
    }

    // Parse the request
    char *request_method = strtok(request_buffer, " ");
    char *request_uri = strtok(NULL, " ");
    char *request_http_version = strtok(NULL, "\r\n");

    // Check if the request is valid
    if (request_method == NULL || request_uri == NULL || request_http_version == NULL) {
        send(client_socket, "HTTP/1.1 400 Bad Request\r\n\r\n", 32, 0);
        close(client_socket);
        return 1;
    }

    // Connect to the remote server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(request_uri);
    server_addr.sin_port = htons(80);
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        send(client_socket, "HTTP/1.1 500 Internal Server Error\r\n\r\n", 39, 0);
        close(client_socket);
        return 1;
    }
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        send(client_socket, "HTTP/1.1 500 Internal Server Error\r\n\r\n", 39, 0);
        close(client_socket);
        close(server_socket);
        return 1;
    }

    // Send the request to the remote server
    send(server_socket, request_buffer, request_length, 0);

    // Read the response from the remote server
    char response_buffer[RESPONSE_BUFFER_SIZE];
    int response_length = recv(server_socket, response_buffer, RESPONSE_BUFFER_SIZE, 0);
    if (response_length == -1) {
        send(client_socket, "HTTP/1.1 500 Internal Server Error\r\n\r\n", 39, 0);
        close(client_socket);
        close(server_socket);
        return 1;
    }

    // Send the response to the client
    send(client_socket, response_buffer, response_length, 0);

    // Close the client and server sockets
    close(client_socket);
    close(server_socket);

    return 0;
}