//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

// Create a socket
int create_socket(int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    // Bind the socket to the port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        exit(1);
    }

    return sockfd;
}

// Accept a connection
int accept_connection(int sockfd) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sockfd == -1) {
        perror("accept");
        exit(1);
    }

    return client_sockfd;
}

// Handle a connection
void handle_connection(int client_sockfd) {
    char buffer[BUFFER_SIZE];
    while (1) {
        // Read from the client
        int bytes_read = read(client_sockfd, buffer, BUFFER_SIZE);
        if (bytes_read == -1) {
            perror("read");
            exit(1);
        } else if (bytes_read == 0) {
            // Client has closed the connection
            break;
        }

        // Process the request
        char *request = strtok(buffer, "\r\n");
        char *method = strtok(request, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, " ");

        // Send a response
        char response[BUFFER_SIZE];
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, world!</h1></body></html>\r\n");
        int bytes_written = write(client_sockfd, response, strlen(response));
        if (bytes_written == -1) {
            perror("write");
            exit(1);
        }

        // Close the connection
        close(client_sockfd);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    int sockfd = create_socket(atoi(argv[1]));

    // Accept connections
    while (1) {
        int client_sockfd = accept_connection(sockfd);

        // Handle the connection
        handle_connection(client_sockfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}