//FormAI DATASET v1.0 Category: Client Server Application ; Style: complete
/* This program demonstrates a simple Client-Server application that
 * allows a client to send a string to the server, and the server
 * responds back with the string in uppercase.
 * 
 * The server listens for incoming connections on a port specified
 * as a command-line argument. The client connects to the server
 * using its IP address and port number.
 *
 * Written by [Your Name]
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

void error(char *message);

int main(int argc, char *argv[]) {
    int server_socket, client_socket, addr_size;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_BUFFER_SIZE];
    int port;

    // Check if port number is specified
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create socket for server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error("Could not create server socket");
    }

    // Initialize server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    port = atoi(argv[1]);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to server address
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Could not bind server socket to address");
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        error("Could not listen for incoming connections");
    }

    printf("Server listening on port %d...\n", port);

    // Wait for client connection
    addr_size = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_size);

    // Receive message from client
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        error("Could not receive message from client");
    }

    // Convert message to uppercase
    for (int i = 0; i < strlen(buffer); i++) {
        buffer[i] = toupper(buffer[i]);
    }

    // Send uppercase message back to client
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        error("Could not send message to client");
    }

    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}