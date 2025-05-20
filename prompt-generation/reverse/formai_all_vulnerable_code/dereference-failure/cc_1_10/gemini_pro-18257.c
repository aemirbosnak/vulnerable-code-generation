//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUF_SIZE 4096

// Function to handle client requests
void handle_client(int client_socket) {
    // Read the request from the client
    char request[BUF_SIZE];
    int bytes_read = recv(client_socket, request, BUF_SIZE, 0);
    if (bytes_read < 0) {
        perror("recv");
        close(client_socket);
        return;
    }

    // Parse the request
    char *method = strtok(request, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Check if the request is a GET request
    if (strcmp(method, "GET") != 0) {
        // Send an error response to the client
        char response[] = "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n";
        send(client_socket, response, strlen(response), 0);
        close(client_socket);
        return;
    }

    // Get the hostname from the path
    char *hostname = strtok(path, "/");

    // Get the port number from the hostname
    char *port_str = strtok(NULL, "/");
    int port = atoi(port_str);

    // Create a socket to connect to the remote server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        close(client_socket);
        return;
    }

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        close(client_socket);
        close(server_socket);
        return;
    }

    // Connect to the remote server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *) host->h_addr;
    if (connect(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(client_socket);
        close(server_socket);
        return;
    }

    // Send the request to the remote server
    send(server_socket, request, bytes_read, 0);

    // Read the response from the remote server
    char response[BUF_SIZE];
    while (1) {
        int bytes_read = recv(server_socket, response, BUF_SIZE, 0);
        if (bytes_read < 0) {
            perror("recv");
            close(client_socket);
            close(server_socket);
            return;
        }
        if (bytes_read == 0) {
            break;
        }

        // Send the response to the client
        send(client_socket, response, bytes_read, 0);
    }

    // Close the sockets
    close(client_socket);
    close(server_socket);
}

// Main function
int main(int argc, char **argv) {
    // Check if the correct number of arguments has been provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Get the port number from the command line arguments
    int port = atoi(argv[1]);

    // Create a socket to listen for client connections
    int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket < 0) {
        perror("socket");
        return 1;
    }

    // Bind the socket to the specified port
    struct sockaddr_in listening_addr;
    memset(&listening_addr, 0, sizeof(listening_addr));
    listening_addr.sin_family = AF_INET;
    listening_addr.sin_port = htons(port);
    listening_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(listening_socket, (struct sockaddr *) &listening_addr, sizeof(listening_addr)) < 0) {
        perror("bind");
        close(listening_socket);
        return 1;
    }

    // Start listening for client connections
    if (listen(listening_socket, 5) < 0) {
        perror("listen");
        close(listening_socket);
        return 1;
    }

    // Accept client connections and handle them in a loop
    while (1) {
        // Accept a client connection
        int client_socket = accept(listening_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // Handle the client request in a separate thread
        handle_client(client_socket);
    }

    // Close the listening socket
    close(listening_socket);

    return 0;
}