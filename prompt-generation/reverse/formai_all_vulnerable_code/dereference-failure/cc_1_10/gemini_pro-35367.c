//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Welcome banner
void welcome() {
    printf("***************************************************************\n");
    printf("* Welcome to the most incredible and exhilarating HTTP Proxy! *\n");
    printf("* Get ready for an awe-inspiring and frictionless browsing experience. *\n");
    printf("***************************************************************\n\n");
}

// Handle client requests
void handle_client(int client_socket) {
    // Receive request from client
    char request[4096];
    recv(client_socket, request, sizeof(request), 0);

    // Parse request
    char *method = strtok(request, " ");
    char *uri = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Connect to server
    char *host = strtok(uri, "/");
    int port = atoi(strtok(NULL, "/"));
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(host);
    server_addr.sin_port = htons(port);
    connect(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

    // Forward request to server
    send(server_socket, request, strlen(request), 0);

    // Receive response from server
    char response[4096];
    recv(server_socket, response, sizeof(response), 0);

    // Forward response to client
    send(client_socket, response, strlen(response), 0);

    // Close connections
    close(client_socket);
    close(server_socket);
}

// Main function
int main() {
    // Display welcome banner
    welcome();

    // Create server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    // Accept client connections
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }
        handle_client(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}