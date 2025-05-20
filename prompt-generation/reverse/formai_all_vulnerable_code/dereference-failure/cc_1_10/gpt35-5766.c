//FormAI DATASET v1.0 Category: Socket programming ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv) {
    int port_number;
    int server_socket;
    int new_socket;
    int result;

    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    char buffer[BUFFER_SIZE];

    // Check if the user provided the correct number of arguments
    if (argc != 2) {
        printf("Usage: ./server <port number>\n");
        exit(EXIT_FAILURE);
    }

    // Parse the port number from the command line argument
    port_number = atoi(argv[1]);

    // Create a new socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_number);

    // Bind the socket to the server address
    result = bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    if (result == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    result = listen(server_socket, 5);
    if (result == -1) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    int client_address_len = sizeof(client_address);
    new_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len);
    if (new_socket == -1) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    // Receive data from the client
    memset(buffer, 0, BUFFER_SIZE);
    result = recv(new_socket, buffer, BUFFER_SIZE, 0);
    if (result == -1) {
        perror("Error receiving data from client");
        exit(EXIT_FAILURE);
    }

    // Print out the data received from the client
    printf("Received '%s' from client\n", buffer);

    // Send a response back to the client
    char* response = "Hello, client!";
    result = send(new_socket, response, strlen(response), 0);
    if (result == -1) {
        perror("Error sending data to client");
        exit(EXIT_FAILURE);
    }

    // Close the sockets
    close(new_socket);
    close(server_socket);

    return 0;
}