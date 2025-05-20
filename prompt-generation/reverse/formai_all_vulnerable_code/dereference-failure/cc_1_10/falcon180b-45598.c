//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

// Function to log messages
void log(const char* message) {
    fprintf(stderr, "%s\n", message);
}

// Function to send a response to the client
void send_response(int client_socket, int status_code, const char* status_message, const char* content_type, const char* content) {
    char response[512];
    sprintf(response, "HTTP/1.1 %d %s\r\nContent-Type: %s\r\nContent-Length: %d\r\n\r\n%s", status_code, status_message, content_type, strlen(content), content);
    send(client_socket, response, strlen(response), 0);
}

// Function to handle a client request
void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);

    char* method = strtok(buffer, " ");
    char* path = strtok(NULL, " ");

    if (strcmp(method, "GET") == 0) {
        char host[BUFFER_SIZE];
        strcpy(host, "127.0.0.1");
        int port = 80;

        int server_socket = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, host, &server_addr.sin_addr);

        connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

        char request[BUFFER_SIZE];
        sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
        send(server_socket, request, strlen(request), 0);

        char response[BUFFER_SIZE];
        memset(response, 0, BUFFER_SIZE);
        recv(server_socket, response, BUFFER_SIZE, 0);

        send_response(client_socket, 200, "OK", "text/html", response);

        close(server_socket);
    } else {
        send_response(client_socket, 405, "Method Not Allowed", "text/html", "Method not allowed");
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, 10);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        log("Client connected");

        handle_request(client_socket);

        close(client_socket);
    }

    return 0;
}