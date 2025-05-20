//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define MAX_MESSAGE_LENGTH 1024

struct client {
    int sock;
    char name[50];
};

int main(int argc, char *argv[]) {
    int listen_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[1024];
    int num_clients = 0;

    // Create the listen socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("Error creating listen socket");
        exit(1);
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the listen socket to the address and port
    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding listen socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 3) < 0) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("Error accepting incoming connection");
            exit(1);
        }

        // Add the new client to the list of connected clients
        struct client *new_client = (struct client *)malloc(sizeof(struct client));
        new_client->sock = client_sock;
        strcpy(new_client->name, "Unknown");
        num_clients++;

        // Handle incoming messages from clients
        while (1) {
            recv(client_sock, buffer, 1024, 0);
            if (strcmp(buffer, "QUIT") == 0) {
                break;
            }
            printf("Server received message from client: %s\n", buffer);

            // Broadcast the message to all other clients
            for (int i = 0; i < num_clients; i++) {
                if (i != num_clients - 1) {
                    sendto(listen_sock, buffer, strlen(buffer), 0,
                           (struct sockaddr *)&client_addr, client_len);
                }
            }
        }

        // Close the client socket and free the client struct
        close(client_sock);
        free(new_client);
    }

    return 0;
}