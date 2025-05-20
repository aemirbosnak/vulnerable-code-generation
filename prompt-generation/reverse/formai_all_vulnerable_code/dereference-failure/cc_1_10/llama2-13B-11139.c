//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct user {
    char *name;
    char *message;
};

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    int num_clients = 0;
    struct user users[10];

    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the server socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_fd, 10) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client, &client_len)) < 0) {
            perror("accept failed");
            exit(1);
        }

        // Add the client to the list of connected clients
        num_clients++;
        users[num_clients - 1].name = malloc(1024);
        users[num_clients - 1].message = malloc(1024);

        // Read data from the client
        read(client_fd, users[num_clients - 1].message, 1024);

        // Print the message from the client
        printf("Client %d: %s\n", num_clients, users[num_clients - 1].message);

        // Allow the client to send another message
        printf("Server> ");
        fgets(users[num_clients - 1].message, 1024, stdin);

        // Send the message back to the client
        send(client_fd, users[num_clients - 1].message, strlen(users[num_clients - 1].message), 0);

        // Free memory for the client's message
        free(users[num_clients - 1].message);

        // Close the client socket
        close(client_fd);
    }

    return 0;
}