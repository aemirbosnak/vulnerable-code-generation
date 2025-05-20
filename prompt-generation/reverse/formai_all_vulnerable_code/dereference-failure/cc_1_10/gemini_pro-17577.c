//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT "8080"  // The port number to listen for incoming connections on
#define MAX_CONNECTIONS 10  // The maximum number of concurrent connections the server can handle
#define BUFFER_SIZE 1024  // The maximum size of a request or response that the server can process

// Function to handle incoming connections from clients
void handle_connection(int client_socket_fd) {
    // Declare buffer to store request and response
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    // Read request from client
    int num_bytes_received = read(client_socket_fd, request, BUFFER_SIZE);
    if (num_bytes_received < 0) {
        perror("read");
        close(client_socket_fd);
        return;
    }

    // Parse request and generate response
    char *method = strtok(request, " ");
    char *path = strtok(NULL, " ");
    char *http_version = strtok(NULL, "\r\n");

    if (strcmp(method, "GET") == 0) {
        // Serve static file
        if (strcmp(path, "/") == 0 || strcmp(path, "/index.html") == 0) {
            strcpy(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
            strcat(response, "<html><body><h1>Welcome to the Simple Web Server!</h1></body></html>");
        } else {
            strcpy(response, "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\n");
            strcat(response, "File not found.");
        }
    } else {
        // Handle other HTTP methods
        strcpy(response, "HTTP/1.1 501 Not Implemented\r\nContent-Type: text/plain\r\n\r\n");
        strcat(response, "Method not implemented.");
    }

    // Send response to client
    int num_bytes_sent = write(client_socket_fd, response, strlen(response));
    if (num_bytes_sent < 0) {
        perror("write");
        close(client_socket_fd);
        return;
    }

    // Close client socket
    close(client_socket_fd);
}

int main() {
    // Get address information for the server
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;  // IPv4
    hints.ai_socktype = SOCK_STREAM;  // TCP
    hints.ai_flags = AI_PASSIVE;  // Use wildcard IP address

    struct addrinfo *result;
    int status = getaddrinfo(NULL, PORT, &hints, &result);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return EXIT_FAILURE;
    }

    // Create a socket for listening for incoming connections
    int server_socket_fd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (server_socket_fd < 0) {
        perror("socket");
        freeaddrinfo(result);
        return EXIT_FAILURE;
    }

    // Bind the socket to the specified address and port
    if (bind(server_socket_fd, result->ai_addr, result->ai_addrlen) < 0) {
        perror("bind");
        close(server_socket_fd);
        freeaddrinfo(result);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket_fd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        close(server_socket_fd);
        freeaddrinfo(result);
        return EXIT_FAILURE;
    }

    // Loop to handle incoming connections
    while (1) {
        // Accept incoming connection
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket_fd = accept(server_socket_fd, (struct sockaddr *) &client_address, &client_address_size);
        if (client_socket_fd < 0) {
            perror("accept");
            continue;
        }

        // Handle the connection in a separate thread
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *) handle_connection, (void *) client_socket_fd);
        pthread_detach(thread_id);
    }

    // Close the server socket
    close(server_socket_fd);

    // Free the address information
    freeaddrinfo(result);

    return EXIT_SUCCESS;
}