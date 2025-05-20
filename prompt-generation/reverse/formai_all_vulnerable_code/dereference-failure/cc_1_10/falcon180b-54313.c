//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int opt = TRUE;
    int addrlen = sizeof(client_addr);

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (TRUE) {
        memset(buffer, 0, BUFFER_SIZE);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        send(client_socket, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", strlen("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"), 0);

        close(client_socket);
    }

    close(server_socket);

    return 0;
}