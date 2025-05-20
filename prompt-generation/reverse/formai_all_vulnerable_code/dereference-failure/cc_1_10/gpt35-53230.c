//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

// Function to handle socket communication
void handle_socket_communication(int client_socket, struct sockaddr_in server_addr) {
    char buffer[BUF_SIZE];
    int bytes_received, bytes_sent;
    memset(buffer, 0, BUF_SIZE);

    // Receive data from client
    bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);
    if (bytes_received < 0) {
        perror("Error receiving data");
        exit(1);
    }

    printf("Received request: %s\n", buffer);

    // Extract host name from request
    char* host_name = strstr(buffer, "Host: ");
    if (host_name == NULL) {
        printf("Error parsing request");
        return;
    }
    host_name += strlen("Host: ");
    char* end_of_host_name = strstr(host_name, "\r\n");
    if (end_of_host_name == NULL) {
        printf("Error parsing request");
        return;
    }
    *end_of_host_name = '\0';

    // Create socket to connect to server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(1);
    }
    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send request to server
    bytes_sent = send(server_socket, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("Error sending request to server");
        exit(1);
    }

    // Receive response from server and send to client
    while ((bytes_received = recv(server_socket, buffer, BUF_SIZE, 0)) > 0) {
        bytes_sent = send(client_socket, buffer, bytes_received, 0);
        if (bytes_sent < 0) {
            perror("Error sending response to client");
            exit(1);
        }
        memset(buffer, 0, BUF_SIZE);
    }

    // Close sockets
    close(server_socket);
    close(client_socket);

    printf("Connection closed\n");
}

// Main function
int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <proxy_port> <server_port>\n", argv[0]);
        exit(1);
    }

    int proxy_port = atoi(argv[1]);
    int server_port = atoi(argv[2]);

    // Create proxy socket
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Error creating proxy socket");
        exit(1);
    }

    // Bind proxy socket to port
    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(proxy_port);
    if (bind(proxy_socket, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Error binding proxy socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(proxy_socket, 5) < 0) {
        perror("Error listening on proxy socket");
        exit(1);
    }

    printf("Proxy server running on port %d\n", proxy_port);

    // Create server address structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(server_port);

    while (1) {
        // Accept incoming connection
        struct sockaddr_in client_addr;
        int client_addr_size = sizeof(client_addr);
        int client_socket = accept(proxy_socket, (struct sockaddr*)&client_addr, &client_addr_size);
        if (client_socket < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        printf("Connection accepted\n");

        // Handle socket communication with client
        handle_socket_communication(client_socket, server_addr);
    }

    return 0;
}