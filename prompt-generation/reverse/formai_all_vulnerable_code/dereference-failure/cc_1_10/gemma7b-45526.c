//Gemma-7B DATASET v1.0 Category: Chat server ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_CLIENTS 10

typedef struct Client {
    char name[20];
    int sockfd;
    struct Client *next;
} Client;

Client *head = NULL;

void addClient(char *name, int sockfd) {
    Client *newClient = (Client *)malloc(sizeof(Client));
    strcpy(newClient->name, name);
    newClient->sockfd = sockfd;
    newClient->next = NULL;

    if (head == NULL) {
        head = newClient;
    } else {
        Client *tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = newClient;
    }
}

void removeClient(int sockfd) {
    Client *tmp = head;
    Client *prev = NULL;

    while (tmp) {
        if (tmp->sockfd == sockfd) {
            if (prev) {
                prev->next = tmp->next;
            } else {
                head = tmp->next;
            }
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

int main() {
    int sockfd, newsockfd, clientCount = 0;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));

    // Bind the socket to a port
    bind(sockfd, NULL, 0);

    // Listen for clients
    while (1) {
        // Accept a client connection
        newsockfd = accept(sockfd, NULL, NULL);

        // Add the client to the list
        addClient("Client", newsockfd);

        // Send a welcome message to the client
        write(newsockfd, "Welcome to the C Chat Server!", 34);

        // Receive a message from the client
        read(newsockfd, buffer, 1024);

        // Broadcast the message to all clients
        for (Client *client = head; client; client) {
            if (client->sockfd != newsockfd) {
                write(client->sockfd, buffer, strlen(buffer) + 1);
            }
        }

        // Remove the client from the list
        removeClient(newsockfd);

        // Close the client connection
        close(newsockfd);

        clientCount++;
    }

    return 0;
}