//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 4096

void *handle_connection(void *arg);

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    pthread_t tid;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create server socket on specified port
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if(bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    if(listen(server_fd, 10) == -1) {
        perror("Error listening on server socket");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Server running on port %d\n", atoi(argv[1]));

    // Wait for incoming client connections
    while(1) {
        socklen_t client_addr_len = sizeof(client_addr);

        client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_addr_len);
        if(client_fd == -1) {
            perror("Error accepting client connection");
            exit(EXIT_FAILURE);
        }

        fprintf(stdout, "Accepted client connection on socket %d\n", client_fd);

        // Start a new thread to handle the client connection
        if(pthread_create(&tid, NULL, handle_connection, (void *) &client_fd) != 0) {
            perror("Error creating thread");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

void *handle_connection(void *arg) {
    char buffer[BUFFER_SIZE];
    int client_fd = *(int *) arg;
    int server_fd;
    ssize_t bytes_read, bytes_written;

    // Read HTTP request from client
    bytes_read = read(client_fd, buffer, BUFFER_SIZE);
    if(bytes_read == -1) {
        perror("Error reading from client connection");
        exit(EXIT_FAILURE);
    }

    // Parse out the host and port from the HTTP request
    char *host_start = strstr(buffer, "Host: ") + strlen("Host: ");
    char *host_end = strstr(host_start, "\r\n");
    char *port_start = strchr(host_start, ':');
    char *port_end = strstr(host_start, "\r\n");
    if(port_start != NULL) {
        port_start++;
    }

    char host[256] = {0};
    if(port_start != NULL) {
        strncpy(host, host_start, port_start - host_start - 1);
    } else {
        strncpy(host, host_start, host_end - host_start);
    }

    int port = port_start != NULL ? atoi(port_start) : 80;

    fprintf(stdout, "Connecting to server %s:%d\n", host, port);

    // Connect to the remote server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    if(connect(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to remote server");
        exit(EXIT_FAILURE);
    }

    // Forward the HTTP request to the remote server
    bytes_written = write(server_fd, buffer, bytes_read);
    if(bytes_written == -1) {
        perror("Error writing to remote server");
        exit(EXIT_FAILURE);
    }

    // Read the response from the remote server and forward it to the client
    while((bytes_read = read(server_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(client_fd, buffer, bytes_read);
        if(bytes_written == -1) {
            perror("Error writing to client connection");
            exit(EXIT_FAILURE);
        }
    }

    // Clean up and close sockets
    close(client_fd);
    close(server_fd);

    return NULL;
}