//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 8192
#define DEFAULT_PORT 8080

void handle_request(int client_socket);
void forward_request(int client_socket, const char *server_ip, int server_port, const char *request_buffer);

int main(int argc, char *argv[]) {
    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int port = DEFAULT_PORT;

    if (argc == 2) {
        port = atoi(argv[1]);
    }

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
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

    printf("Proxy Server listening on port %d...\n", port);

    while (1) {
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        handle_request(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_request(int client_socket) {
    char request_buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, request_buffer, sizeof(request_buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Recv failed");
        return;
    }
    request_buffer[bytes_received] = '\0';

    char method[10], url[200];
    sscanf(request_buffer, "%s %s", method, url);

    char *server_ip = strtok(url + 7, "/"); // Skip "http://"
    char *path = url + 7 + strlen(server_ip); // Url path after server

    printf("Request: %s %s\n", method, url);

    forward_request(client_socket, server_ip, 80, request_buffer);
}

void forward_request(int client_socket, const char *server_ip, int server_port, const char *request_buffer) {
    int server_socket;
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(server_socket);
        return;
    }

    send(server_socket, request_buffer, strlen(request_buffer), 0);

    char response_buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(server_socket, response_buffer, sizeof(response_buffer) - 1, 0)) > 0) {
        response_buffer[bytes_received] = '\0';
        send(client_socket, response_buffer, bytes_received, 0);
    }

    if (bytes_received < 0) {
        perror("Recv from server failed");
    }

    close(server_socket);
}