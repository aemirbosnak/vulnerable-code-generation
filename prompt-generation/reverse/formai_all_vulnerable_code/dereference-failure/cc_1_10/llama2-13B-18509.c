//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 5
#define MAX_MESSAGE_LENGTH 1024

struct client_data {
    int sock;
    char username[50];
};

int main(void) {
    int listen_fd, client_fd;
    socklen_t client_len = sizeof(struct client_data);
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];

    // Create the listen socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(1234);

    // Bind the listen socket to the address and port
    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_fd, MAX_CLIENT_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(1);
    }

    // Accept an incoming connection
    client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd == -1) {
        perror("accept failed");
        exit(1);
    }

    // Create a new client data structure
    struct client_data *client_data = malloc(sizeof(struct client_data));
    client_data->sock = client_fd;

    // Read the client's username
    read(client_fd, client_data->username, 50);

    // Loop indefinitely to handle incoming messages
    while (1) {
        // Read a message from the client
        read(client_fd, buffer, 1024);

        // Send the message back to the client
        send(client_fd, buffer, strlen(buffer), 0);

        // Check if the client has disconnected
        if (client_data->sock == -1) {
            break;
        }
    }

    // Close the client socket
    close(client_fd);

    // Free the client data structure
    free(client_data);

    // Close the listen socket
    close(listen_fd);

    return 0;
}