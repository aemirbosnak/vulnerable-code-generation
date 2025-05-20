//LLAMA2-13B DATASET v1.0 Category: RAM usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/mman.h>

#define MAX_CLIENTS 1024
#define BUFFER_SIZE 1024

struct client_data {
    int sock;
    char *buffer;
    size_t buffer_size;
};

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind the server socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", server_addr.sin_port);

    while (1) {
        // Accept an incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("accept failed");
            exit(1);
        }

        // Create a new client data structure
        struct client_data *client_data = malloc(sizeof(struct client_data));
        client_data->sock = client_fd;
        client_data->buffer = malloc(BUFFER_SIZE);
        client_data->buffer_size = BUFFER_SIZE;

        // Start the client loop
        while (1) {
            // Read data from the client
            read(client_data->sock, client_data->buffer, BUFFER_SIZE);

            // Print the received data
            printf("Received data: %s\n", client_data->buffer);

            // Calculate the RAM usage of the client
            char *ptr = client_data->buffer;
            size_t len = strlen(ptr);
            char *end = ptr + len;
            size_t ram_usage = (end - ptr) * sizeof(char);

            // Send the RAM usage back to the client
            char *ram_usage_str = malloc(sizeof(char) * 10);
            sprintf(ram_usage_str, "%zu", ram_usage);
            send(client_data->sock, ram_usage_str, strlen(ram_usage_str), 0);

            // Free the RAM usage string
            free(ram_usage_str);
        }

        // Free the client data structure
        free(client_data);
    }

    return 0;
}