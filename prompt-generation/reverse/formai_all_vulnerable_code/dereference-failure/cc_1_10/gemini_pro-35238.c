//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

void handle_request(int client_socket) {
    char request[1024];
    char response[1024];

    // Read the client's request
    int bytes_received = recv(client_socket, request, 1024, 0);
    if (bytes_received < 0) {
        perror("recv");
        return;
    }

    // Parse the request
    char *method = strtok(request, " ");
    char *path = strtok(NULL, " ");
    char *protocol = strtok(NULL, "\r\n");

    // Construct the response
    if (strcmp(method, "GET") == 0 && strcmp(path, "/") == 0) {
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Welcome to my peaceful web server!</h1>");
    } else {
        sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<h1>404 Not Found</h1>");
    }

    // Send the response
    int bytes_sent = send(client_socket, response, strlen(response), 0);
    if (bytes_sent < 0) {
        perror("send");
        return;
    }

    // Close the client socket
    close(client_socket);
}

int main() {
    // Create a listening socket
    int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Bind the listening socket to the specified port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(listening_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Start listening for incoming connections
    if (listen(listening_socket, 5) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept incoming connections and handle them
    while (1) {
        int client_socket = accept(listening_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        handle_request(client_socket);
    }

    // Close the listening socket
    close(listening_socket);

    return EXIT_SUCCESS;
}