//Falcon2-11B DATASET v1.0 Category: Networking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 1234
#define BUFFER_SIZE 1024

int main() {
    int socket_fd, bytes_read;
    struct sockaddr_in server_addr;
    struct hostent* server;

    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Error in creating socket");
        exit(EXIT_FAILURE);
    }

    // Set the address of the server
    server = gethostbyname("localhost");
    if (server == NULL) {
        perror("Error in getting server address");
        exit(EXIT_FAILURE);
    }
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error in connecting to server");
        exit(EXIT_FAILURE);
    }

    // Send a message
    char message[BUFFER_SIZE];
    strcpy(message, "Hello, world!");
    send(socket_fd, message, strlen(message), 0);

    // Receive a message
    bytes_read = recv(socket_fd, message, BUFFER_SIZE, 0);
    printf("Received message: %s\n", message);

    // Close the socket
    close(socket_fd);
    return 0;
}