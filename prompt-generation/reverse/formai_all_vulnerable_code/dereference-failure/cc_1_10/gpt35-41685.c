//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096   // Maximum buffer size

int main(int argc, char *argv[]) {
    if (argc != 3) {    // Checking command line arguments
        printf("Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0){
        perror("Error opening socket");
        return 1;
    }

    if (connect(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    int client_socket = accept(STDIN_FILENO, (struct sockaddr *) &client_addr, &client_addr_size);

    if (client_socket < 0) {
        perror("Error accepting client socket");
        return 1;
    }
    
    char buffer[BUFFER_SIZE];   // Initializing buffer to store client request

    ssize_t bytes_received;
    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {   // Loop to receive client request
        if (send(server_socket, buffer, bytes_received, 0) < 0) {   // Forwarding request to server
            perror("Error while forwarding client request to server");
            close(server_socket);
            close(client_socket);
            return 1;
        }

        memset(buffer, 0, BUFFER_SIZE);   // Reset buffer

        ssize_t bytes_sent;
        if ((bytes_sent = recv(server_socket, buffer, BUFFER_SIZE, 0)) < 0) {   // Receiving response from server
            perror("Error while receiving server response");
            close(server_socket);
            close(client_socket);
            return 1;
        }

        if (send(client_socket, buffer, bytes_sent, 0) < 0) {   // Forwarding response to client
            perror("Error while forwarding server response to client");
            close(server_socket);
            close(client_socket);
            return 1;
        }
    }

    close(server_socket);
    close(client_socket);

    return 0;
}