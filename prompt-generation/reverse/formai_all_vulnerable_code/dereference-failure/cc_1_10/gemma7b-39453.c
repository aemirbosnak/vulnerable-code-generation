//Gemma-7B DATASET v1.0 Category: Chat server ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

typedef struct Client {
    int sockfd;
    char name[255];
    struct Client* next;
} Client;

Client* head = NULL;

void addClient(int sockfd, char* name) {
    Client* newClient = (Client*)malloc(sizeof(Client));
    newClient->sockfd = sockfd;
    strcpy(newClient->name, name);
    newClient->next = head;
    head = newClient;
}

void removeClient(int sockfd) {
    Client* previousClient = NULL;
    Client* currentClient = head;

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

void broadcastMessage(char* message) {
    Client* currentClient = head;

    while (currentClient) {
        send(currentClient->sockfd, message, BUFFER_SIZE, 0);
    }
}

int main() {
    int sockfd, newsockfd, port = 8080;
    struct sockaddr_in serverSock, clientSock;
    char buffer[BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    serverSock.sin_family = AF_INET;
    serverSock.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr*)&serverSock, sizeof(serverSock)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    while (1) {
        // Accept a client connection
        newsockfd = accept(sockfd, (struct sockaddr*)&clientSock, NULL);
        if (newsockfd < 0) {
            perror("Error accepting client connection");
            continue;
        }

        // Get the client's name
        char name[255];
        recv(newsockfd, name, 255, 0);

        // Add the client to the list
        addClient(newsockfd, name);

        // Broadcast a message to all clients
        char message[BUFFER_SIZE];
        sprintf(message, "New client: %s has joined the chat.", name);
        broadcastMessage(message);

        // Listen for messages from the client
        while (1) {
            // Receive a message from the client
            recv(newsockfd, buffer, BUFFER_SIZE, 0);

            // Broadcast the message to all clients
            broadcastMessage(buffer);

            // Check if the client has disconnected
            if (strcmp(buffer, "disconnect") == 0) {
                removeClient(newsockfd);
                break;
            }
        }

        // Close the client connection
        close(newsockfd);
    }

    return 0;
}