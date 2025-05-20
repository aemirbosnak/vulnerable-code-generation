//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 512

typedef struct Client {
    int sockfd;
    char name[256];
    struct Client* next;
} Client;

Client* head = NULL;

void handleClient(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytesRead = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytesRead > 0) {
        printf("Client: %s said: %s\n", head->name, buffer);
    } else {
        printf("Client: %s disconnected.\n", head->name);
        close(sockfd);
        Client* client = head;
        head = client->next;
        free(client);
    }
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serverSock, clientSock;
    int clientCount = 0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    serverSock.sin_family = AF_INET;
    serverSock.sin_port = htons(8080);
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

        // Create a new client structure
        Client* client = (Client*)malloc(sizeof(Client));
        client->sockfd = newsockfd;
        client->next = NULL;
        client->name[0] = '\0';

        // Add the client to the head of the client list
        if (head == NULL) {
            head = client;
        } else {
            client->next = head;
            head = client;
        }

        // Handle the client
        handleClient(newsockfd);

        // Increment the client count
        clientCount++;

        // If the client count reaches the maximum number of clients, close the socket
        if (clientCount >= MAX_CLIENTS) {
            close(sockfd);
            exit(0);
        }
    }

    return 0;
}