//Gemma-7B DATASET v1.0 Category: Chat server ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct Client {
    int sockfd;
    char name[256];
    struct Client* next;
} Client;

Client* head = NULL;

void addClient(int sockfd, char* name) {
    Client* newClient = malloc(sizeof(Client));
    newClient->sockfd = sockfd;
    strcpy(newClient->name, name);
    newClient->next = NULL;

    if (head == NULL) {
        head = newClient;
    } else {
        Client* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newClient;
    }
}

void removeClient(int sockfd) {
    Client* temp = head;
    Client* prev = NULL;

    while (temp) {
        if (temp->sockfd == sockfd) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serverSock, clientSock;
    int clientCount = 0;
    char buffer[BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Bind the socket to a port
    serverSock.sin_family = AF_INET;
    serverSock.sin_port = htons(8888);
    if (bind(sockfd, (struct sockaddr*)&serverSock, sizeof(serverSock)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    // Listen for clients
    while (1) {
        // Accept a client connection
        newsockfd = accept(sockfd, (struct sockaddr*)&clientSock, NULL);
        if (newsockfd < 0) {
            perror("Error accepting client connection");
            continue;
        }

        // Add the client to the list
        addClient(newsockfd, clientSock.sin_addr.s_addr);

        // Send a welcome message to the client
        snprintf(buffer, BUFFER_SIZE, "Welcome to the C Chat server, %s!", clientSock.sin_addr.s_addr);
        write(newsockfd, buffer, strlen(buffer));

        // Listen for client messages
        while (1) {
            // Receive a message from the client
            int bytesRead = read(newsockfd, buffer, BUFFER_SIZE);
            if (bytesRead < 0) {
                perror("Error reading message");
                break;
            }

            // Broadcast the message to all clients
            for (Client* client = head; client; client = client->next) {
                if (client->sockfd != newsockfd) {
                    write(client->sockfd, buffer, bytesRead);
                }
            }
        }

        // Remove the client from the list
        removeClient(newsockfd);

        // Close the client socket
        close(newsockfd);
    }

    return 0;
}