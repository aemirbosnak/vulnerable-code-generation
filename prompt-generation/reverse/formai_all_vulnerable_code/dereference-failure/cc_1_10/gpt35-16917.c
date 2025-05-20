//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define DEFAULT_PORT 8080

int main(int argc, char **argv) {
    int socket_fd, new_socket_fd, port;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Check if custom port is provided
    if (argc > 1) {
        port = atoi(argv[1]);
    } else {
        port = DEFAULT_PORT;
    }

    // Create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Failed to create socket!\n");
        return -1;
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Failed to set socket options!\n");
        return -1;
    }

    // Prepare server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind socket to address
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to bind socket to address!\n");
        return -1;
    }

    // Listen for connections
    if (listen(socket_fd, 3) < 0) {
        printf("Failed to listen for connections!\n");
        return -1;
    }

    printf("Server is listening on port %d...\n", port);

    // Accept connections and handle them
    int client_addr_len = sizeof(client_addr);
    while ((new_socket_fd = accept(socket_fd, (struct sockaddr *)&client_addr, (socklen_t*)&client_addr_len))) {
        printf("New client connected!\n");

        // Receive data from client
        int bytes_received = read(new_socket_fd, buffer, BUFFER_SIZE);
        printf("Received %d bytes from client: %s\n", bytes_received, buffer);

        // Process the received message
        // ...

        // Send response to client
        char *response = "Hello from server!";
        write(new_socket_fd, response, strlen(response));
        printf("Response sent to client!\n");

        // Close connection with client
        close(new_socket_fd);
    }

    return 0;
}