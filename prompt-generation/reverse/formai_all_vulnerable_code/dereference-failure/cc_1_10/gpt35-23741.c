//FormAI DATASET v1.0 Category: Networking ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    int server_socket, client_socket, port_number;
    struct sockaddr_in server_address, client_address;
    char message[1000];

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Failed to create socket.\n");
        exit(1);
    }

    // Set server address values
    port_number = atoi(argv[1]);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port_number);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Failed to bind socket.\n");
        exit(1);
    }

    // Start listening for incoming connections
    if (listen(server_socket, 5) < 0) {
        printf("Failed to listen for incoming connections.\n");
        exit(1);
    }

    // Accept incoming connections
    int client_address_length = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
    if (client_socket < 0) {
        printf("Failed to accept incoming connection.\n");
        exit(1);
    }

    // Receive message from client and print it on the server console
    memset(message, '\0', sizeof(message));
    read(client_socket, message, sizeof(message));
    printf("Received message: %s\n", message);

    // Send a response to the client
    char response[1000] = "Hello from the server!";
    write(client_socket, response, strlen(response));

    // Close the client and server sockets
    close(client_socket);
    close(server_socket);

    return 0;
}