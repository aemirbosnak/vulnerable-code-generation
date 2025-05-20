//FormAI DATASET v1.0 Category: Client Server Application ; Style: single-threaded
// C Client Server Application Program
// Single-Threaded Style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void handle_client(int client_socket);

int main(int argc, char *argv[])
{
    int server_socket, client_socket, port_number, bind_status;
    socklen_t client_address_length;
    struct sockaddr_in server_address, client_address;

    // Verify the correct number of arguments were provided
    if (argc != 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a TCP socket to use as the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address struct
    port_number = atoi(argv[1]);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_number);

    // Bind the socket to the specified port number
    bind_status = bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (bind_status == -1)
    {
        perror("Failed to bind server socket to specified port");
        exit(EXIT_FAILURE);
    }

    // Set the socket to listen for incoming connections
    if (listen(server_socket, 10) == -1)
    {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections on port %d\n", port_number);

    // Handle incoming connections
    while (1)
    {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket == -1)
        {
            perror("Failed to accept incoming connection");
            continue;
        }

        printf("Accepted incoming connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Handle this client's requests
        handle_client(client_socket);
    }

    return 0;
}

void handle_client(int client_socket)
{
    int receive_status, send_status;
    char buffer[BUFFER_SIZE];

    // Receive data from the client
    receive_status = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (receive_status == -1)
    {
        perror("Failed to receive data from client");
        close(client_socket);
        return;
    }

    printf("Received data from client: %s\n", buffer);

    // Manipulate the data in some way
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (buffer[i] == 'a')
        {
            buffer[i] = 'A';
        }
        else if (buffer[i] == 'b')
        {
            buffer[i] = 'B';
        }
    }

    // Send the manipulated data back to the client
    send_status = send(client_socket, buffer, strlen(buffer), 0);
    if (send_status == -1)
    {
        perror("Failed to send data back to client");
        close(client_socket);
        return;
    }

    printf("Sent data back to client: %s\n", buffer);

    // Close the connection with this client
    close(client_socket);
}