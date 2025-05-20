//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 8080

typedef struct Client {
    int sockfd;
    struct Client *next;
} Client;

Client *head = NULL;

void addClient(int sockfd) {
    Client *newClient = malloc(sizeof(Client));
    newClient->sockfd = sockfd;
    newClient->next = head;
    head = newClient;
}

void removeClient(int sockfd) {
    Client *prevClient = NULL;
    Client *currentClient = head;

    while (currentClient && currentClient->sockfd != sockfd) {
        prevClient = currentClient;
        currentClient = currentClient->next;
    }

    if (prevClient) {
        prevClient->next = currentClient->next;
    } else {
        head = currentClient->next;
    }

    free(currentClient);
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in sockAddr, clientAddr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
    bind(sockfd, (struct sockaddr *)&sockAddr, sizeof(sockAddr));

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&clientAddr, NULL);
        addClient(newsockfd);

        printf("Client connected: %d\n", newsockfd);

        while (1) {
            int bytesRead = read(newsockfd, buffer, 1024);

            if (bytesRead > 0) {
                printf("Received: %s\n", buffer);
            } else if (bytesRead == 0) {
                printf("Client disconnected: %d\n", newsockfd);
                removeClient(newsockfd);
                break;
            } else {
                printf("Error reading from client: %d\n", newsockfd);
            }

            int bytesWritten = write(newsockfd, buffer, bytesRead);

            if (bytesWritten < 0) {
                printf("Error writing to client: %d\n", newsockfd);
            }
        }

        close(newsockfd);
    }

    return 0;
}