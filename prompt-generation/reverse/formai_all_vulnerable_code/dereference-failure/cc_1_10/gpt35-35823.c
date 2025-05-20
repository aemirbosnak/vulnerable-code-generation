//FormAI DATASET v1.0 Category: Socket programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

void handle_client(int client_socket) {
    // receive message from client
    char buffer[MAX_BUFFER_SIZE];
    int recv_size = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    if (recv_size < 0) {
        perror("recv failed");
        return;
    }

    // print out received message
    printf("received message from client: %s\n", buffer);

    // send message back to client
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        return;
    }

    // close client socket
    close(client_socket);
}

void handle_connection(int server_socket) {
    int client_socket, size;
    struct sockaddr_in client_addr;

    size = sizeof(client_addr);
    memset(&client_addr, 0, size);

    // accept incoming connection
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&size);
    if (client_socket < 0) {
        perror("accept failed");
        return;
    }

    printf("connection accepted\n");

    handle_client(client_socket);

    // recursively handle incoming connections
    handle_connection(server_socket);
}

int main(int argc, char *argv[]) {
    int server_socket, port;

    if (argc != 2) {
        printf("usage: %s port\n", argv[0]);
        return 1;
    }
    port = atoi(argv[1]);

    // create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket creation failed");
        return 1;
    }

    // prepare sockaddr_in structure
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    // bind server socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        return 1;
    }

    // listen for incoming connections
    if (listen(server_socket, MAX_BUFFER_SIZE) < 0) {
        perror("listen failed");
        return 1;
    }

    printf("listening on port %d\n", port);

    // handle incoming connections recursively
    handle_connection(server_socket);

    // close server socket
    close(server_socket);

    return 0;
}