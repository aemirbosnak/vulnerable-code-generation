//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Immerse yourself in the world of a simple HTTP proxy, a gateway between clients and servers, bridging the digital divide.

// A socket, a portal to the digital realm, is created, ready to receive connections from eager clients.
int create_server_socket(int port) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the designated port, establishing its presence in the digital landscape.
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Socket binding failed");
        exit(1);
    }

    // The socket now listens, its digital ears attuned to incoming client connections.
    if (listen(server_socket, 5) == -1) {
        perror("Listen failed");
        exit(1);
    }

    return server_socket;
}

// Accept an incoming client connection, welcoming them into the digital embrace.
int accept_client_connection(int server_socket) {
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);

    // A new socket is created for this specific client connection, a dedicated channel for communication.
    int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
    if (client_socket == -1) {
        perror("Accept failed");
        exit(1);
    }

    return client_socket;
}

// Forward the client's HTTP request to the designated server, acting as a messenger between realms.
void forward_request(int client_socket, char *host, char *port, char *request) {
    // A socket is established to connect to the server, bridging the gap between client and destination.
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(port));
    server_address.sin_addr.s_addr = inet_addr(host);

    // Connect to the server, initiating the digital handshake.
    if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Connect failed");
        exit(1);
    }

    // Relay the client's request to the server, becoming a conduit of digital communication.
    send(server_socket, request, strlen(request), 0);

    // Receive the server's response, a cascade of data flowing back through the digital channels.
    char response[4096];
    int response_length = recv(server_socket, response, sizeof(response), 0);

    // Forward the server's response back to the eager client, completing the digital loop.
    send(client_socket, response, response_length, 0);

    // Close the connection to the server, severing the digital bridge for this request.
    close(server_socket);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <port> <host> <port>\n", argv[0]);
        return 1;
    }

    // The proxy takes its place in the digital realm, ready to serve as a gateway.
    int server_socket = create_server_socket(atoi(argv[1]));

    while (1) {
        // A client connection request emerges from the digital ether, a beacon of communication.
        int client_socket = accept_client_connection(server_socket);

        // Receive the client's HTTP request, a coded message seeking fulfillment.
        char request[4096];
        int request_length = recv(client_socket, request, sizeof(request), 0);

        // Parse the request, extracting the host and port of the intended server.
        char *host = strtok(request, " ");
        host = strtok(NULL, " ");
        host = strtok(NULL, ":");
        char *port = strtok(NULL, " ");
        port = strtok(port, "\r\n");

        // Forward the request to the designated server, a bridge between realms.
        forward_request(client_socket, host, port, request);

        // Close the connection to the client, completing the digital encounter.
        close(client_socket);
    }

    // The proxy gracefully exits, its digital presence fading into the ether.
    close(server_socket);
    return 0;
}