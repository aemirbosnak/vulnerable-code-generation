//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int server_socket, client_socket, numbytes;
    struct sockaddr_in server_address, client_address;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Configure server socket
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Error listening on socket");
        return 1;
    }

    printf("Server started, listening on port %d\n", PORT);

    // Accept client connection
    if ((client_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&numbytes)) < 0) {
        perror("Error accepting connection");
        return 1;
    }

    printf("Connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    char message[100];
    char client_message[100];

    // Receive client message
    if (read(client_socket, message, 100) < 0) {
        perror("Error reading from socket");
        return 1;
    }

    printf("Received: %s\n", message);

    // Send server message
    sprintf(client_message, "Hello, client! Your message was received.");
    if (write(client_socket, client_message, strlen(client_message)) < 0) {
        perror("Error writing to socket");
        return 1;
    }

    close(client_socket);

    return 0;
}