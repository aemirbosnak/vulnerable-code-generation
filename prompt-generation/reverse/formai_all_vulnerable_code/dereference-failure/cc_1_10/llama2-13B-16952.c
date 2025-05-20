//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: complete
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

int main(void) {
    int listen_sock, client_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char message[MAX_MESSAGE_LENGTH];
    int num_clients = 0;

    // Create the listening socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the listening socket to the address and port
    if (bind(listen_sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections...\n");

    while (1) {
        // Accept an incoming connection
        if ((client_sock = accept(listen_sock, (struct sockaddr *)&client, &client_len)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Add the new client to the list of connected clients
        struct client *new_client = (struct client *)malloc(sizeof(struct client));
        new_client->sock = client_sock;
        strcpy(new_client->name, "Unknown");
        num_clients++;

        // Handle messages from the new client
        while (1) {
            // Receive a message from the client
            recv(client_sock, message, MAX_MESSAGE_LENGTH, 0);

            // Print the message to the console
            printf("Received message from %s: %s\n", new_client->name, message);

            // Send a response back to the client
            char *response = "You said:";
            send(client_sock, response, strlen(response), 0);
        }

        // Close the client socket when the client disconnects
        close(client_sock);
    }

    return 0;
}