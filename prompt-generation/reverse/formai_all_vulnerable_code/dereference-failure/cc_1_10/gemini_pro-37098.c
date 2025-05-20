//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

typedef struct {
    int fd;
    char *request;
    int request_len;
    char *response;
    int response_len;
} connection;

void handle_connection(connection *conn) {
    // Read the request
    conn->request_len = read(conn->fd, conn->request, 1024);
    if (conn->request_len == -1) {
        perror("read");
        return;
    }

    // Parse the request
    char *method = strtok(conn->request, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Check the method
    if (strcmp(method, "GET") != 0) {
        // Not a GET request, send a 405 Method Not Allowed response
        conn->response_len = sprintf(conn->response, "HTTP/1.1 405 Method Not Allowed\r\n\r\n");
        write(conn->fd, conn->response, conn->response_len);
        return;
    }

    // Check the path
    if (strcmp(path, "/") == 0) {
        // The path is the root directory, send a 200 OK response with the index.html file
        conn->response_len = sprintf(conn->response, "HTTP/1.1 200 OK\r\n\r\n<html><body><h1>Hello, world!</h1></body></html>\n");
        write(conn->fd, conn->response, conn->response_len);
    } else {
        // The path is not the root directory, send a 404 Not Found response
        conn->response_len = sprintf(conn->response, "HTTP/1.1 404 Not Found\r\n\r\n");
        write(conn->fd, conn->response, conn->response_len);
    }

    // Close the connection
    close(conn->fd);
}

void accept_connections(int server_fd) {
    while (1) {
        // Accept a new connection
        int fd = accept(server_fd, NULL, NULL);
        if (fd == -1) {
            perror("accept");
            continue;
        }

        // Create a new connection object
        connection *conn = malloc(sizeof(connection));
        conn->fd = fd;
        conn->request = malloc(1024);
        conn->response = malloc(1024);

        // Handle the connection in a separate thread
        #pragma omp task
        {
            handle_connection(conn);
        }
    }
}

int main() {
    // Create a server socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return 1;
    }

    // Set the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for connections
    if (listen(server_fd, 10) == -1) {
        perror("listen");
        return 1;
    }

    // Accept connections and handle them in separate threads
    accept_connections(server_fd);

    // Close the server socket
    close(server_fd);

    return 0;
}