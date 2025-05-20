//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080

// Create a socket for the server
int create_server_socket() {
    int server_fd;
    struct sockaddr_in server_addr;

    // Create a socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    return server_fd;
}

// Create a socket for the client
int create_client_socket(const char *ip_address) {
    int client_fd;
    struct sockaddr_in client_addr;

    // Create a socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the client address
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(PORT);
    client_addr.sin_addr.s_addr = inet_addr(ip_address);

    // Connect to the server
    if (connect(client_fd, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    return client_fd;
}

// Send a message from the server to the client
void send_message_from_server(int client_fd, const char *message) {
    int len = strlen(message);

    // Send the length of the message to the client
    int sent = send(client_fd, &len, sizeof(len), 0);
    if (sent < 0) {
        perror("send");
        exit(1);
    }

    // Send the message to the client
    sent = send(client_fd, message, len, 0);
    if (sent < 0) {
        perror("send");
        exit(1);
    }
}

// Receive a message from the client to the server
char *receive_message_from_client(int client_fd) {
    int len;

    // Receive the length of the message from the client
    int received = recv(client_fd, &len, sizeof(len), 0);
    if (received < 0) {
        perror("recv");
        exit(1);
    }

    // Allocate memory for the message
    char *message = malloc(len + 1);
    if (message == NULL) {
        perror("malloc");
        exit(1);
    }

    // Receive the message from the client
    received = recv(client_fd, message, len, 0);
    if (received < 0) {
        perror("recv");
        exit(1);
    }

    // Terminate the message with a null character
    message[len] = '\0';

    return message;
}

// Handle a connection from a client
void handle_connection(int client_fd) {
    char *message;

    // Receive a message from the client
    message = receive_message_from_client(client_fd);

    // Print the message to the console
    printf("Received message from client: %s\n", message);

    // Send a message back to the client
    send_message_from_server(client_fd, "Hello from the server!");

    // Close the connection
    close(client_fd);
}

int main() {
    int server_fd, client_fd;

    // Create a server socket
    server_fd = create_server_socket();

    // Loop forever, waiting for connections from clients
    while (1) {
        // Accept a connection from a client
        client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) {
            perror("accept");
            exit(1);
        }

        // Handle the connection in a separate thread
        pthread_t thread;
        pthread_create(&thread, NULL, (void *)handle_connection, (void *)client_fd);
    }

    // Close the server socket
    close(server_fd);

    return 0;
}