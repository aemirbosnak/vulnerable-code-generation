//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket;
    int client_socket[MAX_CLIENTS];
    int opt = 1;
    char *message = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n<html><body><h1>Welcome to my web server!</h1></body></html>";
    char buffer[BUFFER_SIZE];
    int addrlen, client_len;
    struct sockaddr_in server_addr, client_addr;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        addrlen = sizeof(client_addr);
        if ((client_socket[0] = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen)) == -1) {
            fprintf(stderr, "Error accepting connection\n");
            exit(1);
        }

        send(client_socket[0], message, strlen(message), 0);
        close(client_socket[0]);
    }

    return 0;
}