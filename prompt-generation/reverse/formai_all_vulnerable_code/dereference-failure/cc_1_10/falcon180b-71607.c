//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket, bytes_received;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(server_socket, BACKLOG) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received == 0) {
            printf("Client disconnected\n");
            close(server_socket);
            exit(0);
        }

        printf("Received message: %s\n", buffer);

        send(server_socket, buffer, bytes_received, 0);
    }

    return 0;
}