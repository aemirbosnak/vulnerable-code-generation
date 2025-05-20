//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

// Function to handle client connections
void handle_client(int client_socket) {
    char buffer[BUF_SIZE];
    int bytes_received;
    while ((bytes_received = recv(client_socket, buffer, BUF_SIZE, 0)) > 0) {
        send(client_socket, buffer, bytes_received, 0);
    }
    close(client_socket);
}

// Function to handle server connections
void handle_server(int server_socket, int client_socket) {
    char buffer[BUF_SIZE];
    int bytes_received, bytes_sent;
    while ((bytes_received = recv(server_socket, buffer, BUF_SIZE, 0)) > 0) {
        send(client_socket, buffer, bytes_received, 0);
    }
    close(server_socket);
    close(client_socket);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <port> <host>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    char *host = argv[2];

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct hostent *server;
    server = gethostbyname(host);
    if (server == NULL) {
        printf("No such host\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    // Listen for client connections
    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t addr_size = sizeof(client_addr);
    while ((client_socket = accept(socket_fd, (struct sockaddr *)&client_addr, &addr_size)) > 0) {
        printf("Client connected\n");
        handle_client(client_socket);
    }

    close(socket_fd);
    return 0;
}