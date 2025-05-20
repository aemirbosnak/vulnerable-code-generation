//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to hold client information
typedef struct {
    int sock;
    char name[50];
} client_t;

// Function to handle client connections
void handle_client(int sock) {
    char buffer[256];
    printf("Client connected! Name: ");
    fgets(buffer, 256, stdin);
    printf("Welcome, %s!\n", buffer);

    // Send a message back to the client
    send(sock, "Hello, client!\n", 13, 0);

    // Wait for the client to send another message
    recv(sock, buffer, 256, 0);
    printf("Client said: %s\n", buffer);

    // Close the client connection
    close(sock);
}

// Function to handle server initialization
void init_server(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(sock, 3);

    printf("Server listening on port %d...\n", PORT);
}

// Function to handle server loop
void handle_server(void) {
    int sock = accept(NULL, NULL, NULL);
    client_t *client = malloc(sizeof(client_t));
    client->sock = sock;

    handle_client(sock);

    free(client);
}

int main(void) {
    init_server();

    while (1) {
        handle_server();
    }

    return 0;
}