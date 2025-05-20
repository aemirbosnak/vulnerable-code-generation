//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Main function
int main(int argc, char *argv[]) {
    // Initialize variables
    int server_socket, client_socket, port_number, client_length;
    char buffer[1024];
    struct sockaddr_in server_address, client_address;

    // Check for correct usage
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port number>\n", argv[0]);
        exit(1);
    }

    // Get the port number
    port_number = atoi(argv[1]);

    // Open the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_number);

    // Bind the server socket to the address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for connections
    listen(server_socket, 5);

    // Loop to handle connections
    while (1) {
        // Accept a connection
        client_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_length);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // Read the request from the client
        memset(buffer, 0, sizeof(buffer));
        int bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);
        if (bytes_read < 0) {
            perror("read");
            close(client_socket);
            continue;
        }

        // Process the request
        char *method = strtok(buffer, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");

        // Send the response to the client
        memset(buffer, 0, sizeof(buffer));
        sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, World!</h1>");
        write(client_socket, buffer, strlen(buffer));

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}