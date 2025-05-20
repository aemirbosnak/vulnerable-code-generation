//FormAI DATASET v1.0 Category: Simple Web Server ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 1024

void send_response(int client_socket, const char *response, int response_length) {
    send(client_socket, response, response_length, 0);
}

int main(int argc, char **argv) {

    if (argc < 2) {
        printf("Usage: %s [port]\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating server socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding server socket\n");
        exit(1);
    }

    if (listen(server_socket, 10) == -1) {
        printf("Error listening on server socket\n");
        exit(1);
    }

    printf("Server running on port %d\n", port);
    printf("Press Ctrl+C to quit\n");

    while (true) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);

        if (client_socket == -1) {
            printf("Error accepting client connection\n");
        } else {
            printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        }

        char request[MAX_REQUEST_SIZE];
        int request_length = recv(client_socket, request, MAX_REQUEST_SIZE - 1, 0);

        if (request_length == -1) {
            printf("Error receiving request from client\n");
        } else {
            printf("Received request from client (%d bytes):\n%s\n", request_length, request);
        }

        char response[MAX_RESPONSE_SIZE];
        int response_length = snprintf(response, MAX_RESPONSE_SIZE, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\nHello, world!\r\n");

        send_response(client_socket, response, response_length);

        close(client_socket);
    }

    close(server_socket);

    return 0;
}