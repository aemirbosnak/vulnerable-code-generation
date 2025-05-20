//Gemma-7B DATASET v1.0 Category: Chat server ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct Client {
    char name[256];
    int socketfd;
    struct Client* next;
} Client;

Client* head = NULL;

void handleClient(int sockfd) {
    Client* newClient = malloc(sizeof(Client));
    newClient->socketfd = sockfd;

    // Get client name
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    strcpy(newClient->name, buffer);

    // Add client to list
    newClient->next = head;
    head = newClient;

    // Send welcome message
    char message[256] = "Welcome to the C Chat server, ";
    strcat(message, newClient->name);
    send(sockfd, message, strlen(message), 0);

    // Listen for client messages
    while (1) {
        // Receive message from client
        recv(sockfd, buffer, BUFFER_SIZE, 0);

        // Broadcast message to other clients
        for (Client* client = head; client; client = client->next) {
            if (client->socketfd != sockfd) {
                send(client->socketfd, buffer, strlen(buffer), 0);
            }
        }

        // Check if client has disconnected
        if (strcmp(buffer, "disconnect") == 0) {
            break;
        }
    }

    // Remove client from list
    Client* previous = NULL;
    for (Client* client = head; client; client = client->next) {
        if (client->socketfd == sockfd) {
            if (previous) {
                previous->next = client->next;
            } else {
                head = client->next;
            }
            free(client);
            break;
        }
        previous = client;
    }

    // Close client socket
    close(sockfd);
}

int main() {
    // Listen for clients
    int sockfd, clientfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));

    // Bind socket to port
    server_addr.sin_port = htons(8080);
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for client connections
    while (1) {
        // Accept client connection
        clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);

        // Handle client connection
        handleClient(clientfd);
    }

    return 0;
}