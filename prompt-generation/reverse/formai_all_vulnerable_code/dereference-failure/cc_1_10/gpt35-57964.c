//FormAI DATASET v1.0 Category: Simple Web Server ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

#define RESPONSE_SIZE 1024

char* build_http_response(char* body) {
    char* response = malloc(RESPONSE_SIZE);
    snprintf(response, RESPONSE_SIZE, "HTTP/1.1 200 OK\r\n"
                                      "Content-Type: text/html\r\n"
                                      "Content-Length: %zd\r\n"
                                      "\r\n"
                                      "%s", strlen(body), body);
    return response;
}

void handle_request(int client_socket) {
    char buffer[1024];
    ssize_t count = recv(client_socket, buffer, sizeof(buffer), 0);
    if (count > 0) {
        char* response_body = "<html><head><title>Hello World</title></head><body><h1>Hello World</h1></body></html>";
        char* response = build_http_response(response_body);
        send(client_socket, response, strlen(response), 0);
        free(response);
    }
    close(client_socket);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }
    int port = atoi(argv[1]);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_address = {0};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(server_socket, 10) == -1) {
        perror("listen");
        return 1;
    }

    printf("Web server running on port %d\n", port);

    while (1) {
        struct sockaddr_in client_address = {0};
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_length);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }
        handle_request(client_socket);
    }

    return 0;
}