//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

typedef struct {
    int fd;
    struct sockaddr_in addr;
    socklen_t addrlen;
    char buf[1024];
    int buflen;
} connection_t;

connection_t *connections[1024];
int num_connections = 0;

void handle_signal(int sig) {
    for (int i = 0; i < num_connections; i++) {
        close(connections[i]->fd);
    }
    exit(0);
}

void handle_connection(connection_t *conn) {
    int n = read(conn->fd, conn->buf, sizeof(conn->buf));
    if (n < 0) {
        perror("read");
        close(conn->fd);
        return;
    }
    conn->buflen = n;

    // Parse the request
    char *req = strtok(conn->buf, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Check if the request is valid
    if (strcmp(req, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
        printf("Invalid request: %s\n", conn->buf);
        close(conn->fd);
        return;
    }

    // Send the response
    char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, world!</h1></body></html>";
    write(conn->fd, response, strlen(response));
    close(conn->fd);
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Bind the socket to the port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for connections
    if (listen(sockfd, 1024) < 0) {
        perror("listen");
        exit(1);
    }

    // Set up the signal handler
    signal(SIGINT, handle_signal);

    // Main loop
    while (1) {
        // Accept a connection
        connection_t *conn = malloc(sizeof(connection_t));
        conn->fd = accept(sockfd, (struct sockaddr *)&conn->addr, &conn->addrlen);
        if (conn->fd < 0) {
            perror("accept");
            continue;
        }

        // Add the connection to the list
        connections[num_connections++] = conn;

        // Handle the connection
        handle_connection(conn);
    }

    return 0;
}