//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

// Constants
#define PORT 8080
#define MAX_BUFFER_SIZE 1024

// Function prototypes
void error(char *message);

// Main function
int main()
{
    int socket_fd, new_socket, read_value;
    struct sockaddr_in server_address, client_address;
    socklen_t client_size;
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        error("Socket creation failed");
    }

    // Initializing server_address struct
    memset(&server_address, 0, sizeof(server_address));

    // Filling server_address struct
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the specified address and port
    if (bind(socket_fd, (struct sockaddr *)&server_address,
             sizeof(server_address)) < 0)
    {
        error("Socket binding failed");
    }

    // Listen for incoming connections
    if (listen(socket_fd, 3) < 0)
    {
        error("Listen failed");
    }

    // Accept incoming connections
    while (1)
    {
        // Accept incoming connection
        client_size = sizeof(client_address);
        if ((new_socket = accept(socket_fd, (struct sockaddr *)&client_address,
                                 &client_size)) < 0)
        {
            error("Accept failed");
        }

        // Read data from the client
        read_value = read(new_socket, buffer, MAX_BUFFER_SIZE);
        printf("Client: %s\n", buffer);

        // Send response back to the client
        const char *response = "Hello from the server!\n";
        int write_value = write(new_socket, response, strlen(response));

        // Close the connection
        close(new_socket);
    }

    return 0;
}

// Function to print error and exit
void error(char *message)
{
    fprintf(stderr, "Error: %s. %s\n", message, strerror(errno));
    exit(EXIT_FAILURE);
}