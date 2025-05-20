//FormAI DATASET v1.0 Category: Networking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int create_socket(int port);
void handle_connection(int client_socket);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);

    int server_socket = create_socket(port);

    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);

    while (1) {
        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len);
        handle_connection(client_socket);
    }

    return 0;
}

int create_socket(int port)
{
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 0) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", port);

    return server_socket;
}

void handle_connection(int client_socket)
{
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    do {
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received < 0) {
            perror("Recv failed");
            exit(EXIT_FAILURE);
        }

        if (bytes_received == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Received %zd bytes from client\n", bytes_received);

        ssize_t bytes_sent = send(client_socket, buffer, bytes_received, 0);

        if (bytes_sent < 0) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }

        printf("Sent %zd bytes to client\n", bytes_sent);

    } while (bytes_received > 0);

    if (close(client_socket) < 0) {
        perror("Close failed");
        exit(EXIT_FAILURE);
    }
}