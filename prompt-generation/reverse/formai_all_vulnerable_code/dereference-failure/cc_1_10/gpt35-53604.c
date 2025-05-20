//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: introspective
/* 
 * A Simple HTTP Proxy in C
 * 
 * This program listens on a specific port for incoming requests and forwards them to the designated server.
 *
 * The program has configurable options including the listen port and the destination server URL.
 * 
 * When a request is received, the program establishes a connection with the destination server,
 * sends the HTTP request, receives the response, and then sends it back to the client who made the request.
 * 
 * To run this program:
 * 
 * gcc http_proxy.c -o http_proxy
 * ./http_proxy [listen_port] [destination_server_URL]
 * 
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s [listen_port] [destination_server_URL]\n", argv[0]);
        exit(1);
    }

    int listen_port = atoi(argv[1]);
    char *destination_server = argv[2];

    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error("Error opening socket");
    }

    // Set server address
    struct sockaddr_in server_address, client_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(listen_port);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        error("Error binding socket");
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) < 0) {
        error("Error listening on socket");
    }

    printf("HTTP Proxy is listening on port %d...\n", listen_port);

    while (1) {
        // Accept incoming connection
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket < 0) {
            error("Error accepting incoming connection");
        }

        printf("Client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        char request_buffer[BUFFER_SIZE];
        bzero(request_buffer, BUFFER_SIZE);
        int request_length = read(client_socket, request_buffer, BUFFER_SIZE);

        if (request_length < 0) {
            error("Error reading from client socket");
        }

        printf("Received request from client:\n%s\n", request_buffer);

        // Forward request to destination server
        int destination_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (destination_socket < 0) {
            error("Error opening socket to destination server");
        }

        struct sockaddr_in destination_address;
        bzero(&destination_address, sizeof(destination_address));
        destination_address.sin_family = AF_INET;
        destination_address.sin_port = htons(80);

        if (inet_aton(destination_server, &destination_address.sin_addr) <= 0) {
            error("Error converting IP address to binary format");
        }

        if (connect(destination_socket, (struct sockaddr *) &destination_address, sizeof(destination_address)) < 0) {
            error("Error connecting to destination server");
        }

        if (write(destination_socket, request_buffer, request_length) < 0) {
            error("Error forwarding request to destination server");
        }

        char response_buffer[BUFFER_SIZE];
        bzero(response_buffer, BUFFER_SIZE);

        // Forward response to client
        int response_length = read(destination_socket, response_buffer, BUFFER_SIZE);
        if (response_length < 0) {
            error("Error reading response from destination server");
        }

        printf("Received response from destination server:\n%s\n", response_buffer);

        if (write(client_socket, response_buffer, response_length) < 0) {
            error("Error sending response to client");
        }

        printf("Response forwarded to client\n");

        close(client_socket);
        close(destination_socket);
    }

    close(server_socket);

    return 0;
}