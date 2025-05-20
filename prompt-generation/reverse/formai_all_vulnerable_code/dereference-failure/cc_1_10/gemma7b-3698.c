//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

typedef struct Client {
    char *name;
    int socketfd;
    struct Client *next;
} Client;

Client *head = NULL;

void addClient(char *name, int socketfd) {
    Client *newClient = malloc(sizeof(Client));
    newClient->name = strdup(name);
    newClient->socketfd = socketfd;
    newClient->next = NULL;

    if (head == NULL) {
        head = newClient;
    } else {
        Client *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newClient;
    }
}

int main() {

    int sockfd, clientfd, port = 8080;
    char buffer[MAX_BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    // Bind the socket to a port
    struct sockaddr_in serverAddr;
    serverAddr.sin_port = htons(port);
    bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    // Listen for clients
    while (1) {
        // Accept a client connection
        clientfd = accept(sockfd, NULL, NULL);

        // Add the client to the list
        addClient("Romeo", clientfd);

        // Send a welcome message to the client
        write(clientfd, "Welcome to the proxy server, Romeo!", 40);
    }

    return 0;
}