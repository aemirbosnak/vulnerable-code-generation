//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: Alan Turing
// Alas, I am but a humble machine,
// A proxy I am named, a bridge with zeal;
// I listen, I forward, a conduit unseen,
// Connecting the world, a seamless stream.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXBUF 1024

// Forward declare functions
int create_server(int port);
int accept_client(int server_socket);
void handle_client(int client_socket);

// Main function, where the journey begins
int main(int argc, char *argv[]) {

    // Validate arguments
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Parse port number
    int port = atoi(argv[1]);

    // Create a listening socket, a beacon on the digital sea
    int server_socket = create_server(port);
    if (server_socket < 0) {
        perror("Error creating server socket");
        return 1;
    }

    // Listen for incoming connections, like a spider waiting for its prey
    int client_socket;
    while ((client_socket = accept_client(server_socket)) > 0) {
        // A new client, a fresh adventure!
        handle_client(client_socket);
        close(client_socket);
    }

    // Close the server socket, bid farewell to the listening post
    close(server_socket);

    return 0;
}

// Create a listening socket, the gateway to client connections
int create_server(int port) {
    int server_socket;
    struct sockaddr_in server_addr;

    // Create a socket, a portal to the digital realm
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        return -1;
    }

    // Set server address, our beacon on the network
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind socket to address, securing our position in the digital landscape
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        return -1;
    }

    // Begin listening, like a watchful guardian awaiting clients' requests
    if (listen(server_socket, 5) < 0) {
        return -1;
    }

    return server_socket;
}

// Accept incoming client connections, welcoming them into our digital domain
int accept_client(int server_socket) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;
    int client_socket;

    // Accept a client connection, forging a new digital bond
    client_addr_len = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len);
    if (client_socket < 0) {
        return -1;
    }

    // Print client IP address, tracing the footsteps of our digital visitor
    printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    return client_socket;
}

// Handle client requests, acting as a bridge between browser and server
void handle_client(int client_socket) {
    char buf[MAXBUF];
    int bytes_received;

    // Read HTTP request from client, deciphering their digital intent
    bytes_received = recv(client_socket, buf, MAXBUF, 0);
    if (bytes_received < 0) {
        perror("Error receiving HTTP request");
        return;
    }

    // Parse HTTP request, extracting the path to the desired digital realm
    char *path = strtok(buf, " ");
    if (path == NULL) {
        perror("Error parsing HTTP request");
        return;
    }

    // Construct HTTP response, a digital masterpiece in its own right
    char response[MAXBUF];
    sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, world!</h1>");

    // Send HTTP response to client, fulfilling their digital desires
    send(client_socket, response, strlen(response), 0);
}