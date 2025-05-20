//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    int socket_fd, n;
    struct sockaddr_in server_addr;
    struct hostent* server_name;
    char buffer[MAX_BUFFER_SIZE];
    char* message = "USER romeo\r\n";

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Failed to create socket\n");
        return 1;
    }

    // Resolve server address
    server_name = gethostbyname("pop.example.com");
    if (server_name == NULL) {
        printf("Failed to resolve server address\n");
        return 1;
    }

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    memcpy(&server_addr.sin_addr.s_addr, server_name->h_addr, server_name->h_length);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to connect to server\n");
        return 1;
    }

    // Send authentication message
    n = send(socket_fd, message, strlen(message), 0);
    if (n < 0) {
        printf("Failed to send authentication message\n");
        return 1;
    }

    // Read server response
    bzero(buffer, MAX_BUFFER_SIZE);
    n = recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0);
    if (n < 0) {
        printf("Failed to read server response\n");
        return 1;
    }

    // Print server response
    printf("Server response: %s\n", buffer);

    // Close socket
    close(socket_fd);

    return 0;
}