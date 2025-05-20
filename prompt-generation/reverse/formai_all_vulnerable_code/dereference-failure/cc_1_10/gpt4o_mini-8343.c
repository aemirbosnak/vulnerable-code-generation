//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 8192

void handle_client(int client_socket);
void forward_request(int client_socket, const char *host, int port, const char *request);
void send_response(int client_socket, const char *response, size_t response_length);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int server_socket;
    struct sockaddr_in server_addr;

    int port = atoi(argv[1]);
    if (port <= 0 || port > 65535) {
        fprintf(stderr, "Invalid port number.\n");
        exit(EXIT_FAILURE);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 10) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d\n", port);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        handle_client(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        perror("Read failed");
        return;
    }
    buffer[bytes_read] = '\0';

    // Extract the host and port
    char *host_start = strstr(buffer, "Host: ");
    if (host_start == NULL) {
        fprintf(stderr, "Host header not found\n");
        return;
    }

    host_start += 6; // Move past "Host: "
    char *host_end = strstr(host_start, "\r\n");
    if (host_end == NULL) {
        fprintf(stderr, "Malformed Host header\n");
        return;
    }

    *host_end = '\0'; // Null-terminate the host string
    char *port_start = strchr(host_start, ':');
    int port = 80; // Default port is 80
    if (port_start != NULL) {
        *port_start = '\0'; // Null-terminate the host
        port = atoi(port_start + 1);
    }

    forward_request(client_socket, host_start, port, buffer);
}

void forward_request(int client_socket, const char *host, int port, const char *request) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        return;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(server_socket);
        return;
    }

    write(server_socket, request, strlen(request));

    char response_buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    while ((bytes_received = read(server_socket, response_buffer, sizeof(response_buffer))) > 0) {
        send_response(client_socket, response_buffer, bytes_received);
    }

    close(server_socket);
}

void send_response(int client_socket, const char *response, size_t response_length) {
    write(client_socket, response, response_length);
}