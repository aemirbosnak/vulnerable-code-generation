//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void error_handling(char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    struct hostent* server;
    char buffer[BUFFER_SIZE];

    // Get the server information
    server = gethostbyname("localhost");
    if (server == NULL) {
        error_handling("gethostbyname() failed");
    }

    // Create a socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        error_handling("socket() failed");
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect() failed");
    }

    printf("Connected to server\n");

    // Send data to the server
    strcpy(buffer, "Hello, world!");
    if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
        error_handling("send() failed");
    }

    // Receive data from the server
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
        error_handling("recv() failed");
    }

    printf("Received from server: %s\n", buffer);

    // Close the socket
    if (close(client_socket) == -1) {
        error_handling("close() failed");
    }

    return 0;
}