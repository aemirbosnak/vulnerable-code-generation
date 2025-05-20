//FormAI DATASET v1.0 Category: Chat server ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10   // Maximum number of clients that can connect to server
#define BUFFER_SIZE 1024 // Maximum buffer size

void handle_client(int client_socket);

int main(int argc, char *argv[])
{
    int server_socket, client_socket, opt = 1;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    // Initialize server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
    {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Initialize server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(atoi(argv[1])); // Port number from command line argument

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    if (listen(server_socket, MAX_CLIENTS) < 0)
    {
        perror("Error listening for clients");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %s...\n", argv[1]);

    while (1)
    {
        // Accept incoming client connections
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);

        if (client_socket < 0)
        {
            perror("Error accepting client");
            exit(EXIT_FAILURE);
        }

        printf("New client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Handle client in separate thread
        handle_client(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}

/**
 * Handle client requests
 */
void handle_client(int client_socket)
{
    char buffer[BUFFER_SIZE];
    int ret;

    while (1)
    {
        // Receive message from client
        ret = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (ret == 0)
        {
            // Client disconnected
            printf("Client disconnected\n");
            close(client_socket);
            break;
        }

        if (ret < 0)
        {
            // Receive error
            perror("Error receiving message");
            exit(EXIT_FAILURE);
        }

        // Add null terminator to received message
        buffer[ret] = '\0';

        // Echo message back to client
        printf("Received message: %s\n", buffer);
        ret = send(client_socket, buffer, strlen(buffer), 0);

        if (ret < 0)
        {
            // Send error
            perror("Error sending message");
            exit(EXIT_FAILURE);
        }
    }
}