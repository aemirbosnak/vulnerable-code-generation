//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_NAME_LEN 20
#define MAX_MESSAGE_LEN 100

// Structure to hold client information
typedef struct {
    char name[MAX_CLIENT_NAME_LEN];
    int sock;
} client_t;

// Function to handle client connections
void handle_client(int sock) {
    char message[MAX_MESSAGE_LEN];
    printf("New client connected! Name: %s\n", message);

    // Read message from client
    read(sock, message, MAX_MESSAGE_LEN);
    printf("Received message: %s\n", message);

    // Echo message back to client
    send(sock, message, strlen(message), 0);
}

// Function to handle server
void handle_server(int sock) {
    char message[MAX_MESSAGE_LEN];
    printf("Server listening...\n");

    // Accept incoming client connections
    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        handle_client(client_sock);
        close(client_sock);
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up server address and port
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind server address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    // Listen for incoming client connections
    if (listen(sock, 3) < 0) {
        perror("Listen failed");
        exit(1);
    }

    // Start server loop
    handle_server(sock);

    return 0;
}