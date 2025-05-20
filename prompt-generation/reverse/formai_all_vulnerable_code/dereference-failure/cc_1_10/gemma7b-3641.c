//Gemma-7B DATASET v1.0 Category: Socket programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

// Define the server port number
#define SERVER_PORT 8080

// Define the client port number
#define CLIENT_PORT 8081

// Define the maximum number of clients that can connect
#define MAX_CLIENTS 10

// Define the client structure
typedef struct Client {
    int socketfd;
    char name[20];
    struct Client* next;
} Client;

// Function to add a client to the client list
void addClient(Client** head, char* name) {
    Client* newClient = (Client*)malloc(sizeof(Client));
    newClient->socketfd = -1;
    strcpy(newClient->name, name);
    newClient->next = NULL;

    if (*head == NULL) {
        *head = newClient;
    } else {
        (*head)->next = newClient;
    }
}

// Function to remove a client from the client list
void removeClient(Client** head, char* name) {
    Client* previousClient = NULL;
    Client* currentClient = *head;

    while (currentClient) {
        if (strcmp(currentClient->name, name) == 0) {
            if (previousClient) {
                previousClient->next = currentClient->next;
            } else {
                *head = currentClient->next;
            }
            free(currentClient);
            return;
        }

        previousClient = currentClient;
        currentClient = currentClient->next;
    }

    return;
}

// Function to handle client connections
void handleClient(Client* client) {
    char message[1024];

    // Receive a message from the client
    recv(client->socketfd, message, 1024, 0);

    // Print the message to the server console
    printf("Client: %s, Message: %s\n", client->name, message);

    // Send a message back to the client
    sprintf(message, "Server: Hello, %s!", client->name);
    send(client->socketfd, message, strlen(message), 0);
}

int main() {
    // Create a socket for the server
    int serverSocketfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));

    // Bind the socket to the server port
    bind(serverSocketfd, NULL, 0);

    // Listen for client connections
    Client* clients = NULL;
    while (1) {
        // Accept a client connection
        int clientSocketfd = accept(serverSocketfd, NULL, NULL);

        // Add the client to the client list
        addClient(&clients, "Client");

        // Handle the client connection
        handleClient(clients);

        // Remove the client from the client list
        removeClient(&clients, "Client");

        // Close the client socket
        close(clientSocketfd);
    }

    return 0;
}