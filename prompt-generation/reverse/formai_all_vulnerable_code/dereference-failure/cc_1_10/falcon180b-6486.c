//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 5
#define MAX_REQUEST_SIZE 1024

void handle_request(int client_socket) {
    char request[MAX_REQUEST_SIZE];
    if (recv(client_socket, request, MAX_REQUEST_SIZE, 0) <= 0) {
        close(client_socket);
        return;
    }

    printf("Received request: %s\n", request);

    char response[MAX_REQUEST_SIZE];
    snprintf(response, MAX_REQUEST_SIZE, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\nHello, World!", strlen(request));

    send(client_socket, response, strlen(response), 0);
    close(client_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Failed to bind socket: %s\n", strerror(errno));
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, BACKLOG) == -1) {
        fprintf(stderr, "Failed to listen on socket: %s\n", strerror(errno));
        close(server_socket);
        return 1;
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            fprintf(stderr, "Failed to accept connection: %s\n", strerror(errno));
            continue;
        }

        printf("Accepted connection from client\n");

        handle_request(client_socket);
    }

    close(server_socket);
    return 0;
}