//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Client {
    char name[50];
    int socketfd;
    struct Client* next;
} Client;

Client* clients = NULL;

void handleClient(int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    int readBytes = read(sockfd, buffer, MAX_BUFFER_SIZE);

    if (readBytes > 0) {
        printf("Client: %s, Message: %s\n", clients->name, buffer);
    } else {
        printf("Error reading from client.\n");
    }

    close(sockfd);
}

int main() {
    int sockfd, clientfd;
    struct sockaddr_in serverSockAddr, clientSockAddr;
    unsigned int clientSockAddrLen = sizeof(clientSockAddr);

    // Bind socket to port 8080
    sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    if (sockfd < 0) {
        printf("Error binding socket.\n");
        exit(1);
    }

    // Listen for clients
    listen(sockfd, 10);

    // Accept client connection
    clientfd = accept(sockfd, (struct sockaddr *)&clientSockAddr, &clientSockAddrLen);
    if (clientfd < 0) {
        printf("Error accepting client connection.\n");
        exit(1);
    }

    // Create a new client structure
    Client* newClient = malloc(sizeof(Client));
    newClient->socketfd = clientfd;

    // Add the client to the list
    newClient->next = clients;
    clients = newClient;

    // Handle client
    handleClient(clientfd);

    return 0;
}