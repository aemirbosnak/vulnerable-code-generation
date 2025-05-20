//FormAI DATASET v1.0 Category: Networking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check for proper usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Parse port number
    int port = atoi(argv[1]);

    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    // Bind socket to port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server is listening on port %d\n", port);

    // Accept incoming connections
    struct sockaddr_in client_address;
    int client_socket;
    char buffer[BUFFER_SIZE];
    while (1) {
        socklen_t client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket == -1) {
            perror("accept");
            exit(1);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Receive data from client
        memset(buffer, 0, BUFFER_SIZE);
        int receive_result = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (receive_result == -1) {
            perror("recv");
            exit(1);
        }

        printf("Received message from client: %s\n", buffer);

        // Echo data back to client
        int send_result = send(client_socket, buffer, receive_result, 0);
        if (send_result == -1) {
            perror("send");
            exit(1);
        }

        printf("Sent message back to client: %s\n", buffer);

        // Close client socket
        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}