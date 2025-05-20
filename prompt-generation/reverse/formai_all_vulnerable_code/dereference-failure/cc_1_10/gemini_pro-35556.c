//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the server's port number
#define SERVER_PORT 8080

// Create a socket
int create_socket() {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Bind the socket to the server's port
void bind_socket(int sockfd) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Could not bind socket");
        exit(EXIT_FAILURE);
    }
}

// Listen for incoming connections
void listen_for_connections(int sockfd) {
    if (listen(sockfd, 5) < 0) {
        perror("Could not listen for connections");
        exit(EXIT_FAILURE);
    }
}

// Accept an incoming connection
int accept_connection(int sockfd) {
    int client_sockfd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    if ((client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
        perror("Could not accept connection");
        exit(EXIT_FAILURE);
    }
    return client_sockfd;
}

// Receive data from the client
char *receive_data(int client_sockfd) {
    char *buffer = malloc(1024);
    int bytes_received = recv(client_sockfd, buffer, 1024, 0);
    if (bytes_received < 0) {
        perror("Could not receive data");
        exit(EXIT_FAILURE);
    }
    return buffer;
}

// Send data to the client
void send_data(int client_sockfd, char *data) {
    int bytes_sent = send(client_sockfd, data, strlen(data), 0);
    if (bytes_sent < 0) {
        perror("Could not send data");
        exit(EXIT_FAILURE);
    }
}

// Close the socket
void close_socket(int sockfd) {
    close(sockfd);
}

// Main function
int main() {
    // Create a socket
    int sockfd = create_socket();

    // Bind the socket to the server's port
    bind_socket(sockfd);

    // Listen for incoming connections
    listen_for_connections(sockfd);

    // Accept an incoming connection
    int client_sockfd = accept_connection(sockfd);

    // Receive data from the client
    char *buffer = receive_data(client_sockfd);

    // Send data to the client
    send_data(client_sockfd, "Hello world!");

    // Close the socket
    close_socket(sockfd);

    return 0;
}