//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>

#define SOCKET_PATH "/tmp/echo_socket"
#define BUFFER_SIZE 256

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the string
        printf("Server received: %s", buffer);
        
        // Echo back the message
        send(client_socket, buffer, bytes_received, 0);
    }

    if (bytes_received == -1) {
        perror("Error reading from client socket");
    }
    
    close(client_socket);
}

void start_server() {
    int server_socket, client_socket;
    struct sockaddr_un server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create a Unix domain socket
    if ((server_socket = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, SOCKET_PATH, sizeof(server_addr.sun_path) - 1);

    // Remove any existing socket
    unlink(SOCKET_PATH);

    // Bind the socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on %s\n", SOCKET_PATH);

    // Main server loop
    while (1) {
        // Accept a client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len)) == -1) {
            perror("Error accepting client connection");
            continue; // Continue accepting new clients
        }

        // Handle the client connection
        handle_client(client_socket);
    }

    // Close the server socket (unreachable in this example)
    close(server_socket);
}

void start_client() {
    int client_socket;
    struct sockaddr_un server_addr;
    char message[BUFFER_SIZE];

    // Create a Unix domain socket
    if ((client_socket = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("Error creating client socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, SOCKET_PATH, sizeof(server_addr.sun_path) - 1);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Client: ");
        fgets(message, sizeof(message), stdin);

        // Check for exit condition
        if (strncmp(message, "exit", 4) == 0) {
            break;
        }

        // Send message to the server
        send(client_socket, message, strlen(message), 0);

        // Receive echoed message from the server
        char buffer[BUFFER_SIZE];
        ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        buffer[bytes_received] = '\0';
        printf("Echo from server: %s", buffer);
    }

    // Clean up
    close(client_socket);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server|client>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (strcmp(argv[1], "client") == 0) {
        start_client();
    } else {
        fprintf(stderr, "Invalid argument: %s. Use 'server' or 'client'.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}