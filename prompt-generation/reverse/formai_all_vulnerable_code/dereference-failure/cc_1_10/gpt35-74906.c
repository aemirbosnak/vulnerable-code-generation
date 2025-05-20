//FormAI DATASET v1.0 Category: Networking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CONNECTIONS 10
#define BUFF_SIZE 1024

int main(int argc, char const *argv[])
{
    // Check for input arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(atoi(argv[1]));
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Error binding socket to port");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0)
    {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Sherlock Holmes: The Adventure of the Networking Program\n");
    printf("Listening for connections on port %d...\n", atoi(argv[1]));

    while (1)
    {
        // Accept incoming connection
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0)
        {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        // Read message from client
        char buffer[BUFF_SIZE];
        int bytes_read = read(client_socket, buffer, BUFF_SIZE);
        if (bytes_read < 0)
        {
            perror("Error reading from client socket");
            exit(EXIT_FAILURE);
        }

        printf("Sherlock Holmes: I have received a message. It reads: %s\n", buffer);
        printf("Sherlock Holmes: Let me think...\n");

        // Process message
        char response[BUFF_SIZE];
        snprintf(response, BUFF_SIZE, "Sherlock Holmes: I have solved the mystery, the message contained %d characters.\n", bytes_read);
        printf("%s", response);

        // Send response to client
        int bytes_sent = write(client_socket, response, strlen(response));
        if (bytes_sent < 0)
        {
            perror("Error writing to client socket");
            exit(EXIT_FAILURE);
        }

        printf("Sherlock Holmes: The case is closed.\n");

        close(client_socket);
    }

    close(server_socket);
    exit(EXIT_SUCCESS);
}