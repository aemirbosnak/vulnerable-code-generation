//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 8192

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    // Read the request from the client
    ssize_t bytes_read = read(client_sock, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        error("Error reading from client socket");
    }
    
    if (bytes_read == 0) {
        close(client_sock);
        return;
    }

    // Parse the request line
    char method[16], url[1024], protocol[16];
    sscanf(buffer, "%s %s %s", method, url, protocol);
    printf("Request: %s %s %s\n", method, url, protocol);

    // Open connection to the target server
    char hostname[1024];
    int port = 80;
    if (sscanf(url, "http://%1023[^:]:%d", hostname, &port) != 2) {
        sscanf(url, "http://%1023[^/]", hostname);
    }
    
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        error("Error opening server socket");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    // Forward the request to the server
    write(server_sock, buffer, bytes_read);

    // Read the response from the server and send it back to the client
    while ((bytes_read = read(server_sock, buffer, sizeof(buffer))) > 0) {
        write(client_sock, buffer, bytes_read);
    }

    if (bytes_read < 0) {
        error("Error reading from server socket");
    }

    // Clean up
    close(server_sock);
    close(client_sock);
}

int main(int argc, char *argv[]) {
    int port = 8080;
    if (argc > 1) {
        port = atoi(argv[1]);
    }

    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        error("Error creating listening socket");
    }

    struct sockaddr_in listen_addr;
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(port);
    listen_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        error("Error binding to port");
    }

    listen(listen_sock, 5);
    printf("Proxy server listening on port %d...\n", port);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            error("Error accepting connection");
        }

        // Handle client in a separate function
        handle_client(client_sock);
    }

    close(listen_sock);
    return 0;
}