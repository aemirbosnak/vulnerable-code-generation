//FormAI DATASET v1.0 Category: Networking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // check if the necessary arguments are provided
    if (argc != 2) {
        printf("Usage: ./server <port>\n");
        return 1;
    }

    int port = atoi(argv[1]);

    // create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    // bind socket to address and port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) == -1) {
        printf("Failed to bind socket\n");
        close(server_socket);
        return 1;
    }

    // listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Failed to listen for connections\n");
        close(server_socket);
        return 1;
    }

    printf("Server is listening on port %d\n", port);

    // accept incoming connections
    struct sockaddr_in client_address;
    int client_address_len = sizeof(client_address);

    int client_socket;
    char buffer[BUFFER_SIZE];

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address_len);

        if (client_socket == -1) {
            printf("Failed to accept connection\n");
            continue;
        }

        printf("New client connected with IP %s and port %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // receive data from client
        while (recv(client_socket, buffer, BUFFER_SIZE, 0) > 0) {
            printf("Received from client: %s", buffer);

            // send data back to client
            if (send(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
                printf("Failed to send data to client\n");
                close(client_socket);
                break;
            }
        }

        printf("Client with IP %s and port %d disconnected\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        close(client_socket);
    }

    close(server_socket);
    return 0;
}