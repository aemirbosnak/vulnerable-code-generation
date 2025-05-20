//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>

#define HTTP_OK "HTTP/1.1 200 OK\r\n"
#define HTTP_BAD "HTTP/1.1 400 Bad Request\r\n"
#define HTTP_METHOD_NOT_ALLOWED "HTTP/1.1 405 Method Not Allowed\r\n"
#define HTTP_HEADER_CONTENT_TYPE "Content-Type: text/plain\r\n"
#define HTTP_HEADER_CONTENT_LENGTH "Content-Length: %d\r\n"

#define SERVER_NAME "Happy Server"
#define SERVER_PORT 8080
#define SERVER_BACKLOG 5
#define SERVER_TIMEOUT 10

#define BUFFER_SIZE 1024

static void handle_connection(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t length;

    length = recv(client_socket, buffer, sizeof(buffer), MSG_PEEK);
    if (length < 0) {
        perror("recv");
        close(client_socket);
        return;
    }

    if (strncmp(buffer, "GET", 3) != 0) {
        send(client_socket, HTTP_METHOD_NOT_ALLOWED, strlen(HTTP_METHOD_NOT_ALLOWED), MSG_NOSIGNAL);
        close(client_socket);
        return;
    }

    char *path = strchr(buffer, ' ') + 1;
    char *query = strchr(path, '?');
    if (query != NULL) {
        *query = '\0';
    }

    if (strcmp(path, "/") == 0) {
        path = "/index.html";
    }

    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        send(client_socket, HTTP_BAD, strlen(HTTP_BAD), MSG_NOSIGNAL);
        close(client_socket);
        return;
    }

    fseek(file, 0, SEEK_END);
    size_t content_length = ftell(file);
    rewind(file);

    char response[BUFFER_SIZE];
    sprintf(response, "%s%s%s%s", HTTP_OK, HTTP_HEADER_CONTENT_TYPE, HTTP_HEADER_CONTENT_LENGTH, content_length);
    send(client_socket, response, strlen(response), MSG_NOSIGNAL);

    while ((length = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        send(client_socket, buffer, length, MSG_NOSIGNAL);
    }

    fclose(file);
    close(client_socket);
}

static void handle_signal(int signal) {
    switch (signal) {
        case SIGTERM:
            fprintf(stderr, "\nHappy Server shutting down...\n");
            exit(0);
        default:
            break;
    }
}

int main(void) {
    int server_socket;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    socklen_t client_address_length;
    int client_socket;

    // Create the server socket.
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(1);
    }

    // Set the server address.
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the server socket to the server address.
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections on the server socket.
    if (listen(server_socket, SERVER_BACKLOG) < 0) {
        perror("listen");
        exit(1);
    }

    // Register a signal handler for SIGTERM.
    signal(SIGTERM, handle_signal);

    // Accept incoming connections and handle them.
    fprintf(stderr, "Happy Server is listening on port %d...\n", SERVER_PORT);
    while (1) {
        client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        fprintf(stderr, "Happy Server received a connection from %s:%d.\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        handle_connection(client_socket);
    }

    // Close the server socket.
    close(server_socket);

    return 0;
}