//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct Client {
    int socketfd;
    char name[255];
    struct Client* next;
} Client;

Client* clients = NULL;

void handleClient(int sockfd) {
    char buffer[BUFFER_SIZE];
    int nread = read(sockfd, buffer, BUFFER_SIZE);
    if (nread > 0) {
        printf("Client: %s sent: %s\n", clients->name, buffer);
        write(sockfd, buffer, nread);
    } else {
        printf("Error: client disconnected.\n");
        close(sockfd);
        Client* client = clients;
        clients = clients->next;
        free(client);
    }
}

int main() {
    int listenfd, sockfd, clientfd;
    struct sockaddr_in serverAddr, clientAddr;
    int sin_size = sizeof(clientAddr);

    listenfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    bind(listenfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    clients = NULL;

    while (1) {
        clientfd = accept(listenfd, (struct sockaddr*)&clientAddr, &sin_size);
        Client* client = malloc(sizeof(Client));
        client->socketfd = clientfd;
        strcpy(client->name, "Client");
        client->next = clients;
        clients = client;

        handleClient(clientfd);
    }

    return 0;
}