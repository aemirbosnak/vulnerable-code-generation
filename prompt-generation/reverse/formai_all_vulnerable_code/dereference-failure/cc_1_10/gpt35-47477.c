//FormAI DATASET v1.0 Category: Simple Web Server ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_CLIENTS 100
#define MAX_BUFFER 1024

typedef struct {
    int sockfd;
    char client_ip[INET_ADDRSTRLEN];
    int client_port;
} client_info_t;

int setup_server(int port);

void serve_client(int sockfd, client_info_t *client_info);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = setup_server(atoi(argv[1]));

    // Main loop for accepting client connections
    while (1) {
        // Accept the client connection.
        struct sockaddr_in client_addr;
        unsigned int addr_len = sizeof(client_addr);
        int client_fd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len);

        // Check for errors
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        // Convert client address to human-readable format
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);

        // Get client port
        int client_port = ntohs(client_addr.sin_port);

        // Create client info struct
        client_info_t client_info = {
            .sockfd = client_fd,
            .client_port = client_port,
        };
        strncpy(client_info.client_ip, client_ip, INET_ADDRSTRLEN);

        // Serve the client in a new thread
        serve_client(client_fd, &client_info);
    }

    return 0;
}

int setup_server(int port) {
    // Create TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address
    int reuse = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the address and port
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = htonl(INADDR_ANY),
        .sin_port = htons(port),
    };
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", port);

    return sockfd;
}

void serve_client(int sockfd, client_info_t *client_info) {
    printf("Accepted connection from %s:%d\n", client_info->client_ip, client_info->client_port);

    // Receive client request
    char buffer[MAX_BUFFER];
    ssize_t bytes_received = recv(sockfd, buffer, MAX_BUFFER, 0);
    if (bytes_received == -1) {
        perror("recv");
        close(sockfd);
        return;
    }

    // Parse client request
    if (strstr(buffer, "GET") == NULL) {
        printf("Invalid request received from %s:%d\n", client_info->client_ip, client_info->client_port);
        close(sockfd);
        return;
    }

    // Get requested file path
    char *path = strchr(buffer, ' ') + 1;
    char *path_end = strchr(path, ' ');
    *path_end = '\0';

    // Check if file exists
    if (access(path, F_OK) == -1) {
        printf("File %s not found, serving 404 page to %s:%d\n", path, client_info->client_ip, client_info->client_port);
        char not_found[] = "HTTP/1.0 404 Not Found\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE html><html><head><title>Not Found</title></head><body><h1>404 Not Found</h1><p>The requested resource was not found on this server.</p></body></html>";
        send(sockfd, not_found, strlen(not_found), 0);
    } else {
        // Serve requested file
        printf("Serving file %s to %s:%d\n", path, client_info->client_ip, client_info->client_port);

        // Open file
        int fd = open(path, O_RDONLY);
        if (fd == -1) {
            perror("open");
            close(sockfd);
            return;
        }

        // Read file content
        char file_buffer[MAX_BUFFER];
        ssize_t bytes_read = read(fd, file_buffer, MAX_BUFFER);
        if (bytes_read == -1) {
            perror("read");
            close(fd);
            close(sockfd);
            return;
        }

        // Send file content to client
        char http_response[MAX_BUFFER];
        snprintf(http_response, MAX_BUFFER, "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n%s", file_buffer);
        send(sockfd, http_response, strlen(http_response), 0);

        // Clean up
        close(fd);
    }

    // Close client connection
    close(sockfd);
}