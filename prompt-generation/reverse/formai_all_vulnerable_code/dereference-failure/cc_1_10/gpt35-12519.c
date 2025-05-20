//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFSIZE 8192

void handle_error(char *msg) {
    fprintf(stderr, "Error: %s (%s)\n", msg, strerror(errno));
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <listen-port> <server-port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int listen_port = atoi(argv[1]);
    int server_port = atoi(argv[2]);

    // Create a TCP socket for listening
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        handle_error("Failed to create listening socket");
    }

    // Bind the socket to the given port and address
    struct sockaddr_in listen_addr = {0};
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(listen_port);
    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        handle_error("Failed to bind listening socket");
    }

    // Listen for incoming connections
    if (listen(listen_sock, 5) < 0) {
        handle_error("Failed to listen on socket");
    }

    // Accept incoming connections and proxy them to the server
    while (1) {
        // Accept the connection
        struct sockaddr_in client_addr = {0};
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock < 0) {
            handle_error("Failed to accept connection");
        }

        // Create a TCP socket for the server
        int server_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sock < 0) {
            handle_error("Failed to create server socket");
        }

        // Connect to the server
        struct sockaddr_in server_addr = {0};
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        server_addr.sin_port = htons(server_port);
        if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            handle_error("Failed to connect to server");
        }

        // Receive the HTTP request from the client
        char buf[BUFSIZE];
        ssize_t total_recv = 0;
        while (total_recv < BUFSIZE) {
            ssize_t num_recv = recv(client_sock, buf + total_recv, BUFSIZE - total_recv, 0);
            if (num_recv < 0) {
                handle_error("Failed to receive data from client");
            } else if (num_recv == 0) {
                break;
            }
            total_recv += num_recv;
        }

        // Forward the HTTP request to the server
        if (send(server_sock, buf, total_recv, 0) < 0) {
            handle_error("Failed to send data to server");
        }

        // Receive the HTTP response from the server
        ssize_t total_sent = 0;
        while (total_sent < total_recv) {
            ssize_t num_sent = send(client_sock, buf + total_sent, total_recv - total_sent, 0);
            if (num_sent < 0) {
                handle_error("Failed to send data to client");
            } else if (num_sent == 0) {
                break;
            }
            total_sent += num_sent;
        }

        // Close the sockets
        close(server_sock);
        close(client_sock);
    }

    return 0;
}