//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 65535

int open_client_socket(const char *server_ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        return -1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid server IP address");
        close(sock);
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        close(sock);
        return -1;
    }

    return sock;
}

void handle_client_request(int client_socket, const struct sockaddr_in *client_addr, const char *server_ip, int server_port) {
    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        perror("Failed to receive client request");
        return;
    }

    // Connect to remote server
    int server_socket = open_client_socket(server_ip, server_port);
    if (server_socket < 0) {
        return;
    }

    ssize_t bytes_sent = send(server_socket, buffer, bytes_received, 0);
    if (bytes_sent < 0) {
        perror("Failed to send request to server");
        close(server_socket);
        return;
    }

    // Forward response to client
    while (1) {
        bytes_received = recv(server_socket, buffer, MAX_BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }

        bytes_sent = send(client_socket, buffer, bytes_received, 0);
        if (bytes_sent < 0) {
            perror("Failed to send response to client");
            close(server_socket);
            return;
        }
    }

    close(server_socket);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <listen port> <server IP> <server port>\n", argv[0]);
        return 1;
    }

    int listen_port = atoi(argv[1]);
    const char *server_ip = argv[2];
    int server_port = atoi(argv[3]);

    // Create socket to listen for incoming client connections
    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket < 0) {
        perror("Failed to create listen socket");
        return 1;
    }

    int optval = 1;
    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind to local address and port
    struct sockaddr_in listen_addr;
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    listen_addr.sin_port = htons(listen_port);
    if (bind(listen_socket, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("Failed to bind to local address and port");
        close(listen_socket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(listen_socket, SOMAXCONN) < 0) {
        perror("Failed to listen for incoming connections");
        close(listen_socket);
        return 1;
    }

    printf("Listening for incoming connections on port %d...\n", listen_port);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_addr_len);

        if (client_socket < 0) {
            perror("Failed to accept incoming connection");
            continue;
        }

        printf("Received incoming connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        handle_client_request(client_socket, &client_addr, server_ip, server_port);

        close(client_socket);
    }

    close(listen_socket);

    return 0;
}