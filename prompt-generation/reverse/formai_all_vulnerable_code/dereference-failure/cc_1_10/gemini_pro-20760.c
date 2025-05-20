//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define MAX_CONNECTIONS 10
#define MAX_REQUEST_SIZE 1024

typedef struct {
    int fd;
    char *request;
    int request_len;
    char *response;
    int response_len;
} connection_t;

void handle_connection(connection_t *conn) {
    // Read the request
    conn->request = malloc(MAX_REQUEST_SIZE);
    conn->request_len = read(conn->fd, conn->request, MAX_REQUEST_SIZE);
    if (conn->request_len == -1) {
        perror("read");
        close(conn->fd);
        free(conn->request);
        return;
    }

    // Parse the request
    char *method = strtok(conn->request, " ");
    char *path = strtok(NULL, " ");
    char *protocol = strtok(NULL, "\r\n");

    // Check if the method is supported
    if (strcmp(method, "GET") != 0) {
        conn->response = "HTTP/1.1 501 Not Implemented\r\n\r\n";
        conn->response_len = strlen(conn->response);
        return;
    }

    // Check if the path is valid
    if (strcmp(path, "/") == 0) {
        path = "/index.html";
    }

    char *file_path = malloc(strlen(path) + 1);
    strcpy(file_path, path);

    // Open the file
    int fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        conn->response = "HTTP/1.1 404 Not Found\r\n\r\n";
        conn->response_len = strlen(conn->response);
        close(conn->fd);
        free(conn->request);
        free(file_path);
        return;
    }

    // Read the file
    char *file_content = malloc(MAX_REQUEST_SIZE);
    int file_content_len = read(fd, file_content, MAX_REQUEST_SIZE);
    if (file_content_len == -1) {
        perror("read");
        close(conn->fd);
        close(fd);
        free(conn->request);
        free(file_path);
        free(file_content);
        return;
    }
    close(fd);

    // Create the response
    conn->response = malloc(strlen(protocol) + strlen(" 200 OK\r\n") + strlen("Content-Length: ") + strlen("Content-Type: text/html\r\n") + strlen("\r\n") + file_content_len);
    sprintf(conn->response, "%s 200 OK\r\nContent-Length: %d\r\nContent-Type: text/html\r\n\r\n%s", protocol, file_content_len, file_content);
    conn->response_len = strlen(conn->response);

    // Send the response
    write(conn->fd, conn->response, conn->response_len);

    // Close the connection
    close(conn->fd);
    free(conn->request);
    free(file_path);
    free(file_content);
    free(conn->response);
}

int main() {
    // Create the server socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return 1;
    }

    // Set the server socket to be non-blocking
    int flags = fcntl(server_fd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        close(server_fd);
        return 1;
    }
    if (fcntl(server_fd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl");
        close(server_fd);
        return 1;
    }

    // Bind the server socket to the server port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(server_fd);
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        close(server_fd);
        return 1;
    }

    // Main loop
    while (1) {
        // Accept incoming connections
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                continue;
            } else {
                perror("accept");
                close(server_fd);
                return 1;
            }
        }

        // Create a new connection object
        connection_t *conn = malloc(sizeof(connection_t));
        conn->fd = client_fd;
        conn->request = NULL;
        conn->request_len = 0;
        conn->response = NULL;
        conn->response_len = 0;

        // Handle the connection in a separate thread
        pthread_t thread;
        int ret = pthread_create(&thread, NULL, (void *(*)(void *))handle_connection, conn);
        if (ret != 0) {
            perror("pthread_create");
            close(client_fd);
            free(conn);
            continue;
        }

        // Detach the thread
        pthread_detach(thread);
    }

    // Close the server socket
    close(server_fd);

    return 0;
}