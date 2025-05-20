//Gemma-7B DATASET v1.0 Category: Chat server ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

// Define the maximum number of clients that the server can handle
#define MAX_CLIENTS 10

// Define the client structure
typedef struct Client {
    int sockfd;
    char name[256];
    struct Client* next;
} Client;

// Global variable to store the head of the client list
Client* head = NULL;

// Function to add a client to the client list
void addClient(int sockfd, char* name) {
    Client* newClient = (Client*)malloc(sizeof(Client));
    newClient->sockfd = sockfd;
    strcpy(newClient->name, name);
    newClient->next = head;
    head = newClient;
}

// Function to remove a client from the client list
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
    int sockfd, newsockfd, clientCount = 0, port = SERVER_PORT;
    char buffer[BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Listen for clients
    while (1) {
        // Accept a client connection
        newsockfd = accept(sockfd, NULL, NULL);
        if (newsockfd < 0) {
            perror("Error accepting client connection");
            continue;
        }

        // Add the client to the client list
        addClient(newsockfd, "Client");

        // Send a welcome message to the client
        sprintf(buffer, "Welcome to the C Chat server, %s!", "Client");
        write(newsockfd, buffer, strlen(buffer));

        // Receive a message from the client
        read(newsockfd, buffer, BUFFER_SIZE);
        printf("Client: %s: %s\n", "Client", buffer);

        // Remove the client from the client list
        removeClient(newsockfd);

        // Close the client connection
        close(newsockfd);
        clientCount++;
    }

    return 0;
}