//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_MESSAGE_LEN 256

struct client {
    int sock;
    char name[50];
    char message[256];
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Create a server address
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind the server address to the socket
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Create a new client structure
        struct client *client = malloc(sizeof(struct client));
        client->sock = client_sock;
        client->name[0] = '\0';
        client->message[0] = '\0';

        // Read the client's name and message
        read(client_sock, client->name, sizeof(client->name) - 1);
        read(client_sock, client->message, sizeof(client->message) - 1);

        // Print the client's name and message
        printf("Client %s says: %s\n", client->name, client->message);

        // Broadcast the client's message to all connected clients
        sendto(sock, client->message, strlen(client->message), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

        // Free the client structure
        free(client);
    }

    return 0;
}