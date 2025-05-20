//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen;
    int opt = 1;
    int client_port;
    char *message;

    if (argc!= 3) {
        printf("Usage:./server <port> <message>\n");
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    message = argv[2];
    client_port = ntohs(server_addr.sin_port);

    printf("Server started on port %d\n", client_port);
    printf("Waiting for client to connect...\n");

    addrlen = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);

    if (client_socket == -1) {
        printf("Error accepting connection\n");
        exit(1);
    }

    printf("Client connected\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        if (strcmp(buffer, "exit") == 0) {
            printf("Client disconnected\n");
            close(client_socket);
            break;
        }

        send(client_socket, message, strlen(message), 0);
    }

    close(server_socket);
    return 0;
}