//FormAI DATASET v1.0 Category: Simple Web Server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CONN 5
#define MAX_REQUEST_SIZE 2048

char *get_content_type(char *file_extension) {
    if (strstr(file_extension, ".html")) {
        return "text/html";
    } else if (strstr(file_extension, ".css")) {
        return "text/css";
    } else if (strstr(file_extension, ".js")) {
        return "application/javascript";
    } else {
        return "text/plain";
    }
}

void send_404_response(int client_socket) {
    char *response_headers = "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n";
    send(client_socket, response_headers, strlen(response_headers), 0);
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket, read_size, bind_result, listen_result;
    struct sockaddr_in server_address, client_address;
    char *root_directory;

    if (argc != 2) {
        printf("Usage: %s <Root Directory>\n", argv[0]);
        exit(1);
    }

    root_directory = argv[1];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create server socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    bind_result = bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (bind_result == -1) {
        perror("Failed to bind server socket");
        exit(1);
    }

    listen_result = listen(server_socket, MAX_CONN);
    if (listen_result == -1) {
        perror("Failed to listen on server socket");
        exit(1);
    }

    printf("Server listening on port 8080...\n");

    while (1) {
        socklen_t client_address_len = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len);
        if (client_socket == -1) {
            perror("Failed to accept client connection");
            continue;
        }

        char *request_buffer = (char *) malloc(MAX_REQUEST_SIZE);
        read_size = recv(client_socket, request_buffer, MAX_REQUEST_SIZE, 0);
        if (read_size == -1) {
            perror("Failed to read from client socket");
            continue;
        }

        char *token, *method, *filename, *file_extension;

        method = strtok(request_buffer, " ");
        if (strcmp(method, "GET")) {
            send_404_response(client_socket);
            close(client_socket);
            continue;
        }

        filename = strtok(NULL, " ");
        if (filename == NULL) {
            send_404_response(client_socket);
            close(client_socket);
            continue;
        }

        token = strtok(filename, ".");
        file_extension = strtok(NULL, ".");

        if (file_extension == NULL) {
            send_404_response(client_socket);
            close(client_socket);
            continue;
        }

        char full_path[256];
        sprintf(full_path, "%s/%s", root_directory, filename);
        FILE *file_pointer = fopen(full_path, "rb");
        if (file_pointer == NULL) {
            send_404_response(client_socket);
            close(client_socket);
            continue;
        } else {
            fseek(file_pointer, 0L, SEEK_END);
            int content_length = ftell(file_pointer);
            fseek(file_pointer, 0L, SEEK_SET);

            char response_headers[1024];
            char *content_type = get_content_type(file_extension);
            sprintf(response_headers, "HTTP/1.1 200 OK\r\nContent-Type: %s\r\nContent-Length: %d\r\n\r\n", content_type, content_length);

            send(client_socket, response_headers, strlen(response_headers), 0);

            char response_buffer[1024];
            int num_bytes_read;
            while ((num_bytes_read = fread(response_buffer, sizeof(char), 1024, file_pointer)) > 0) {
                send(client_socket, response_buffer, num_bytes_read, 0);
            }

            fclose(file_pointer);
            close(client_socket);
        }
    }

    return 0;
}