//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_SIZE 1024

// Server function
void server(int port) {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept connections
    int client_sockets[MAX_CLIENTS];
    int num_clients = 0;
    while (1) {
        // Accept a connection
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Add the client socket to the list of clients
        client_sockets[num_clients++] = client_socket;

        // Send a welcome message to the client
        const char *welcome_message = "Welcome to the server!\n";
        if (send(client_socket, welcome_message, strlen(welcome_message), 0) == -1) {
            perror("send");
            close(client_socket);
            continue;
        }
    }

    // Close the server socket
    close(server_socket);
}

// Client function
void client(char *ip_address, int port) {
    // Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip_address);
    server_address.sin_port = htons(port);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send a message to the server
    const char *message = "Hello from the client!\n";
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("send");
        close(client_socket);
        exit(1);
    }

    // Receive a message from the server
    char buffer[MAX_MESSAGE_SIZE];
    int num_bytes_received = recv(client_socket, buffer, MAX_MESSAGE_SIZE, 0);
    if (num_bytes_received == -1) {
        perror("recv");
        close(client_socket);
        exit(1);
    }

    // Print the message from the server
    printf("Message from the server: %s", buffer);

    // Close the client socket
    close(client_socket);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip_address> <port>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);

    if (strcmp(argv[0], "server") == 0) {
        server(port);
    } else if (strcmp(argv[0], "client") == 0) {
        client(ip_address, port);
    } else {
        fprintf(stderr, "Invalid command: %s\n", argv[0]);
        exit(1);
    }

    return 0;
}