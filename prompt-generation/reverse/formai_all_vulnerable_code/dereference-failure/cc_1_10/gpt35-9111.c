//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
#define MAX_CONNECTIONS 1024

static int create_server_socket(const int port) {
    int server_socket;
    struct sockaddr_in server_address;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(struct sockaddr_in));
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    int enable_reuseaddr = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &enable_reuseaddr, sizeof(enable_reuseaddr)) < 0) {
        perror("Failed to set socket option");
        exit(EXIT_FAILURE);
    }

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(struct sockaddr_in)) < 0) {
        perror("Failed to bind server socket to port");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("Failed to listen on server socket");
        exit(EXIT_FAILURE);
    }

    return server_socket;
}

static int handle_client_socket(int client_socket) {
    char request[BUFFER_SIZE];
    ssize_t request_length = recv(client_socket, request, BUFFER_SIZE, 0);
    if (request_length < 0) {
        perror("Failed to receive request from client");
        close(client_socket);
        return -1;
    }

    int server_socket;
    struct sockaddr_in server_address;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create server socket for request");
        close(client_socket);
        return -1;
    }

    memset(&server_address, 0, sizeof(struct sockaddr_in));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);

    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Failed to convert server IP address to network address");
        close(client_socket);
        return -1;
    }

    if (connect(server_socket, (struct sockaddr *) &server_address, sizeof(struct sockaddr_in)) < 0) {
        perror("Failed to connect to server");
        close(client_socket);
        return -1;
    }

    if (send(server_socket, request, request_length, 0) < 0) {
        perror("Failed to send request to server");
        close(server_socket);
        close(client_socket);
        return -1;
    }

    char response[BUFFER_SIZE];
    ssize_t response_length = recv(server_socket, response, BUFFER_SIZE, 0);
    if (response_length < 0) {
        perror("Failed to receive response from server");
        close(server_socket);
        close(client_socket);
        return -1;
    }

    if (send(client_socket, response, response_length, 0) < 0) {
        perror("Failed to send response to client");
        close(server_socket);
        close(client_socket);
        return -1;
    }

    close(server_socket);
    close(client_socket);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const int port = atoi(argv[1]);
    if (port <= 0) {
        fprintf(stderr, "Invalid port number\n");
        exit(EXIT_FAILURE);
    }

    const int server_socket = create_server_socket(port);
    printf("Listening on port %d\n", port);

    int client_socket;
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(struct sockaddr_in);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_size);
        if (client_socket < 0) {
            perror("Failed to accept incoming connection");
            continue;
        }

        printf("Accepted incoming connection\n");

        int flags = fcntl(client_socket, F_GETFL, 0);
        if (flags < 0) {
            perror("Failed to get client socket flags");
            close(client_socket);
            continue;
        }

        if (fcntl(client_socket, F_SETFL, flags | O_NONBLOCK) < 0) {
            perror("Failed to set client socket to non-blocking mode");
            close(client_socket);
            continue;
        }

        if (handle_client_socket(client_socket) < 0) {
            continue;
        }
    }

    return 0;
}