//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CONNECTIONS 10
#define MAX_REQUEST_SIZE 1024

typedef struct {
    int client_socket;
    int server_socket;
} connection_t;

void *handle_connection(void *arg) {
    connection_t *connection = (connection_t *)arg;
    char request[MAX_REQUEST_SIZE];
    char response[MAX_REQUEST_SIZE];

    // Read the request from the client
    int bytes_received = recv(connection->client_socket, request, MAX_REQUEST_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv");
    } else if (bytes_received == 0) {
        printf("Client closed connection\n");
    } else {
        // Parse the request
        char *host = strtok(request, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");

        // Connect to the server
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        inet_pton(AF_INET, host, &server_addr.sin_addr);
        connection->server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (connection->server_socket < 0) {
            perror("socket");
        }
        if (connect(connection->server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("connect");
        }

        // Send the request to the server
        send(connection->server_socket, request, bytes_received, 0);

        // Receive the response from the server
        bytes_received = recv(connection->server_socket, response, MAX_REQUEST_SIZE, 0);
        if (bytes_received < 0) {
            perror("recv");
        } else if (bytes_received == 0) {
            printf("Server closed connection\n");
        } else {
            // Send the response to the client
            send(connection->client_socket, response, bytes_received, 0);
        }
    }

    // Close the client and server sockets
    close(connection->client_socket);
    close(connection->server_socket);

    return NULL;
}

int main() {
    // Create the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
    }

    // Bind the server socket to the port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("listen");
    }

    while (1) {
        // Accept an incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("accept");
        } else {
            // Create a new thread to handle the connection
            pthread_t thread;
            connection_t *connection = malloc(sizeof(connection_t));
            connection->client_socket = client_socket;
            pthread_create(&thread, NULL, handle_connection, (void *)connection);
        }
    }

    // Close the server socket
    close(server_socket);

    return 0;
}