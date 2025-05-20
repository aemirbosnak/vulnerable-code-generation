//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10

struct client_info {
    int client_fd;
    struct sockaddr_in client_addr;
};

void *handle_client(void *arg) {
    struct client_info *client = (struct client_info *)arg;

    char buffer[1024];
    int bytes_received;

    while ((bytes_received = recv(client->client_fd, buffer, sizeof(buffer), 0)) > 0) {
        printf("Received %d bytes from client %s:%d\n", bytes_received, inet_ntoa(client->client_addr.sin_addr), ntohs(client->client_addr.sin_port));

        // Process the received data here

        // Send a response back to the client
        send(client->client_fd, buffer, bytes_received, 0);
    }

    if (bytes_received == 0) {
        printf("Client %s:%d disconnected\n", inet_ntoa(client->client_addr.sin_addr), ntohs(client->client_addr.sin_port));
    } else {
        perror("Error receiving data from client");
    }

    close(client->client_fd);
    free(client);

    return NULL;
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    // Create a TCP socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    // Set the server address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) == -1) {
        perror("Error listening on socket");
        return EXIT_FAILURE;
    }

    printf("Server listening on port %d\n", PORT);

    // Accept incoming connections and create a new thread for each client
    while (1) {
        client_addr_len = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("Error accepting client connection");
            continue;
        }

        printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create a new thread to handle the client
        pthread_t thread;
        struct client_info *client_info = malloc(sizeof(struct client_info));
        client_info->client_fd = client_fd;
        client_info->client_addr = client_addr;
        pthread_create(&thread, NULL, handle_client, (void *)client_info);
    }

    // Close the server socket
    close(server_fd);

    return EXIT_SUCCESS;
}