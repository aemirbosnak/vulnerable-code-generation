//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

// The server function
int server_function(int port) {
    int server_socket;
    struct sockaddr_in server_address;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("ERROR opening socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(server_socket, 5);

    int client_socket;
    struct sockaddr_in client_address;
    socklen_t client_len = sizeof(client_address);

    client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_len);
    if (client_socket == -1) {
        perror("ERROR on accepting");
        exit(1);
    }

    printf("Connected to %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    // Now read and print client messages
    char buffer[256];
    ssize_t read_size = recv(client_socket, buffer, 256, 0);
    if (read_size <= 0) {
        printf("ERROR reading from socket\n");
        exit(1);
    }
    printf("Client: %s\n", buffer);

    send(client_socket, "Hello, client!", strlen("Hello, client!"), 0);

    close(client_socket);

    return 0;
}

// The client function
int client_function(char* host, int port) {
    int client_socket;
    struct sockaddr_in server_address;
    socklen_t server_len = sizeof(server_address);

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("ERROR opening socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(host);

    if (connect(client_socket, (struct sockaddr*)&server_address, server_len) == -1) {
        perror("ERROR connecting to server");
        exit(1);
    }

    printf("Connected to %s:%d\n", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));

    // Now write and print server messages
    char buffer[256];
    printf("Client: Hello, server!\n");
    send(client_socket, "Hello, server!", strlen("Hello, server!"), 0);

    ssize_t read_size = recv(client_socket, buffer, 256, 0);
    if (read_size <= 0) {
        printf("ERROR reading from socket\n");
        exit(1);
    }
    printf("Server: %s\n", buffer);

    close(client_socket);

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <port> <host>\n", argv[0]);
        exit(1);
    }

    server_function(atoi(argv[1]));

    client_function(argv[2], atoi(argv[1]));

    return 0;
}