//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// My very own web server!
int main() {
    // Set up the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // Bind the server socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("listen");
        return 1;
    }

    // Main server loop
    while (1) {
        // Accept incoming connections
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Handle the client request
        char request[1024];
        int request_length = recv(client_socket, request, sizeof(request), 0);
        if (request_length == -1) {
            perror("recv");
            close(client_socket);
            continue;
        }

        // Parse the request
        char *method = strtok(request, " ");
        char *path = strtok(NULL, " ");
        char *protocol = strtok(NULL, " ");

        // Generate the response
        char response[1024];
        if (strcmp(method, "GET") == 0) {
            if (strcmp(path, "/") == 0) {
                sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Welcome to my web server!</h1>");
            } else {
                sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<h1>404 Not Found</h1>");
            }
        } else {
            sprintf(response, "HTTP/1.1 405 Method Not Allowed\r\nContent-Type: text/html\r\n\r\n<h1>405 Method Not Allowed</h1>");
        }

        // Send the response
        int response_length = strlen(response);
        if (send(client_socket, response, response_length, 0) == -1) {
            perror("send");
            close(client_socket);
            continue;
        }

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}