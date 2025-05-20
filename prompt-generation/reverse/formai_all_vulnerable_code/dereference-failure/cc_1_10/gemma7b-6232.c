//Gemma-7B DATASET v1.0 Category: Chat server ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CLIENTS 10

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
    int sockfd, newsockfd;
    struct sockaddr_in serverSock, clientSock;
    char buffer[1024];

    // Bind the socket to a port
    sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    serverSock.sin_family = AF_INET;
    serverSock.sin_port = htons(8080);
    bind(sockfd, (struct sockaddr*)&serverSock, sizeof(serverSock));

    // Listen for clients
    while (1) {
        // Accept a client connection
        newsockfd = accept(sockfd, (struct sockaddr*)&clientSock, NULL);
        addClient(inet_ntoa(clientSock.sin_addr), newsockfd);

        // Send a welcome message to the client
        sprintf(buffer, "Welcome to the C Chat Server, %s!", inet_ntoa(clientSock.sin_addr));
        write(newsockfd, buffer, strlen(buffer));

        // Listen for client messages
        while (1) {
            // Receive a message from the client
            read(newsockfd, buffer, 1024);

            // Broadcast the message to all clients
            for (Client* client = head; client; client) {
                if (client->sockfd != newsockfd) {
                    write(client->sockfd, buffer, strlen(buffer));
                }
            }

            // Check if the client has disconnected
            if (strcmp(buffer, "quit") == 0) {
                removeClient(newsockfd);
                break;
            }
        }

        // Close the client connection
        close(newsockfd);
    }

    return 0;
}