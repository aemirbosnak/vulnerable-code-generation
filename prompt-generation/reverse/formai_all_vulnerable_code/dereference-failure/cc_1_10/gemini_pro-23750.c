//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Define the port number of the server
#define PORT 8080

// Define the maximum number of connections the server can handle
#define MAX_CONNECTIONS 5

// Define the maximum size of the request buffer
#define REQUEST_BUFFER_SIZE 1024

// Define the maximum size of the response buffer
#define RESPONSE_BUFFER_SIZE 8192

// Create a new socket for the server
int create_socket() {
    int socket_fd;

    // Create a new socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Check if the socket was created successfully
    if (socket_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Return the socket file descriptor
    return socket_fd;
}

// Bind the socket to the specified port
void bind_socket(int socket_fd, int port) {
    struct sockaddr_in server_address;

    // Set the server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
}

// Listen for incoming connections on the socket
void listen_socket(int socket_fd) {
    // Listen for incoming connections
    if (listen(socket_fd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

// Accept an incoming connection on the socket
int accept_connection(int socket_fd) {
    int client_socket_fd;
    struct sockaddr_in client_address;
    socklen_t client_address_length;

    // Accept an incoming connection
    client_socket_fd = accept(socket_fd, (struct sockaddr *)&client_address, &client_address_length);

    // Check if the connection was accepted successfully
    if (client_socket_fd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Return the client socket file descriptor
    return client_socket_fd;
}

// Read the request from the client
char *read_request(int client_socket_fd) {
    char *request_buffer;
    int bytes_read;

    // Allocate memory for the request buffer
    request_buffer = malloc(REQUEST_BUFFER_SIZE);

    // Read the request from the client
    bytes_read = read(client_socket_fd, request_buffer, REQUEST_BUFFER_SIZE - 1);

    // Check if the request was read successfully
    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Null-terminate the request buffer
    request_buffer[bytes_read] = '\0';

    // Return the request buffer
    return request_buffer;
}

// Parse the request
char *parse_request(char *request) {
    char *method;
    char *uri;
    char *http_version;

    // Get the method
    method = strtok(request, " ");

    // Get the URI
    uri = strtok(NULL, " ");

    // Get the HTTP version
    http_version = strtok(NULL, "\r\n");

    // Return the URI
    return uri;
}

// Generate the response
char *generate_response(char *uri) {
    char *response_buffer;
    int response_length;

    // Generate the response header
    response_buffer = malloc(RESPONSE_BUFFER_SIZE);
    response_length = snprintf(response_buffer, RESPONSE_BUFFER_SIZE,
                              "HTTP/1.1 200 OK\r\n"
                              "Content-Type: text/html\r\n"
                              "Content-Length: %d\r\n"
                              "\r\n"
                              "<html>\n"
                              "<head>\n"
                              "<title>My Web Server</title>\n"
                              "</head>\n"
                              "<body>\n"
                              "<h1>Welcome to my web server!</h1>\n"
                              "<p>You requested the following URI: %s</p>\n"
                              "</body>\n"
                              "</html>\n",
                              strlen(uri), uri);

    // Return the response buffer
    return response_buffer;
}

// Send the response to the client
void send_response(int client_socket_fd, char *response) {
    int bytes_sent;

    // Send the response to the client
    bytes_sent = write(client_socket_fd, response, strlen(response));

    // Check if the response was sent successfully
    if (bytes_sent == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
}

// Close the client socket
void close_client_socket(int client_socket_fd) {
    // Close the client socket
    close(client_socket_fd);
}

// The main function
int main() {
    int socket_fd;
    int client_socket_fd;
    char *request;
    char *uri;
    char *response;

    // Create a new socket for the server
    socket_fd = create_socket();

    // Bind the socket to the specified port
    bind_socket(socket_fd, PORT);

    // Listen for incoming connections on the socket
    listen_socket(socket_fd);

    // Accept an incoming connection on the socket
    client_socket_fd = accept_connection(socket_fd);

    // Read the request from the client
    request = read_request(client_socket_fd);

    // Parse the request
    uri = parse_request(request);

    // Generate the response
    response = generate_response(uri);

    // Send the response to the client
    send_response(client_socket_fd, response);

    // Close the client socket
    close_client_socket(client_socket_fd);

    // Close the server socket
    close(socket_fd);

    // Free the allocated memory
    free(request);
    free(response);

    return 0;
}