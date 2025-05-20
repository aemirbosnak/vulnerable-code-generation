//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Read the request from the client
    bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read <= 0) {
        perror("recv failed");
        close(client_socket);
        return;
    }
    buffer[bytes_read] = '\0';

    // Extract the host and port information from the request
    char *host_start = strstr(buffer, "Host: ");
    if (!host_start) {
        fprintf(stderr, "No Host header found\n");
        close(client_socket);
        return;
    }
    host_start += 6; // move past "Host: "

    char *host_end = strstr(host_start, "\r\n");
    if (!host_end) {
        fprintf(stderr, "Invalid Host header\n");
        close(client_socket);
        return;
    }
    *host_end = '\0'; // Terminate the host string

    // If no port is specified, default to 80
    int port = 80;
    char *port_pos = strchr(host_start, ':');
    if (port_pos) {
        *port_pos = '\0'; // Terminate host name
        port = atoi(port_pos + 1);
    }

    // Connect to the target server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket failed");
        close(client_socket);
        return;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with DNS resolution for actual use

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        close(server_socket);
        close(client_socket);
        return;
    }

    // Forward the request to the server
    send(server_socket, buffer, bytes_read, 0);

    // Read the response from the server
    while ((bytes_read = recv(server_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        // Send the response back to the client
        send(client_socket, buffer, bytes_read, 0);
    }

    // Close sockets
    close(server_socket);
    close(client_socket);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("socket failed");
        return EXIT_FAILURE;
    }

    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any network interface
    proxy_addr.sin_port = htons(port);

    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("bind failed");
        close(proxy_socket);
        return EXIT_FAILURE;
    }

    if (listen(proxy_socket, 10) < 0) {
        perror("listen failed");
        close(proxy_socket);
        return EXIT_FAILURE;
    }

    printf("Proxy listening on port %d...\n", port);

    while (1) {
        int client_socket = accept(proxy_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("accept failed");
            continue;
        }
        handle_client(client_socket);
    }

    close(proxy_socket);
    return EXIT_SUCCESS;
}