//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888
#define MAX_CLIENTS 10
#define MAX_MESSAGE_LENGTH 256

struct client {
    int sock;
    char name[50];
};

int main(int argc, char *argv[]) {
    int server_sock;
    struct client clients[MAX_CLIENTS];
    int client_count = 0;

    // Create the server socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server address
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind the server socket to the address and port
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Retro Chat Room Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        int client_sock = accept(server_sock, NULL, NULL);

        // Add the client to the list of connected clients
        struct client *client = malloc(sizeof(struct client));
        client->sock = client_sock;
        strcpy(client->name, "Anonymous");
        client_count++;
        clients[client_count - 1] = *client;

        printf("New client connected: %s\n", client->name);

        while (1) {
            // Read a message from the client
            char message[MAX_MESSAGE_LENGTH];
            read(client_sock, message, MAX_MESSAGE_LENGTH);

            // Broadcast the message to all connected clients
            int i;
            for (i = 0; i < client_count; i++) {
                if (clients[i].sock != client_sock) {
                    write(clients[i].sock, message, strlen(message));
                }
            }
        }
    }

    return 0;
}