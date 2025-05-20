//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: safe
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

void handle_client(int client_socket, struct sockaddr_in server_address) {
    char buffer[BUFFER_SIZE];
    memset(&buffer, 0, sizeof(buffer));

    // creating a socket for the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // connecting to the server
    if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }

    // forwarding requests from the client to the server
    while (true) {
        int read = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (read < 0) {
            perror("Recv from client failed");
            exit(EXIT_FAILURE);
        } else if (read == 0) {
            break;
        } else {
            if (send(server_socket, buffer, read, 0) < 0) {
                perror("Send to server failed");
                exit(EXIT_FAILURE);
            }
        }
        memset(&buffer, 0, sizeof(buffer));
    }

    close(server_socket);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <port> <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    // setting up the server address
    server_address.sin_family = AF_INET; 
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, argv[2], &server_address.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    // creating a socket for the client
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // binding the socket to the specified port number
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // listening for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server started on port %d...\n", port);

    while (true) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        handle_client(client_socket, server_address);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}