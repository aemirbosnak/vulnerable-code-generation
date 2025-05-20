//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CLIENT_NUMBER 10

typedef struct Client {
    char name[20];
    int sockfd;
    struct Client *next;
} Client;

Client *head = NULL;

void addClient(char *name, int sockfd) {
    Client *newClient = malloc(sizeof(Client));
    strcpy(newClient->name, name);
    newClient->sockfd = sockfd;
    newClient->next = NULL;

    if (head == NULL) {
        head = newClient;
    } else {
        Client *lastClient = head;
        while (lastClient->next) {
            lastClient = lastClient->next;
        }
        lastClient->next = newClient;
    }
}

void removeClient(int sockfd) {
    Client *prevClient = NULL;
    Client *currentClient = head;

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
    int sockfd, newsockfd, clientNumber = 0;
    struct sockaddr_in serverSockAddr, clientSockAddr;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(80));

    // Bind the socket to a port
    serverSockAddr.sin_family = AF_INET;
    serverSockAddr.sin_port = htons(8080);
    bind(sockfd, (struct sockaddr *)&serverSockAddr, sizeof(serverSockAddr));

    // Listen for clients
    while (1) {
        // Accept a client connection
        newsockfd = accept(sockfd, (struct sockaddr *)&clientSockAddr, NULL);

        // Add the client to the list
        addClient("Client", newsockfd);

        // Send a welcome message to the client
        write(newsockfd, "Welcome to the server!", 20);

        // Receive a message from the client
        read(newsockfd, buffer, 1024);

        // Print the message to the console
        printf("Client: %s, Message: %s\n", clientSockAddr.sin_addr.s_addr, buffer);

        // Close the client connection
        close(newsockfd);

        // Remove the client from the list
        removeClient(newsockfd);
    }

    return 0;
}