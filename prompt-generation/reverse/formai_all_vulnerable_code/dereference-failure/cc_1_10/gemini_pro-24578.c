//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main() {
    // Create a socket for listening for incoming connections
    int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket == -1) {
        perror("Error creating listening socket");
        exit(1);
    }

    // Bind the socket to a port
    struct sockaddr_in listening_address;
    memset(&listening_address, 0, sizeof(listening_address));
    listening_address.sin_family = AF_INET;
    listening_address.sin_port = htons(PORT);
    listening_address.sin_addr.s_addr = INADDR_ANY;
    if (bind(listening_socket, (struct sockaddr *) &listening_address, sizeof(listening_address)) == -1) {
        perror("Error binding socket to port");
        exit(1);
    }

    // Start listening for incoming connections
    if (listen(listening_socket, 5) == -1) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    // Accept incoming connections in a loop
    while (1) {
        // Accept an incoming connection
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(listening_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket == -1) {
            perror("Error accepting incoming connection");
            continue;
        }

        // Read the HTTP request from the client
        char buffer[BUFFER_SIZE];
        int bytes_read = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_read == -1) {
            perror("Error reading HTTP request from client");
            close(client_socket);
            continue;
        }

        // Parse the HTTP request
        char *method = strtok(buffer, " ");
        char *path = strtok(NULL, " ");
        char *protocol = strtok(NULL, " ");

        // Check if the HTTP request is valid
        if (strcmp(method, "GET") != 0 || strcmp(protocol, "HTTP/1.1") != 0) {
            // Send a 400 Bad Request response to the client
            char response[] = "HTTP/1.1 400 Bad Request\n\nBad Request";
            send(client_socket, response, strlen(response), 0);
            close(client_socket);
            continue;
        }

        // Send a 302 Found response to the client, redirecting the client to the actual website
        char redirection_url[] = "https://www.example.com";
        char response[1024];
        snprintf(response, sizeof(response), "HTTP/1.1 302 Found\nLocation: %s\n\n", redirection_url);
        send(client_socket, response, strlen(response), 0);
        close(client_socket);
    }

    // Close the listening socket
    close(listening_socket);

    return 0;
}