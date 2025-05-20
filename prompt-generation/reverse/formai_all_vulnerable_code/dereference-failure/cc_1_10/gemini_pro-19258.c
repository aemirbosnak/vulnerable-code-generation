//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// Define the port number for the server.
#define PORT 8080

// Create a socket.
int create_socket() {
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Bind the socket to an address and port.
void bind_socket(int sockfd) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }
}

// Listen for connections on the socket.
void listen_socket(int sockfd) {
    if (listen(sockfd, 5) < 0) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }
}

// Accept a connection on the socket.
int accept_connection(int sockfd) {
    int new_sockfd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (new_sockfd < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }
    return new_sockfd;
}

// Read data from the socket.
char *read_data(int sockfd) {
    char *buffer;
    int n;
    buffer = malloc(1024);
    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        perror("Error reading data");
        exit(EXIT_FAILURE);
    }
    return buffer;
}

// Write data to the socket.
void write_data(int sockfd, char *data) {
    int n;
    n = write(sockfd, data, strlen(data));
    if (n < 0) {
        perror("Error writing data");
        exit(EXIT_FAILURE);
    }
}

// Close the socket.
void close_socket(int sockfd) {
    close(sockfd);
}

// Main function.
int main() {
    int sockfd, new_sockfd;
    char *buffer;

    // Create a socket.
    sockfd = create_socket();

    // Bind the socket to an address and port.
    bind_socket(sockfd);

    // Listen for connections on the socket.
    listen_socket(sockfd);

    // Accept a connection on the socket.
    new_sockfd = accept_connection(sockfd);

    // Read data from the socket.
    buffer = read_data(new_sockfd);

    // Write data to the socket.
    write_data(new_sockfd, "Hello from the server!\n");

    // Close the socket.
    close_socket(new_sockfd);
    close_socket(sockfd);

    return 0;
}