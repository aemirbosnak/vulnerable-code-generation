//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    // Initialize socket
    int server_socket = 0;
    struct sockaddr_in server_addr;
    int addr_len = sizeof(server_addr);

    // Create a socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Failed to create socket\n");
        exit(1);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Failed to bind socket\n");
        exit(1);
    }

    // Start listening on socket
    if (listen(server_socket, 5) < 0) {
        fprintf(stderr, "Failed to start listening on socket\n");
        exit(1);
    }

    printf("Server is now listening on port %d\n", ntohs(server_addr.sin_port));

    // Accept client connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            fprintf(stderr, "Failed to accept client connection\n");
            continue;
        }

        char buffer[1024];
        char *response = "Hello, welcome to the chat server!";

        // Send greeting to client
        send(client_socket, response, strlen(response), 0);

        // Receive message from client
        int message_len = recv(client_socket, buffer, 1024, 0);
        if (message_len < 0) {
            fprintf(stderr, "Failed to receive message from client\n");
            continue;
        }

        buffer[message_len] = '\0';
        printf("%s\n", buffer);

        // Send response to client
        response = "I received your message: %s\n", buffer;
        send(client_socket, response, strlen(response), 0);

        // Close client connection
        close(client_socket);
    }

    return 0;
}