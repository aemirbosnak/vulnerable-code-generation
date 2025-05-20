//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 10
#define SERVER_NAME "localhost"
#define SERVER_PORT "8080"

void handle_request(int client_socket);

int main() {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_size;

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_NAME, &server_addr.sin_addr);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server started on port %s\n", SERVER_PORT);

    while (1) {
        client_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_size);
        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        handle_request(client_socket);

        close(client_socket);
    }

    return 0;
}

void handle_request(int client_socket) {
    char buffer[1024];
    ssize_t bytes_received;
    char *response = "HTTP/1.1 200 OK\r\nContent-Length: 12\r\nConnection: close\r\n\r\nHello, World!";

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        if (send(client_socket, response, strlen(response), 0) == -1) {
            printf("Error sending response: %s\n", strerror(errno));
            break;
        }
    }

    close(client_socket);
}