//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum size of the request buffer
#define REQUEST_BUFFER_SIZE 1024

// Define the maximum size of the response buffer
#define RESPONSE_BUFFER_SIZE 1024

// Define the maximum number of clients that can be connected to the server at the same time
#define MAX_CLIENTS 10

// Define the structure of a client
typedef struct client {
    int socket;
    char request[REQUEST_BUFFER_SIZE];
    char response[RESPONSE_BUFFER_SIZE];
} client;

// Define the function to handle a client
void handle_client(client *client) {
    // Read the request from the client
    int bytes_received = recv(client->socket, client->request, REQUEST_BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv");
        close(client->socket);
        return;
    }

    // Parse the request
    char *method = strtok(client->request, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Check if the request is valid
    if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
        // Send a 400 Bad Request response
        sprintf(client->response, "HTTP/1.1 400 Bad Request\r\nContent-Length: 0\r\n\r\n");
        send(client->socket, client->response, strlen(client->response), 0);
        close(client->socket);
        return;
    }

    // Generate the response
    sprintf(client->response, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\nContent-Type: text/plain\r\n\r\nHello, world!\n", strlen("Hello, world!"));

    // Send the response to the client
    send(client->socket, client->response, strlen(client->response), 0);

    // Close the client socket
    close(client->socket);
}

// Define the main function
int main() {
    // Create a socket for the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        return -1;
    }

    // Set the socket to be reusable
    int reuseaddr = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr)) < 0) {
        perror("setsockopt");
        close(server_socket);
        return -1;
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
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        close(server_socket);
        return -1;
    }

    // Accept incoming connections
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // Create a new client
        client *client = malloc(sizeof(client));
        client->socket = client_socket;

        // Handle the client in a separate thread
        pthread_t thread;
        if (pthread_create(&thread, NULL, (void *(*)(void *)) handle_client, client) != 0) {
            perror("pthread_create");
            close(client_socket);
            free(client);
            continue;
        }
    }

    // Close the server socket
    close(server_socket);

    return 0;
}