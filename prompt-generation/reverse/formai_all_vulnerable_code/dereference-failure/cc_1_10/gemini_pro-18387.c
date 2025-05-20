//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 4096

// Function to handle incoming client requests
void handle_client_request(int client_socket) {
    char request[MAX_REQUEST_SIZE];
    char response[MAX_RESPONSE_SIZE];

    // Read the incoming HTTP request from the client
    int bytes_received = read(client_socket, request, MAX_REQUEST_SIZE);
    if (bytes_received < 0) {
        perror("Error reading from client socket");
        close(client_socket);
        return;
    }

    // Parse the HTTP request to get the target host and path
    char *host_start = strstr(request, "Host:");
    if (host_start == NULL) {
        printf("Invalid HTTP request: no Host header\n");
        write(client_socket, "HTTP/1.1 400 Bad Request\r\n\r\n", 29);
        close(client_socket);
        return;
    }
    char *host_end = strchr(host_start, '\n');
    if (host_end == NULL) {
        printf("Invalid HTTP request: no newline after Host header\n");
        write(client_socket, "HTTP/1.1 400 Bad Request\r\n\r\n", 29);
        close(client_socket);
        return;
    }
    char *host = malloc(host_end - host_start);
    strncpy(host, host_start + 6, host_end - host_start - 6);

    char *path_start = strstr(request, "GET ");
    if (path_start == NULL) {
        printf("Invalid HTTP request: no GET method\n");
        write(client_socket, "HTTP/1.1 400 Bad Request\r\n\r\n", 29);
        close(client_socket);
        return;
    }
    char *path_end = strchr(path_start, ' ');
    if (path_end == NULL) {
        printf("Invalid HTTP request: no space after GET method\n");
        write(client_socket, "HTTP/1.1 400 Bad Request\r\n\r\n", 29);
        close(client_socket);
        return;
    }
    char *path = malloc(path_end - path_start);
    strncpy(path, path_start + 4, path_end - path_start - 4);

    // Open a socket to the target host
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        printf("Error resolving hostname %s\n", host);
        write(client_socket, "HTTP/1.1 500 Internal Server Error\r\n\r\n", 37);
        close(client_socket);
        return;
    }
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        close(client_socket);
        return;
    }
    if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        close(client_socket);
        close(server_socket);
        return;
    }

    // Send the HTTP request to the target host
    write(server_socket, request, bytes_received);

    // Read the HTTP response from the target host
    int bytes_read = 0;
    while ((bytes_read = read(server_socket, response + bytes_read, MAX_RESPONSE_SIZE - bytes_read)) > 0) {
        // Do nothing
    }
    if (bytes_read < 0) {
        perror("Error reading from server socket");
        close(client_socket);
        close(server_socket);
        return;
    }

    // Send the HTTP response to the client
    write(client_socket, response, bytes_read);

    // Close the sockets
    close(client_socket);
    close(server_socket);

    // Free the allocated memory
    free(host);
    free(path);
}

// Main function to start the HTTP proxy server
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    // Create a socket to listen for incoming client connections
    int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket < 0) {
        perror("Error creating listening socket");
        return 1;
    }

    struct sockaddr_in listening_address;
    memset(&listening_address, 0, sizeof(listening_address));
    listening_address.sin_family = AF_INET;
    listening_address.sin_port = htons(port);
    listening_address.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listening_socket, (struct sockaddr *)&listening_address, sizeof(listening_address)) < 0) {
        perror("Error binding listening socket");
        close(listening_socket);
        return 1;
    }

    if (listen(listening_socket, 5) < 0) {
        perror("Error listening on socket");
        close(listening_socket);
        return 1;
    }

    // Wait for incoming client connections and handle them
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(listening_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket < 0) {
            perror("Error accepting client connection");
            continue;
        }

        // Handle the client request in a separate thread
        int pid = fork();
        if (pid == 0) {
            handle_client_request(client_socket);
            exit(0);
        } else {
            close(client_socket);
        }
    }

    // Close the listening socket
    close(listening_socket);

    return 0;
}