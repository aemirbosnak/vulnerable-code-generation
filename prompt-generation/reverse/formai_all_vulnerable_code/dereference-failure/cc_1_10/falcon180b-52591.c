//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in listen_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Create socket
    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Set up listen address
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(8080);
    listen_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to address
    if (bind(listen_socket, (struct sockaddr*)&listen_addr, sizeof(listen_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(2);
    }

    // Listen for incoming connections
    if (listen(listen_socket, 5) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        exit(3);
    }

    printf("Proxy server listening on port 8080\n");

    while (1) {
        // Accept incoming connection
        client_socket = accept(listen_socket, (struct sockaddr*)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        // Forward data between client and server
        while (1) {
            bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received == 0) {
                printf("Client disconnected\n");
                break;
            }
            if (bytes_received == -1) {
                printf("Error receiving data: %s\n", strerror(errno));
                break;
            }
            send(client_socket, buffer, bytes_received, 0);
        }

        // Close client socket
        close(client_socket);
    }

    close(listen_socket);
    return 0;
}