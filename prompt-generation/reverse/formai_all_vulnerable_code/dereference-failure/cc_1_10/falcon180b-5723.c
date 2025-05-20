//Falcon-180B DATASET v1.0 Category: Networking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_REQUEST_SIZE 1024
#define RESPONSE_HEADER "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n"

void handle_client(int client_socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen;
    char buffer[MAX_REQUEST_SIZE];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        close(server_socket);
        exit(1);
    }

    if (listen(server_socket, BACKLOG) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        close(server_socket);
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        addrlen = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        handle_client(client_socket);

        close(client_socket);
    }

    return 0;
}

void handle_client(int client_socket) {
    char request[MAX_REQUEST_SIZE];
    int bytes_received, total_bytes_received = 0;

    while (1) {
        memset(request, 0, sizeof(request));
        bytes_received = recv(client_socket, request, MAX_REQUEST_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }

        total_bytes_received += bytes_received;

        if (total_bytes_received == 0) {
            send(client_socket, "HTTP/1.1 400 Bad Request\r\n\r\n", strlen("HTTP/1.1 400 Bad Request\r\n\r\n"), 0);
            close(client_socket);
            return;
        }

        if (strncmp(request, "GET /", 5) == 0) {
            send(client_socket, RESPONSE_HEADER, strlen(RESPONSE_HEADER), 0);
            send(client_socket, "<html><body><h1>Hello, World!</h1></body></html>", strlen("<html><body><h1>Hello, World!</h1></body></html>"), 0);
            break;
        }
    }
}