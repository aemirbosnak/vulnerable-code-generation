//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, client_addr_size;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received, bytes_sent;
    char *request;
    char *response;
    int response_len;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDR, &server_addr.sin_addr);

    connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Proxy started on port %d\n", SERVER_PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            perror("accept");
            exit(1);
        }

        request = malloc(BUFFER_SIZE);
        if (request == NULL) {
            perror("malloc");
            exit(1);
        }

        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            perror("recv");
            exit(1);
        }

        buffer[bytes_received] = '\0';
        strcpy(request, buffer);

        response = malloc(BUFFER_SIZE);
        if (response == NULL) {
            perror("malloc");
            exit(1);
        }

        response_len = sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n", strlen(request));

        send(client_socket, response, response_len, 0);
        send(client_socket, request, strlen(request), 0);

        close(client_socket);
        free(request);
        free(response);
    }

    close(server_socket);
    return 0;
}