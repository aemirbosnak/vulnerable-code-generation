//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 80
#define MAX_CONNECTIONS 5

struct connection {
    int socket;
    struct sockaddr_in address;
    char *buffer;
    size_t buffer_size;
};

void handle_connection(struct connection *connection) {
    // Receive data from the client
    ssize_t bytes_received = recv(connection->socket, connection->buffer, connection->buffer_size, 0);
    if (bytes_received < 0) {
        perror("recv");
        close(connection->socket);
        return;
    }

    // Check if the data contains any malicious code
    if (strstr(connection->buffer, "malicious_code") != NULL) {
        // Log the intrusion attempt
        printf("Intrusion attempt detected from %s:%d\n", inet_ntoa(connection->address.sin_addr), ntohs(connection->address.sin_port));

        // Close the connection
        close(connection->socket);
        return;
    }

    // Send a response to the client
    const char *response = "HTTP/1.1 200 OK\r\n\r\nHello, world!\n";
    ssize_t bytes_sent = send(connection->socket, response, strlen(response), 0);
    if (bytes_sent < 0) {
        perror("send");
        close(connection->socket);
        return;
    }

    // Close the connection
    close(connection->socket);
}

int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the socket options
    int reuse_address = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuse_address, sizeof(reuse_address)) < 0) {
        perror("setsockopt");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Bind the socket to the port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("listen");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Accept incoming connections
    while (1) {
        struct connection connection;
        memset(&connection, 0, sizeof(connection));
        connection.socket = accept(server_socket, (struct sockaddr *) &connection.address, (socklen_t *) &connection.address);
        if (connection.socket < 0) {
            perror("accept");
            continue;
        }

        // Allocate a buffer for the data
        connection.buffer_size = 1024;
        connection.buffer = malloc(connection.buffer_size);
        if (connection.buffer == NULL) {
            perror("malloc");
            close(connection.socket);
            continue;
        }

        // Handle the connection in a separate thread
        pthread_t thread;
        if (pthread_create(&thread, NULL, (void *(*)(void *)) handle_connection, &connection) != 0) {
            perror("pthread_create");
            close(connection.socket);
            free(connection.buffer);
            continue;
        }
    }

    // Close the server socket
    close(server_socket);

    return EXIT_SUCCESS;
}