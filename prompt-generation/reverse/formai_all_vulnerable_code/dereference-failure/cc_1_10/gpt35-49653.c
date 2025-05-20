//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_REQUEST_SIZE 2000
#define DEFAULT_PORT 8080

int main(int argc, char *argv[]) {
    char request[MAX_REQUEST_SIZE];
    int server_socket, client_socket, port;
    socklen_t client_length;
    struct sockaddr_in server_address, client_address;
    
    // Set default port
    port = DEFAULT_PORT;

    // Parse arguments to get new port, if any
    if (argc == 2) {
        port = atoi(argv[1]);
    }

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(1);
    }

    // Initialize server address
    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    // Bind server address to socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding server address to socket");
        exit(1);
    }

    // Set socket to listen
    listen(server_socket, 5);
    printf("Server listening on port %d...\n", port);

    // Loop forever
    while (true) {
        // Accept incoming connection
        client_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_length);
        if (client_socket < 0) {
            perror("Error accepting incoming connection");
            exit(1);
        }

        // Read request from client
        bzero(request, MAX_REQUEST_SIZE);
        int request_length = read(client_socket, request, MAX_REQUEST_SIZE-1);
        if (request_length < 0) {
            perror("Error reading request from client");
            exit(1);
        }

        // Print request
        printf("Request:\n%s", request);

        // Construct and send response
        char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, World!";
        int response_length = strlen(response);
        int bytes_sent = write(client_socket, response, response_length);
        if (bytes_sent < 0) {
            perror("Error sending response to client");
            exit(1);
        }

        // Close client connection
        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}