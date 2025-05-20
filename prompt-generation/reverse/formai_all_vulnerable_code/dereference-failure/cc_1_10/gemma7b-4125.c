//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_CLIENTS 10

typedef struct Client {
    int socketfd;
    char name[20];
    struct Client* next;
} Client;

Client* head = NULL;

void handleClient(int sockfd) {
    char buf[1024];
    Client* client = malloc(sizeof(Client));
    client->socketfd = sockfd;
    client->next = NULL;

    if (head == NULL) {
        head = client;
    } else {
        head->next = client;
        head = client;
    }

    printf("Client connected: %s\n", client->name);

    while (1) {
        int bytesRead = read(sockfd, buf, 1024);
        if (bytesRead > 0) {
            printf("Client: %s: %s\n", client->name, buf);
        } else if (bytesRead == 0) {
            printf("Client disconnected: %s\n", client->name);
            break;
        } else {
            perror("Error reading from client");
            break;
        }
    }

    free(client);
}

int main() {
    int sockfd, clientfd;
    struct sockaddr_in servaddr, cliaddr;
    int sin_size = sizeof(cliaddr);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    while (1) {
        // Accept a client connection
        clientfd = accept(sockfd, (struct sockaddr*)&cliaddr, &sin_size);
        if (clientfd < 0) {
            perror("Error accepting client connection");
            continue;
        }

        // Handle the client
        handleClient(clientfd);
    }

    return 0;
}