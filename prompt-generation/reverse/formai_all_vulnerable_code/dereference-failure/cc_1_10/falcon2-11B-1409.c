//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int server_fd, client_fd, port_num;
    struct sockaddr_in server_addr, client_addr;
    char buffer[256];

    // Create a TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi("5000"));

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR on binding");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("ERROR on listen");
        exit(EXIT_FAILURE);
    }

    // Accept a connection from a client
    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&port_num)) < 0) {
        perror("ERROR on accept");
        exit(EXIT_FAILURE);
    }

    // Receive a message from the client
    recv(client_fd, buffer, sizeof(buffer), 0);
    printf("Received message from client: %s\n", buffer);

    // Send a message back to the client
    send(client_fd, buffer, strlen(buffer), 0);

    // Close the socket
    close(client_fd);
    close(server_fd);

    return 0;
}