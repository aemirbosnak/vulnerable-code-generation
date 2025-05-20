//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CONNECTIONS 10

typedef struct {
    int client_fd;
    int server_fd;
} connection_t;

void *handle_connection(void *arg) {
    connection_t *conn = (connection_t *)arg;

    // Buffer for incoming data
    char buffer[4096];

    // Loop until the connection is closed
    while (1) {
        // Read data from the client
        int bytes_received = recv(conn->client_fd, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            // Client closed the connection
            break;
        }

        // Send data to the server
        send(conn->server_fd, buffer, bytes_received, 0);

        // Read data from the server
        bytes_received = recv(conn->server_fd, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            // Server closed the connection
            break;
        }

        // Send data to the client
        send(conn->client_fd, buffer, bytes_received, 0);
    }

    // Close the client and server file descriptors
    close(conn->client_fd);
    close(conn->server_fd);

    // Free the connection struct
    free(conn);

    return NULL;
}

int main() {
    // Create a listening socket
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Bind the socket to the specified port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(listen_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Start listening for incoming connections
    if (listen(listen_fd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        // Accept an incoming connection
        int client_fd = accept(listen_fd, NULL, NULL);
        if (client_fd < 0) {
            perror("accept");
            exit(1);
        }

        // Create a new thread to handle the connection
        pthread_t thread;
        connection_t *conn = malloc(sizeof(connection_t));
        conn->client_fd = client_fd;

        // Connect to the remote server
        conn->server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (conn->server_fd < 0) {
            perror("socket");
            exit(1);
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80); // Default HTTP port
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost
        if (connect(conn->server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("connect");
            exit(1);
        }

        pthread_create(&thread, NULL, handle_connection, conn);
    }

    // Close the listening socket
    close(listen_fd);

    return 0;
}