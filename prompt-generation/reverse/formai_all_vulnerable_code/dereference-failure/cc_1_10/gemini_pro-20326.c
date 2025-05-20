//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

// Define the maximum size of a request buffer
#define REQUEST_BUFFER_SIZE 1024

// Define the maximum number of clients that can be connected to the proxy at once
#define MAX_CLIENTS 10

// Create a socket for the proxy server to listen on
int create_server_socket(int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    return sockfd;
}

// Handle a client connection
void handle_client(int clientfd) {
    char request_buffer[REQUEST_BUFFER_SIZE];
    char *host;
    char *path;
    char *port;
    int host_len;
    int path_len;
    int port_len;
    int request_len;

    // Read the request from the client
    request_len = read(clientfd, request_buffer, REQUEST_BUFFER_SIZE);
    if (request_len == -1) {
        perror("read");
        exit(1);
    }

    // Parse the request
    host = strstr(request_buffer, "Host: ");
    if (host == NULL) {
        fprintf(stderr, "Invalid request: missing Host header\n");
        exit(1);
    }
    host = host + strlen("Host: ");
    host_len = strcspn(host, "\r\n");

    path = strstr(request_buffer, "GET ");
    if (path == NULL) {
        fprintf(stderr, "Invalid request: missing GET request line\n");
        exit(1);
    }
    path = path + strlen("GET ");
    path_len = strcspn(path, " ");

    port = strstr(host, ":");
    if (port == NULL) {
        port = "80";
        port_len = 2;
    } else {
        port_len = strcspn(port + 1, "\r\n");
    }

    // Connect to the server
    int serverfd;
    struct sockaddr_in serveraddr;

    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(host);
    serveraddr.sin_port = htons(atoi(port));

    if (connect(serverfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send the request to the server
    if (write(serverfd, request_buffer, request_len) == -1) {
        perror("write");
        exit(1);
    }

    // Read the response from the server
    char response_buffer[REQUEST_BUFFER_SIZE];
    int response_len;
    do {
        response_len = read(serverfd, response_buffer, REQUEST_BUFFER_SIZE);
        if (response_len == -1) {
            perror("read");
            exit(1);
        }

        // Send the response to the client
        if (write(clientfd, response_buffer, response_len) == -1) {
            perror("write");
            exit(1);
        }
    } while (response_len > 0);

    // Close the client connection
    close(clientfd);

    // Close the server connection
    close(serverfd);
}

// Main function
int main(int argc, char **argv) {
    // Check the command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Create the server socket
    int serverfd = create_server_socket(atoi(argv[1]));

    // Main loop
    while (1) {
        // Accept a client connection
        int clientfd;
        struct sockaddr_in clientaddr;
        socklen_t clientaddr_len;

        clientfd = accept(serverfd, (struct sockaddr *)&clientaddr, &clientaddr_len);
        if (clientfd == -1) {
            perror("accept");
            exit(1);
        }

        // Handle the client connection
        handle_client(clientfd);
    }

    // Close the server socket
    close(serverfd);

    return 0;
}