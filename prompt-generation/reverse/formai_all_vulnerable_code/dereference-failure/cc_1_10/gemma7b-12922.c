//Gemma-7B DATASET v1.0 Category: Chat server ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct Client {
    char name[256];
    int sockfd;
    struct Client *next;
} Client;

Client *head = NULL;

void addClient(char *name, int sockfd) {
    Client *newClient = (Client *)malloc(sizeof(Client));
    strcpy(newClient->name, name);
    newClient->sockfd = sockfd;
    newClient->next = head;
    head = newClient;
}

void removeClient(int sockfd) {
    Client *prev = NULL;
    Client *curr = head;

    while (curr) {
        if (curr->sockfd == sockfd) {
            if (prev) {
                prev->next = curr->next;
            } else {
                head = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int main() {
    int sockfd, newsockfd, port = 8888, clients = 0;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, client_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Bind the socket to a port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    // Listen for clients
    while (1) {
        // Accept a client connection
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
        if (newsockfd < 0) {
            perror("Error accepting client connection");
            continue;
        }

        // Add the client to the list
        addClient("Client", newsockfd);

        // Send a welcome message to the client
        sprintf(buffer, "Welcome, %s!", client_addr.sin_addr.s_addr);
        write(newsockfd, buffer, strlen(buffer));

        // Listen for client messages
        while (1) {
            // Receive a message from the client
            int len = read(newsockfd, buffer, BUFFER_SIZE);
            if (len > 0) {
                // Broadcast the message to all clients
                for (Client *client = head; client; client) {
                    if (client->sockfd != newsockfd) {
                        write(client->sockfd, buffer, len);
                    }
                }
            } else if (len < 0) {
                // Client disconnected
                removeClient(newsockfd);
                break;
            }
        }

        // Close the client connection
        close(newsockfd);
        clients--;
    }

    return 0;
}