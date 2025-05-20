//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Structure to represent a connected client
typedef struct {
    int sock;
    char name[50];
} client_t;

// Function to handle incoming client connections
void handle_client_connection(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Read name from client
    printf("Welcome, client!\n");
    printf("Please enter your name: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character

    // Store name in client structure
    client_t *client = malloc(sizeof(client_t));
    client->sock = sock;
    strcpy(client->name, buffer);

    // Handle client requests
    while (1) {
        printf("Client %s> ", client->name);
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character

        // Execute request
        if (strcmp(buffer, "quit") == 0) {
            break;
        } else if (strcmp(buffer, "say_hello") == 0) {
            printf("Hello, %s!\n", client->name);
        } else {
            printf("Invalid request, try again.\n");
        }
    }

    // Close client connection
    close(sock);
    free(client);
}

// Function to handle server listen and accept
void handle_server_listen(int sock) {
    socklen_t client_len = sizeof(int);
    int client_sock;

    // Listen for incoming connections
    while (1) {
        listen(sock, 3); // Listen for 3 incoming connections

        // Accept incoming connection
        client_sock = accept(sock, NULL, &client_len);
        handle_client_connection(client_sock);
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(1234)
    };

    // Bind server address and port
    bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for incoming connections
    listen(sock, 3);

    // Spin up server listen loop
    handle_server_listen(sock);

    return 0;
}