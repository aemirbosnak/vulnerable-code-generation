//Gemma-7B DATASET v1.0 Category: Chat server ; Style: curious
#include <stdio.h>
#include <string.h>
#include <netdb.h>

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
    newClient->next = NULL;

    if (head == NULL) {
        head = newClient;
    } else {
        Client* lastClient = head;
        while (lastClient->next) {
            lastClient = lastClient->next;
        }
        lastClient->next = newClient;
    }
}

void broadcastMessage(char* message) {
    Client* client = head;
    while (client) {
        send(client->sockfd, message, strlen(message), 0);
    }
}

int main() {
    int sockfd, newsockfd, clientfd;
    struct sockaddr_in serverSock, clientSock;
    char message[200];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));

    // Bind the socket to a port
    serverSock.sin_port = htons(8888);
    bind(sockfd, (struct sockaddr*)&serverSock, sizeof(serverSock));

    // Listen for clients
    while (1) {
        // Accept a client connection
        newsockfd = accept(sockfd, (struct sockaddr*)&clientSock, NULL);

        // Add the client to the list
        addClient(clientSock.sin_addr.s_addr, newsockfd);

        // Broadcast a message to all clients
        printf("Client connected: %s\n", clientSock.sin_addr.s_addr);
        sprintf(message, "Client %s has joined the chat.", clientSock.sin_addr.s_addr);
        broadcastMessage(message);
    }

    return 0;
}