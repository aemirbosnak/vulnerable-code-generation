//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_REQUEST_SIZE 1024

// Function to handle incoming client connections
void handle_client(int client_sock) {
    // Read the HTTP request from the client
    char request[MAX_REQUEST_SIZE];
    int num_bytes_read = read(client_sock, request, MAX_REQUEST_SIZE);
    if (num_bytes_read == -1) {
        perror("Error reading from client");
        exit(1);
    }

    // Parse the HTTP request
    char *method = strtok(request, " ");
    char *uri = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Check if the HTTP request is valid
    if (strcmp(method, "GET") != 0) {
        // Send an error response to the client
        char *error_response = "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n";
        write(client_sock, error_response, strlen(error_response));
        close(client_sock);
        return;
    }

    // Get the hostname and port from the URI
    char *hostname = strtok(uri, "/");
    char *port = strtok(NULL, "/");
    if (port == NULL) {
        port = "80";
    }

    // Create a socket to connect to the web server
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Get the IP address of the web server
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("Error getting host by name");
        exit(1);
    }

    // Connect to the web server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr.s_addr = *(long*)host->h_addr_list[0];

    if (connect(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send the HTTP request to the web server
    write(server_sock, request, strlen(request));

    // Read the HTTP response from the web server
    char response[MAX_REQUEST_SIZE];
    int num_bytes_received = read(server_sock, response, MAX_REQUEST_SIZE);
    if (num_bytes_received == -1) {
        perror("Error reading from server");
        exit(1);
    }

    // Send the HTTP response to the client
    write(client_sock, response, num_bytes_received);

    // Close the client and server sockets
    close(client_sock);
    close(server_sock);
}

int main(int argc, char *argv[]) {
    // Check if the command line arguments are valid
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Get the port number from the command line arguments
    int port = atoi(argv[1]);

    // Create a socket to listen for incoming connections
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("Error setting socket options");
        exit(1);
    }

    // Bind the socket to the port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(listen_sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_sock, SOMAXCONN) == -1) {
        perror("Error listening for connections");
        exit(1);
    }

    // Accept incoming connections and handle them in a separate thread
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(listen_sock, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_sock == -1) {
            perror("Error accepting connection");
            continue;
        }

        pthread_t thread;
        pthread_create(&thread, NULL, (void*)handle_client, (void*)client_sock);
    }

    // Close the listen socket
    close(listen_sock);

    return 0;
}