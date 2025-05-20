//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 5
#define MAX_MESSAGE_LENGTH 100

struct client {
    char *name;
    int sock;
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", server_addr.sin_port);

    // Accept and handle incoming connections
    while (1) {
        struct client *new_client;
        new_client = (struct client *)malloc(sizeof(struct client));
        new_client->name = malloc(MAX_MESSAGE_LENGTH);
        new_client->sock = accept(sock, NULL, NULL);

        // Greet the new client
        printf("New client connected! Name: %s\n", new_client->name);

        // Read and handle messages from the client
        while (1) {
            char message[MAX_MESSAGE_LENGTH];
            if (read(new_client->sock, message, MAX_MESSAGE_LENGTH) < 0) {
                perror("read failed");
                break;
            }

            // Handle the message
            printf("Client %s said: %s\n", new_client->name, message);

            // Send a response back to the client
            char *response = "Thank you, dear client!";
            send(new_client->sock, response, strlen(response), 0);
        }

        // Clean up and free memory
        free(new_client->name);
        free(new_client);
    }

    // Close the socket
    close(sock);

    return 0;
}