//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define BUFFERSIZE 1024

// Function to handle a client connection
void handle_client(int client_socket) {
    char buffer[BUFFERSIZE];
    while (TRUE) {
        memset(buffer, 0, BUFFERSIZE);
        int bytes_received = recv(client_socket, buffer, BUFFERSIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Received message: %s\n", buffer);
        send(client_socket, buffer, strlen(buffer), 0);
    }
    close(client_socket);
}

// Function to handle multiple client connections
void handle_connections(int server_socket) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    while (TRUE) {
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        handle_client(client_socket);
    }
}

// Main function
int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, BACKLOG) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        close(server_socket);
        return 1;
    }

    printf("Server listening on port %d\n", PORT);
    handle_connections(server_socket);

    close(server_socket);
    return 0;
}