//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 100
#define BUFFER_SIZE 1024

struct client_info {
    int sock;
    char ip_addr[INET_ADDRSTRLEN];
    char username[64];
};

int main(void) {
    int listen_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    struct client_info clients[MAX_CLIENT_CONNECTIONS];
    int num_clients = 0;

    // Create the listening socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind the listening socket to the address and port
    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(listen_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections...\n");

    while (1) {
        // Accept an incoming connection
        if ((client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("accept failed");
            continue;
        }

        // Print the client's IP address and port
        printf("Connection accepted from %s:%d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create a new client structure and store it in the clients array
        struct client_info *new_client = calloc(1, sizeof(*new_client));
        new_client->sock = client_fd;
        inet_ntop(AF_INET, &client_addr.sin_addr, new_client->ip_addr, sizeof(new_client->ip_addr));

        // Add the new client to the array of clients
        if (num_clients >= MAX_CLIENT_CONNECTIONS) {
            fprintf(stderr, "Too many clients connected (%d)\n", num_clients);
            close(client_fd);
            continue;
        }
        clients[num_clients++] = *new_client;

        // Handle the client's requests
        while (1) {
            // Read data from the client
            recv(client_fd, buffer, BUFFER_SIZE, 0);

            // Print the received data
            printf("Received message from client: %s\n", buffer);

            // Send a response back to the client
            char *message = "Hello, client!";
            send(client_fd, message, strlen(message), 0);
        }

        // Close the client's connection
        close(client_fd);
    }

    return 0;
}