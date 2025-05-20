//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_REQUEST 2048
#define MAX_RESPONSE 8192

void send_response(int client_sock, char *response, int response_len) {
    send(client_sock, response, response_len, 0);
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Failed to create socket");
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind socket to address");
        return EXIT_FAILURE;
    }

    if (listen(server_sock, 5) == -1) {
        perror("Failed to listen for connections");
        return EXIT_FAILURE;
    }

    while (1) {
        client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sock == -1) {
            perror("Failed to accept connection");
            continue;
        }

        char request[MAX_REQUEST];
        int request_len = recv(client_sock, request, MAX_REQUEST - 1, 0);
        if (request_len == -1) {
            perror("Failed to receive request");
            close(client_sock);
            continue;
        }

        request[request_len] = '\0';

        char *method = strtok(request, " ");
        char *path = strtok(NULL, " ");

        if (strcmp(method, "GET") == 0) {
            char response[MAX_RESPONSE];
            int response_len = 0;

            if (strcmp(path, "/") == 0) {
                response_len = snprintf(response, MAX_RESPONSE, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<h1>Hello from the future!</h1>");
            } else {
                response_len = snprintf(response, MAX_RESPONSE, "HTTP/1.1 404 Not Found\nContent-Type: text/plain\n\n404 Not Found");
            }

            send_response(client_sock, response, response_len);
        }

        close(client_sock);
    }

    close(server_sock);

    return EXIT_SUCCESS;
}