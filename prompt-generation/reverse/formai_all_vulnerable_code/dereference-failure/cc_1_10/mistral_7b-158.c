//MISTRAL-7B DATASET v1.0 Category: Simple Web Server ; Style: interoperable
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation error");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (true) {
        int client_len = sizeof(struct sockaddr_in);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        handle_client(client_socket);

        close(client_socket);
    }

    close(server_socket);
    return EXIT_SUCCESS;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE] = {0};
    int read_size;

    // Send HTTP response header
    send(client_socket, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n", strlen("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n"), 0);

    // Read request from client
    read_size = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (read_size <= 0) {
        perror("Error reading from socket");
        return;
    }

    printf("Request received:\n%s\n", buffer);

    // Generate dynamic response based on request
    char response[BUFFER_SIZE] = {0};
    snprintf(response, BUFFER_SIZE, "Hello, %s! Welcome to my Simple Web Server.", strtok(buffer, " " + 2)[0]);

    // Send dynamic response to client
    send(client_socket, response, strlen(response), 0);
}