//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: enthusiastic
// Let's start by including the necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define some necessary constants
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

// Define a helper function that sends data to the client
void send_data_to_client(int client_fd, char* data)
{
    // Send data to the client
    if (send(client_fd, data, strlen(data), 0) == -1) {
        printf("Error sending data to client: %s\n", strerror(errno));
        return;
    }
}

int main()
{
    // Create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return -1;
    }

    // Define server address and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);

    // Bind server to the specified address and port
    if (bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        printf("Error binding to port %d: %s\n", SERVER_PORT, strerror(errno));
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 10) == -1) {
        printf("Error listening for connections: %s\n", strerror(errno));
        return -1;
    }

    // Accept incoming connections and handle them
    while (1) {
        // Accept incoming connection
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_fd = accept(server_fd, (struct sockaddr*)&client_address, &client_address_size);
        if (client_fd == -1) {
            printf("Error accepting incoming connections: %s\n", strerror(errno));
            continue;
        }

        // Read data from the client
        char buffer[BUFFER_SIZE];
        ssize_t bytes_read = recv(client_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_read == -1) {
            printf("Error reading data from client: %s\n", strerror(errno));
            continue;
        }
        buffer[bytes_read] = '\0';

        // Forward data to the server
        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd == -1) {
            printf("Error creating socket to forward request: %s\n", strerror(errno));
            continue;
        }

        // Connect to the server
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(80);
        if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
            printf("Error parsing server address: %s\n", strerror(errno));
            continue;
        }
        if (connect(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
            printf("Error connecting to server: %s\n", strerror(errno));
            continue;
        }

        // Send data to the server
        if (send(server_fd, buffer, strlen(buffer), 0) == -1) {
            printf("Error sending data to server: %s\n", strerror(errno));
            continue;
        }

        // Read data from the server
        char server_response_buffer[BUFFER_SIZE];
        ssize_t server_response_bytes_read = recv(server_fd, server_response_buffer, BUFFER_SIZE, 0);
        if (server_response_bytes_read == -1) {
            printf("Error reading data from server: %s\n", strerror(errno));
            continue;
        }

        // Forward data back to the client
        send_data_to_client(client_fd, server_response_buffer);

        // Close the client and server connections
        close(client_fd);
        close(server_fd);
    }

    // Close the server socket
    close(server_fd);

    return 0;
}