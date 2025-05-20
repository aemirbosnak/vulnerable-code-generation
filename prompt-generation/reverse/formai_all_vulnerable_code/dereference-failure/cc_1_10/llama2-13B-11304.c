//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

struct client {
    int sock;
    char name[50];
};

int main(int argc, char *argv[]) {
    int listen_sock, client_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char buffer[BUFFER_SIZE];
    int num_clients = 0;

    // Create the listening socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    // Bind the listening socket to the address and port
    if (bind(listen_sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Listening for incoming connections...\n");

    while (1) {
        // Accept an incoming connection
        client_sock = accept(listen_sock, (struct sockaddr *)&client, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            exit(1);
        }

        // Print the client's address and port
        printf("New client connection from %s%d\n",
               inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // Create a new client structure and add it to the list
        struct client *new_client = malloc(sizeof(struct client));
        new_client->sock = client_sock;
        strcpy(new_client->name, "Unknown");
        num_clients++;
        printf("Total clients: %d\n", num_clients);

        // Handle incoming messages from clients
        while (1) {
            recv(client_sock, buffer, BUFFER_SIZE, 0);
            if (strlen(buffer) > 0) {
                printf("Received message from %s: %s\n", new_client->name, buffer);
                // Send the message to all other clients
                for (int i = 0; i < num_clients; i++) {
                    if (i != new_client->sock) {
                        send(i, buffer, strlen(buffer), 0);
                    }
                }
            }
        }
    }

    return 0;
}