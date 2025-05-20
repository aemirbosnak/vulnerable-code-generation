//Gemma-7B DATASET v1.0 Category: Chat server ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

typedef struct Client {
    char name[20];
    int sockfd;
    struct Client* next;
} Client;

Client* head = NULL;

void addClient(char* name, int sockfd) {
    Client* newClient = malloc(sizeof(Client));
    strcpy(newClient->name, name);
    newClient->sockfd = sockfd;
    newClient->next = head;
    head = newClient;
}

void removeClient(int sockfd) {
    Client* currentClient = head;
    Client* previousClient = NULL;

    while (currentClient) {
        if (currentClient->sockfd == sockfd) {
            if (previousClient) {
                previousClient->next = currentClient->next;
            } else {
                head = currentClient->next;
            }
            free(currentClient);
            return;
        }

        previousClient = currentClient;
        currentClient = currentClient->next;
    }
}

int main() {
    int sockfd, newsockfd, clientCount = 0, port = 8080;
    struct sockaddr_in serverSock, clientSock;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    // Bind the socket to a port
    serverSock.sin_family = AF_INET;
    serverSock.sin_port = htons(port);
    bind(sockfd, (struct sockaddr*)&serverSock, sizeof(serverSock));

    // Listen for clients
    while (1) {
        // Accept a client connection
        newsockfd = accept(sockfd, (struct sockaddr*)&clientSock, NULL);

        // Add the client to the list
        addClient("Client", newsockfd);

        // Send a welcome message to the client
        write(newsockfd, "Welcome to the chat server!", 29);

        // Increment the client count
        clientCount++;

        // Print the client list
        printf("Clients: %d\n", clientCount);
    }

    // Close the socket
    close(sockfd);

    return 0;
}