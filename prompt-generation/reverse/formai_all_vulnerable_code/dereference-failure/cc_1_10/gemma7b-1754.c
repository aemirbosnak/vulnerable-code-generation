//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CLIENTS 10

typedef struct Client {
    char name[20];
    int sockfd;
    struct Client *next;
} Client;

Client *clients = NULL;

void handleClient(int sockfd) {
    Client *client = malloc(sizeof(Client));
    client->sockfd = sockfd;

    // Get client name
    char name[20];
    recv(sockfd, name, 20, 0);
    strcpy(client->name, name);

    // Send welcome message
    char message[100] = "Welcome, ";
    strcat(message, client->name);
    send(sockfd, message, strlen(message), 0);

    // Listen for client messages
    char message_recv[100];
    while (recv(sockfd, message_recv, 100, 0) > 0) {
        // Broadcast message to other clients
        for (Client *iter = clients; iter; iter = iter->next) {
            if (iter->sockfd != sockfd) {
                send(iter->sockfd, message_recv, strlen(message_recv), 0);
            }
        }
    }

    // Free client resources
    free(client);
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    listen(sockfd, MAX_CLIENTS);

    // Handle clients
    while (1) {
        int newsockfd = accept(sockfd, NULL, NULL);
        if (newsockfd < 0) {
            perror("Error accepting client");
            continue;
        }
        handleClient(newsockfd);
    }

    return 0;
}