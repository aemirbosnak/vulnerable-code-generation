//FormAI DATASET v1.0 Category: Simple Web Server ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024
#define SERVER_PORT 8000
#define DOCUMENT_ROOT "htdocs"

int socket_fd, client_socket_fd;

int start_listening(int port) {
    struct sockaddr_in server_address;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Failed to create socket\n");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Failed to bind\n");
        return -1;
    }

    if (listen(socket_fd, 5) < 0) {
        printf("Failed to start listening\n");
        return -1;
    }

    printf("Server started on port %d\n", port);

    return 0;
}

char* get_file_path(char* request) {
    char* token = strtok(request, " ");
    token = strtok(NULL, " ");

    char* file_path = calloc(strlen(token) + strlen(DOCUMENT_ROOT) + 1, sizeof(char));
    strcat(file_path, DOCUMENT_ROOT);
    strcat(file_path, token);

    if (strcmp(token, "/") == 0) {
        strcat(file_path, "index.html");
    }

    return file_path;
}

void handle_request() {
    char* request_buffer = calloc(MAX_BUFFER_SIZE, sizeof(char));
    char* file_buffer = calloc(MAX_BUFFER_SIZE, sizeof(char));
    char* file_path;

    int bytes_received = recv(client_socket_fd, request_buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        printf("Error while receiving data\n");
        return;
    }

    file_path = get_file_path(request_buffer);

    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("File not found: %s\n", file_path);
        const char* response = "HTTP/1.1 404 Not Found\r\n\r\n<html><body><h1>404 Not Found</h1></body></html>";
        send(client_socket_fd, response, strlen(response), 0);
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    fread(file_buffer, 1, file_size, file);

    const char* response_headers = "HTTP/1.1 200 OK\r\n\r\n";
    send(client_socket_fd, response_headers, strlen(response_headers), 0);
    send(client_socket_fd, file_buffer, file_size, 0);

    fclose(file);
    free(request_buffer);
    free(file_buffer);
    free(file_path);
}

void handle_client() {
    client_socket_fd = accept(socket_fd, (struct sockaddr *)NULL, NULL);
    if (client_socket_fd < 0) {
        printf("Error while accepting connection\n");
        return;
    }
    
    printf("Client connected\n");

    handle_request();

    close(client_socket_fd);
    printf("Client disconnected\n");
}

int main() {
    if (start_listening(SERVER_PORT) < 0) {
        return -1;
    }

    while (1) {
        handle_client();
    }

    return 0;
}