//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_CONN 1024

void handle_client(int);

int main(int argc, char *argv[]) {
    int listen_fd, client_fd, port_number;
    bool running = true;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    char buffer[1024];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    port_number = atoi(argv[1]);
    if (port_number < 0 || port_number > 65535) {
        fprintf(stderr, "%s: Invalid port number\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    int optval = 1;
    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;  
    server_addr.sin_addr.s_addr = INADDR_ANY;  
    server_addr.sin_port = htons(port_number);  

    if (bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_fd, MAX_CONN) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Simple HTTP Proxy listening on port %d\n", port_number);

    while (running) {
        client_addr_len = sizeof(client_addr);
        if ((client_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_addr_len)) == -1) {
            perror("accept");
            continue;
        }

        if (!fork()) {
            close(listen_fd);
            handle_client(client_fd);
            exit(EXIT_SUCCESS);
        }

        close(client_fd);
    }

    close(listen_fd);
    return 0;
}

void handle_client(int client_fd) {
    char buffer[1024];
    ssize_t n;
    int remote_fd, status;
    struct hostent *server;
    struct sockaddr_in server_addr;

    // Read the client's request
    if ((n = read(client_fd, buffer, sizeof(buffer) - 1)) == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Ensure that the request is null-terminated
    buffer[n] = '\0';

    // Parse the host and port from the request
    char *host = strtok(buffer, ":");
    int port = atoi(strtok(NULL, "/"));

    // Create a new socket for the remote server
    if ((remote_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Find the IP address of the remote server
    if ((server = gethostbyname(host)) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Set the address of the remote server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    // Connect to the remote server
    if (connect(remote_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Forward the client's request to the remote server
    if (write(remote_fd, buffer, strlen(buffer)) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Read the remote server's response
    while ((n = read(remote_fd, buffer, sizeof(buffer))) > 0) {
        // Forward the response to the client
        if (write(client_fd, buffer, n) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    close(remote_fd);
    close(client_fd);
}