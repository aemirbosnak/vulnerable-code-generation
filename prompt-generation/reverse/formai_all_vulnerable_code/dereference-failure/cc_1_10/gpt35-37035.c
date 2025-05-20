//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096
#define SERVER_PORT 8080
#define CLIENT_PORT 8888
#define MAX_CONNECTIONS 10

int server_sock = 0, client_sock = 0;
struct sockaddr_in server_addr, client_addr;
socklen_t client_addr_len = sizeof(client_addr);

bool running = true;

void handle_sigint(int sig) {
    running = false;
}

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received = 0;

    signal(SIGINT, handle_sigint);

    // Create server socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        error("Error creating server socket");
    }

    // Bind server socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error binding server socket");
    }

    // Listen for incoming connections
    if (listen(server_sock, MAX_CONNECTIONS) < 0) {
        error("Error listening for incoming connections");
    }

    printf("Proxy server running on port %d...\n", SERVER_PORT);

    while (running) {
        // Accept incoming connection from client
        client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_addr_len);

        if (client_sock < 0) {
            if (errno == EINTR) {
                continue;
            }

            error("Error accepting incoming connection");
        }

        printf("Accepted connection from %s:%d\n",
                inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Forward client request to server
        int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd < 0) {
            error("Error creating server socket");
        }

        struct sockaddr_in server_addr = {0};
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr("192.168.0.1");
        server_addr.sin_port = htons(80);

        if (connect(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
            error("Error connecting to server");
        }

        bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received < 0) {
            error("Error receiving client request");
        }

        if (send(server_sockfd, buffer, bytes_received, 0) < 0) {
            error("Error sending client request to server");
        }

        printf("Sent request to server:\n%s\n", buffer);

        // Receive server response and forward to client
        bytes_received = recv(server_sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received < 0) {
            error("Error receiving server response");
        }

        if (send(client_sock, buffer, bytes_received, 0) < 0) {
            error("Error sending server response to client");
        }

        printf("Sent response to client:\n%s\n", buffer);

        close(server_sockfd);
        close(client_sock);
    }

    printf("Shutting down proxy server...\n");

    close(server_sock);

    return 0;
}