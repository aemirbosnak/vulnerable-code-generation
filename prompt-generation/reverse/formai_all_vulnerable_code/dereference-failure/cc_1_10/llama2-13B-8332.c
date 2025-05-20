//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_LENGTH 1024
#define MAX_MESSAGE_LENGTH 512

struct client {
    int sock;
    char name[MAX_CLIENT_LENGTH];
};

void handle_connection(int sock);
void handle_message(int sock, char *message);
void handle_disconnect(int sock);

int main(int argc, char *argv[]) {
    int server_sock;
    struct sockaddr_in server_addr;
    socklen_t client_len = sizeof(struct sockaddr_in);

    // Create the server socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Bind the server socket to the address and port
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Main loop for handling incoming connections
    while (1) {
        // Accept an incoming connection
        int client_sock = accept(server_sock, (struct sockaddr *)NULL, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Create a new client struct to store the client's information
        struct client *new_client = malloc(sizeof(struct client));
        new_client->sock = client_sock;

        // Start the recursive function to handle the client's messages
        handle_connection(client_sock);

        // Free the client struct when the client disconnects
        free(new_client);
    }

    return 0;
}

void handle_connection(int sock) {
    // Get the client's name
    char name[MAX_CLIENT_LENGTH];
    recvfrom(sock, name, MAX_CLIENT_LENGTH, 0, NULL, NULL);

    // Print the client's name and welcome message
    printf("Client connected: %s\n", name);

    // Start the recursive function to handle the client's messages
    handle_message(sock, name);

    // Clean up and close the client socket when the client disconnects
    handle_disconnect(sock);
}

void handle_message(int sock, char *name) {
    // Get the message from the client
    char message[MAX_MESSAGE_LENGTH];
    recvfrom(sock, message, MAX_MESSAGE_LENGTH, 0, NULL, NULL);

    // Print the message and the client's name
    printf("Message from %s: %s\n", name, message);

    // Start the recursive function to handle the client's next message
    handle_message(sock, name);
}

void handle_disconnect(int sock) {
    // Print a message when the client disconnects
    printf("Client disconnected\n");

    // Close the client socket
    close(sock);
}