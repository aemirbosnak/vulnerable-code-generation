//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 10
#define MAX_MESSAGE_LENGTH 256

struct client_info {
    int sock;
    char username[50];
};

int main(void) {
    int listen_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[256];

    // Create a listening socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(1234);

    // Bind the listening socket to the address and port
    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(listen_fd, MAX_CLIENT_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept an incoming connection
        if ((client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("accept failed");
            continue;
        }

        // Create a new client structure
        struct client_info *client = malloc(sizeof(struct client_info));
        client->sock = client_fd;

        // Read the client's username
        printf("Welcome, please enter your username: ");
        fgets(buffer, sizeof(buffer), stdin);
        client->username[0] = buffer[0];
        client->username[1] = '\0';

        // Handle client messages
        while (1) {
            printf("> ");
            fgets(buffer, sizeof(buffer), stdin);
            if (buffer[0] == '\0') {
                break;
            }
            // Send the message to all connected clients
            sendto(client->sock, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        }

        // Close the client socket and free the client structure
        close(client->sock);
        free(client);
    }

    return 0;
}