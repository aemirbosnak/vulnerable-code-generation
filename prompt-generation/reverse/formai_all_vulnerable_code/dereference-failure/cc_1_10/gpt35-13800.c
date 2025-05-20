//FormAI DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

#define PORT 8080

void recursive_echo(int client_fd);

int main()
{
    // Create socket file descriptor
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port and an IP address
    struct sockaddr_in address = {0};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) == -1)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started! Listening on port %d...\n", PORT);

    while (1)
    {
        // Accept incoming connection
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0)
        {
            perror("Failed to accept connection");
            continue;
        }

        // Handle the client connection recursively
        recursive_echo(client_fd);
    }
}

void recursive_echo(int client_fd)
{
    // Allocate buffer and read message from the client
    char *buffer = (char *)malloc(sizeof(char) * 1024);
    memset(buffer, '\0', 1024);
    int read_size = read(client_fd, buffer, 1024);
    if (read_size <= 0)
    {
        if (read_size == 0)
        {
            printf("Client disconnected.\n");
        }
        else
        {
            perror("Failed to read from client");
        }
        free(buffer);
        close(client_fd);
        return;
    }

    // Print received message and send it back to the client
    printf("Received message: %s", buffer);
    write(client_fd, buffer, strlen(buffer));

    // Call this function recursively to handle next message from the client
    recursive_echo(client_fd);

    free(buffer);
}