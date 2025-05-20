//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server is listening on port 8080...\n");

    while (1) {
        socklen_t client_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        char *request = (char *)malloc(1024);
        memset(request, 0, 1024);
        if (recv(client_socket, request, 1024, 0) == -1) {
            printf("Error receiving request\n");
            close(client_socket);
            free(request);
            continue;
        }

        if (strcmp(request, "GET / HTTP/1.1")!= 0) {
            printf("Invalid request\n");
            close(client_socket);
            free(request);
            continue;
        }

        char response[1024];
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\nHello, world!", strlen("Hello, world!"));
        send(client_socket, response, strlen(response), 0);

        close(client_socket);
        free(request);
    }

    close(server_socket);
    return 0;
}