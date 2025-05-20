//Gemma-7B DATASET v1.0 Category: Chat server ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_CLIENTS 10

// Define the server structure
typedef struct Client {
    int sockfd;
    char name[256];
    struct Client* next;
} Client;

Client* head = NULL;

// Function to add a client to the server
void addClient(int sockfd, char* name) {
    Client* newClient = (Client*)malloc(sizeof(Client));
    newClient->sockfd = sockfd;
    strcpy(newClient->name, name);
    newClient->next = head;
    head = newClient;
}

// Function to remove a client from the server
void removeClient(int sockfd) {
    Client* prevClient = NULL;
    Client* currentClient = head;

    while (currentClient) {
        if (currentClient->sockfd == sockfd) {
            if (prevClient) {
                prevClient->next = currentClient->next;
            } else {
                head = currentClient->next;
            }
            free(currentClient);
            return;
        }
        prevClient = currentClient;
        currentClient = currentClient->next;
    }
}

int main() {
    int sockfd, newsockfd, clientCount = 0, listenfd;
    char buffer[1024];

    // Create a TCP socket
    listenfd = socket(AF_INET, SOCK_STREAM, htons(8080));

    // Bind the socket to a port
    bind(listenfd, NULL, 0);

    // Listen for clients
    while (1) {
        // Accept a client connection
        newsockfd = accept(listenfd, NULL, NULL);

        // Add the client to the server
        addClient(newsockfd, "Client");

        // Send a welcome message to the client
        write(newsockfd, "Welcome to the C Chat server!", 32);

        // Receive a message from the client
        read(newsockfd, buffer, 1024);

        // Broadcast the message to the other clients
        for (Client* currentClient = head; currentClient; currentClient) {
            if (currentClient->sockfd != newsockfd) {
                write(currentClient->sockfd, buffer, 1024);
            }
        }

        // Remove the client from the server
        removeClient(newsockfd);

        // Close the client socket
        close(newsockfd);

        // Increment the client count
        clientCount++;

        // Print the client count
        printf("Number of clients: %d\n", clientCount);
    }

    return 0;
}