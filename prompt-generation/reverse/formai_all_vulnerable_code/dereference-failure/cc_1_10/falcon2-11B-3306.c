//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFF_SIZE 4096

void handle_request(int client_socket, char *request) {
    // Process the request here
    printf("Received request: %s\n", request);

    // Send back a response
    char response[BUFF_SIZE] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello World!</h1></body></html>";
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <proxy-port>\n", argv[0]);
        exit(1);
    }

    int proxy_port = atoi(argv[1]);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        fprintf(stderr, "Failed to create socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(proxy_port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Failed to bind socket\n");
        exit(1);
    }

    listen(server_fd, 5);

    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd == -1) {
            fprintf(stderr, "Failed to accept connection\n");
            exit(1);
        }

        char buffer[BUFF_SIZE];
        int n = recv(client_fd, buffer, BUFF_SIZE, 0);
        if (n <= 0) {
            fprintf(stderr, "Failed to receive request\n");
            exit(1);
        }

        handle_request(client_fd, buffer);

        close(client_fd);
    }

    return 0;
}