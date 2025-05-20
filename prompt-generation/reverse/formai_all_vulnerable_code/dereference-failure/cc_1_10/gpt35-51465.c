//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <port> <proxy_address:port>\n", argv[0]);
        exit(1);
    }

    int server_port = atoi(argv[1]);
    int buffer_size = BUFFER_SIZE;
    int client_socket_fd, server_socket_fd;
    char buffer[buffer_size];
    struct sockaddr_in client_address, server_address;
    socklen_t client_address_size = sizeof(client_address), server_address_size = sizeof(server_address);

    printf("\n");
    printf("============================================================\n");
    printf("===== Welcome to the Simple HTTP Proxy Server Program! =====\n");
    printf("============================================================\n\n");

    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        handle_error("Could not create server socket");
    }

    memset(&server_address, 0, server_address_size);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    server_address.sin_addr.s_addr = inet_addr(argv[2]);

    if (bind(server_socket_fd, (struct sockaddr *)&server_address, server_address_size) == -1) {
        handle_error("Could not bind server socket");
    }

    if (listen(server_socket_fd, 10) == -1) {
        handle_error("Could not listen on server socket");
    }

    while (1) {
        printf("\n");
        printf("================================================================\n");
        printf("==================== Waiting for Client Request... ===========\n");
        printf("================================================================\n\n");

        if ((client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_address, &client_address_size)) == -1) {
            handle_error("Could not accept client connection");
        }

        printf("Connected to Client!\n");

        memset(buffer, 0, buffer_size);

        if (recv(client_socket_fd, buffer, buffer_size, 0) == -1) {
            handle_error("Could not receive message from client");
        }

        printf("Proxy Received Request from Client:\n\n");
        printf("%s\n\n", buffer);

        if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            handle_error("Could not create server socket");
        }

        if (connect(server_socket_fd, (struct sockaddr*)&server_address, server_address_size) == -1) {
            handle_error("Could not connect to server");
        }

        if (send(server_socket_fd, buffer, strlen(buffer), 0) == -1) {
            handle_error("Could not send message to server");
        }

        printf("Proxy Sent Request to Server:\n\n");
        printf("%s\n\n", buffer);

        memset(buffer, 0, buffer_size);

        if (recv(server_socket_fd, buffer, buffer_size, 0) == -1) {
            handle_error("Could not receive message from server");
        }

        printf("Proxy Received Response from Server:\n\n");
        printf("%s\n\n", buffer);

        if (send(client_socket_fd, buffer, strlen(buffer), 0) == -1) {
            handle_error("Could not send message to client");
        }

        printf("Proxy Sent Response to Client:\n\n");
        printf("%s\n\n", buffer);

        close(client_socket_fd);
        close(server_socket_fd);
    }

    close(server_socket_fd);

    return 0;
}