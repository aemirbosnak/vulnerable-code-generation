//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080

void handle_request(int client_socket) {
    char request[BUFFER_SIZE];
    memset(request, 0, BUFFER_SIZE);

    int bytes_received = recv(client_socket, request, BUFFER_SIZE, 0);
    if(bytes_received <= 0) {
        printf("Client disconnected\n");
        return;
    }

    char *method = strtok(request, " ");
    char *path = strtok(NULL, " ");

    if(strcmp(method, "GET") == 0) {
        char response[BUFFER_SIZE];
        snprintf(response, BUFFER_SIZE, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n", strlen(path));

        send(client_socket, response, strlen(response), 0);
        send(client_socket, path, strlen(path), 0);
    } else {
        char response[BUFFER_SIZE];
        snprintf(response, BUFFER_SIZE, "HTTP/1.1 405 Method Not Allowed\r\n\r\n");

        send(client_socket, response, strlen(response), 0);
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    listen(server_socket, 5);

    while(1) {
        int client_socket = accept(server_socket, NULL, NULL);
        printf("Client connected\n");

        handle_request(client_socket);

        close(client_socket);
    }

    return 0;
}