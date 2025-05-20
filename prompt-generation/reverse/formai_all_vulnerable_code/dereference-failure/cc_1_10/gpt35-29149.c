//FormAI DATASET v1.0 Category: Simple Web Server ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Maximum number of requests that can be queued for processing
#define BACKLOG 10

// HTML content that gets sent to the client
const char* html_response = 
    "HTTP/1.1 200 OK\n"
    "Content-Type: text/html; charset=UTF-8\n\n"
    "<html><body>Hello World!</body></html>\n";

int main(int argc, char* argv[]) {
    // Check if port number was provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Convert port number to an integer
    int port_num = atoi(argv[1]);

    // Create socket file descriptor
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        fprintf(stderr, "Error setting socket options: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Set up server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_num);

    // Bind socket to server address
    if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, BACKLOG) == -1) {
        fprintf(stderr, "Error listening for connections: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &client_addr_len);
    if (client_fd == -1) {
        fprintf(stderr, "Error accepting client connection: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Send HTML content to client
    if (send(client_fd, html_response, strlen(html_response), 0) == -1) {
        fprintf(stderr, "Error sending HTML content to client: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Close client and server sockets
    close(client_fd);
    close(server_fd);

    return 0;
}