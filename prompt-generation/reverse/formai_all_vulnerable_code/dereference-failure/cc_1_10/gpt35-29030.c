//FormAI DATASET v1.0 Category: Simple Web Server ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define SERVER_PORT 8080
#define LISTEN_BACKLOG 50
#define WEB_DIR "web"

void error(char *msg) {
    perror(msg);
    exit(1);
}

char *read_file(char *file) {
    char *buffer = NULL;
    long length;
    FILE *f = fopen(file, "rb");

    if (f) {
        fseek (f, 0, SEEK_END);
        length = ftell(f);
        fseek (f, 0, SEEK_SET);

        buffer = malloc(length);
        if (buffer) {
            fread(buffer, 1, length, f);
        }

        fclose(f);
    }

    return buffer;
}

void send_file(int client_fd, char *file) {
    char *file_content = read_file(file);
    if (file_content) {
        char *http_response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
        char response[strlen(http_response) + strlen(file_content)];
        sprintf(response, "%s%s", http_response, file_content);
        send(client_fd, response, strlen(response), 0);
    } else {
        char *http_response = "HTTP/1.1 404 Not Found\nContent-Type: text/html\n\n";
        send(client_fd, http_response, strlen(http_response), 0);
    }
}

int main() {
    int server_fd, client_fd, flags;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    char buffer[2048];

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) <= 0) {
        error("Error creating socket");
    }

    // Set listen backlog
    if (listen(server_fd, LISTEN_BACKLOG) < 0) {
        error("Error setting listen backlog");
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);

    // Bind server socket to address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("Error binding socket");
    }

    while (1) {
        // Accept client connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_len)) < 0) {
            error("Error accepting client connection");
        }

        // Set client socket to nonblocking mode
        if ((flags = fcntl(client_fd, F_GETFL, 0)) < 0) {
            error("Error getting client socket flags");
        }
        flags |= O_NONBLOCK;
        if (fcntl(client_fd, F_SETFL, flags) < 0) {
            error("Error setting client socket to nonblocking mode");
        }

        // Receive request from client
        memset(buffer, 0, sizeof(buffer));
        recv(client_fd, buffer, sizeof(buffer), 0);

        // Extract request method and path
        char *request_method = strtok(buffer, " ");
        char *request_path = strtok(NULL, " ");

        // Set default file path
        char file_path[strlen(WEB_DIR) + strlen(request_path) + 1];
        sprintf(file_path, "%s%s", WEB_DIR, request_path);

        // Check if requested path exists in web directory
        struct stat file_stat;
        if (stat(file_path, &file_stat) < 0) {
            send(client_fd, "HTTP/1.1 404 Not Found\nContent-Type: text/html\n\n", 47, 0);
        } else if (S_ISDIR(file_stat.st_mode)) {
            // If requested path is directory, serve index.html
            sprintf(file_path, "%s%s/index.html", WEB_DIR, request_path);
            send_file(client_fd, file_path);
        } else {
            send_file(client_fd, file_path);
        }

        // Close client socket
        close(client_fd);
    }

    // Close server socket
    close(server_fd);

    return 0;
}