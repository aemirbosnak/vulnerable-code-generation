//Gemma-7B DATASET v1.0 Category: Chat server ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

#define MAX_CLIENTS 10

typedef struct Client {
    char name[255];
    int sockfd;
    struct Client *next;
} Client;

Client *head = NULL;

void addClient(char *name, int sockfd) {
    Client *newClient = malloc(sizeof(Client));
    strcpy(newClient->name, name);
    newClient->sockfd = sockfd;
    newClient->next = NULL;

    if (head == NULL) {
        head = newClient;
    } else {
        Client *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newClient;
    }
}

void removeClient(int sockfd) {
    Client *temp = head;
    Client *prev = NULL;

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
    int listenfd, sockfd, clientfd;
    struct sockaddr_in serverSock, clientSock;
    char buffer[1024];

    listenfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    bind(listenfd, (struct sockaddr *)&serverSock, sizeof(serverSock));

    while (1) {
        clientfd = accept(listenfd, (struct sockaddr *)&clientSock, NULL);
        addClient("John Doe", clientfd);

        printf("Client connected: %s\n", clientSock.sin_addr.s_addr);

        while (1) {
            recv(clientfd, buffer, 1024, 0);
            printf("Client: %s\n", buffer);

            if (strcmp(buffer, "quit") == 0) {
                break;
            }

            send(clientfd, buffer, strlen(buffer) + 1, 0);
        }

        removeClient(clientfd);
        close(clientfd);
    }

    return 0;
}