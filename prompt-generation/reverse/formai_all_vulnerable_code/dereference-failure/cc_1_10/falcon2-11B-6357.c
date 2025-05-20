//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_MESSAGE_LEN 256

int main(int argc, char *argv[]) {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char message[MAX_MESSAGE_LEN];

    // Initialize the server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server's address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind the server socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Error on listen");
        exit(1);
    }

    // Accept incoming connections
    printf("Waiting for connections...\n");
    while (1) {
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("Error on accept");
            exit(1);
        }

        // Read messages from clients
        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        if (read(new_socket, message, MAX_MESSAGE_LEN) < 0) {
            perror("Error reading from socket");
            exit(1);
        }

        // Send messages to all connected clients
        printf("Received: %s\n", message);
        if (send(new_socket, message, strlen(message), 0) < 0) {
            perror("Error writing to socket");
            exit(1);
        }

        // Send the message to all connected clients
        printf("Sending message to all connected clients: %s\n", message);
        if (sendto(new_socket, message, strlen(message), 0, (struct sockaddr *)&client_addr, client_len) < 0) {
            perror("Error writing to socket");
            exit(1);
        }

        // Close the connection
        close(new_socket);
    }

    close(server_socket);
    return 0;
}