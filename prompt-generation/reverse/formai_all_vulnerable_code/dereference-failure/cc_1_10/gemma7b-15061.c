//Gemma-7B DATASET v1.0 Category: System administration ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SERVER_PORT 5000
#define MAX_CLIENTS 10

typedef struct Client {
    char name[255];
    int socket_fd;
    struct Client* next;
} Client;

Client* clients = NULL;

void addClient(char* name, int sockfd) {
    Client* newClient = (Client*)malloc(sizeof(Client));
    strcpy(newClient->name, name);
    newClient->socket_fd = sockfd;
    newClient->next = clients;
    clients = newClient;
}

void removeClient(char* name) {
    Client* previousClient = NULL;
    Client* currentClient = clients;

    while (currentClient) {
        if (strcmp(currentClient->name, name) == 0) {
            if (previousClient) {
                previousClient->next = currentClient->next;
            } else {
                clients = currentClient->next;
            }
            free(currentClient);
            return;
        }
        previousClient = currentClient;
        currentClient = currentClient->next;
    }

    return;
}

int main() {
    int sockfd, client_fd, new_fd;
    char buffer[1024], name[255];

    // Listen for clients on the server port
    sockfd = listen(SERVER_PORT, MAX_CLIENTS);

    // Accept client connections
    while (1) {
        client_fd = accept(sockfd, NULL, NULL);

        // Get the client's name
        recv(client_fd, name, 255, 0);

        // Add the client to the list
        addClient(name, client_fd);

        // Send a welcome message to the client
        send(client_fd, "Welcome to the server!", 23, 0);

        // Close the client connection
        close(client_fd);
    }

    return 0;
}