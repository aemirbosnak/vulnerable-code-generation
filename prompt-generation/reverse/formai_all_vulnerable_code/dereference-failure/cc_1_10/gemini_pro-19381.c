//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Receive the HTTP request from the client
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv");
        close(client_socket);
        return;
    }

    // Parse the HTTP request
    char *request_line = strtok(buffer, "\r\n");
    char *method = strtok(request_line, " ");
    char *path = strtok(NULL, " ");
    char *http_version = strtok(NULL, "\r\n");

    // Check if the request is valid
    if (strcmp(method, "GET") != 0) {
        // Send an HTTP 405 Method Not Allowed response
        char *response = "HTTP/1.1 405 Method Not Allowed\r\nContent-Type: text/plain\r\n\r\nMethod Not Allowed";
        send(client_socket, response, strlen(response), 0);
        close(client_socket);
        return;
    }

    // Connect to the remote server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        close(client_socket);
        return;
    }

    if (connect(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("connect");
        close(client_socket);
        close(server_socket);
        return;
    }

    // Send the HTTP request to the remote server
    send(server_socket, buffer, bytes_received, 0);

    // Receive the HTTP response from the remote server
    bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv");
        close(client_socket);
        close(server_socket);
        return;
    }

    // Send the HTTP response to the client
    send(client_socket, buffer, bytes_received, 0);

    // Close the connections
    close(client_socket);
    close(server_socket);
}

int main() {
    // Create a listening socket
    int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket < 0) {
        perror("socket");
        return 1;
    }

    // Bind the listening socket to the address and port
    struct sockaddr_in listening_address;
    listening_address.sin_family = AF_INET;
    listening_address.sin_port = htons(8080);
    listening_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(listening_socket, (struct sockaddr *) &listening_address, sizeof(listening_address)) < 0) {
        perror("bind");
        close(listening_socket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(listening_socket, 5) < 0) {
        perror("listen");
        close(listening_socket);
        return 1;
    }

    // Accept incoming connections
    while (1) {
        int client_socket = accept(listening_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // Handle the client connection in a separate thread
        pthread_t thread;
        pthread_create(&thread, NULL, (void *(*)(void *)) handle_client, (void *) client_socket);
    }

    // Close the listening socket
    close(listening_socket);

    return 0;
}