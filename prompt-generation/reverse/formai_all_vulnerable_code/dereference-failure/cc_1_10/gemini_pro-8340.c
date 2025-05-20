//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

// Define the port number for the server.
#define PORT 8080

// Define the maximum number of clients that the server can handle.
#define MAX_CLIENTS 10

// Define the maximum size of a request.
#define MAX_REQUEST_SIZE 1024

// Define the maximum size of a response.
#define MAX_RESPONSE_SIZE 1024

// Define the MIME types for different file extensions.
typedef struct {
    char *extension;
    char *mime_type;
} mime_type;

mime_type mime_types[] = {
    {".html", "text/html"},
    {".css", "text/css"},
    {".js", "application/javascript"},
    {".png", "image/png"},
    {".jpg", "image/jpeg"},
    {".gif", "image/gif"},
    {NULL, NULL}
};

// Get the MIME type for a given file extension.
char *get_mime_type(char *extension) {
    int i = 0;
    while (mime_types[i].extension != NULL) {
        if (strcmp(extension, mime_types[i].extension) == 0) {
            return mime_types[i].mime_type;
        }
        i++;
    }
    return "text/plain";
}

// Send a response to the client.
void send_response(int client_socket, char *response, int response_size) {
    char buffer[MAX_RESPONSE_SIZE];
    sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\nContent-Type: text/html\r\n\r\n", response_size);
    strcat(buffer, response);
    send(client_socket, buffer, strlen(buffer), 0);
}

// Handle a request from a client.
void handle_request(int client_socket) {
    char request[MAX_REQUEST_SIZE];
    char response[MAX_RESPONSE_SIZE];
    int request_size = recv(client_socket, request, MAX_REQUEST_SIZE, 0);
    if (request_size < 0) {
        perror("recv");
        close(client_socket);
        return;
    }
    char *method = strtok(request, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");
    if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
        printf("Invalid request method or version.\n");
        close(client_socket);
        return;
    }
    char *file_path = ".";
    strcat(file_path, path);
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        printf("File not found.\n");
        close(client_socket);
        return;
    }
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *file_data = malloc(file_size);
    fread(file_data, 1, file_size, file);
    fclose(file);
    char *extension = strrchr(path, '.');
    char *mime_type = get_mime_type(extension);
    send_response(client_socket, file_data, file_size);
    free(file_data);
    close(client_socket);
}

// Start the server.
void start_server() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_socket);
        exit(1);
    }
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        close(server_socket);
        exit(1);
    }
    printf("Server started on port %d.\n", PORT);
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }
        printf("Client connected from %s:%d.\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        handle_request(client_socket);
    }
    close(server_socket);
}

// Main function.
int main() {
    start_server();
    return 0;
}