//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int server_socket, client_socket[MAX_CLIENTS], client_socket_count = 0;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    int addrlen;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        return 2;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        return 3;
    }

    printf("Server is listening on port %d\n", SERVER_PORT);

    while (1) {
        addrlen = sizeof(client_addr[client_socket_count]);
        if ((client_socket[client_socket_count] = accept(server_socket, (struct sockaddr *)&client_addr[client_socket_count], &addrlen)) == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            return 4;
        }
        client_socket_count++;
        printf("Client connected: %s:%d\n", inet_ntoa(client_addr[client_socket_count].sin_addr), ntohs(client_addr[client_socket_count].sin_port));

        if (client_socket_count >= MAX_CLIENTS) {
            fprintf(stderr, "Maximum number of clients reached\n");
            return 5;
        }
    }

    return 0;
}