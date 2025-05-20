//Gemma-7B DATASET v1.0 Category: Chat server ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 8080

#define BUFFER_SIZE 1024

typedef struct Client {
    char name[256];
    int socketfd;
    struct Client* next;
} Client;

Client* headClient = NULL;

void addClient(char* name, int socketfd) {
    Client* newClient = malloc(sizeof(Client));
    strcpy(newClient->name, name);
    newClient->socketfd = socketfd;
    newClient->next = NULL;

    if (headClient == NULL) {
        headClient = newClient;
    } else {
        Client* currentClient = headClient;
        while (currentClient->next) {
            currentClient = currentClient->next;
        }
        currentClient->next = newClient;
    }
}

void removeClient(int socketfd) {
    Client* currentClient = headClient;
    Client* previousClient = NULL;

    while (currentClient) {
        if (currentClient->socketfd == socketfd) {
            if (previousClient) {
                previousClient->next = currentClient->next;
            } else {
                headClient = currentClient->next;
            }
            free(currentClient);
            return;
        }
        previousClient = currentClient;
        currentClient = currentClient->next;
    }
}

int main() {
    int listenfd, socketfd;
    struct sockaddr_in serverSockaddr, clientSockaddr;
    char buffer[BUFFER_SIZE];

    listenfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    bind(listenfd, (struct sockaddr*)&serverSockaddr, sizeof(serverSockaddr));

    while (1) {
        socketfd = accept(listenfd, (struct sockaddr*)&clientSockaddr, NULL);
        addClient("Client", socketfd);

        printf("Client connected: %s\n", clientSockaddr.sin_addr.s_addr);

        while (1) {
            recv(socketfd, buffer, BUFFER_SIZE, 0);
            printf("Client: %s\n", buffer);

            send(socketfd, buffer, BUFFER_SIZE, 0);
            printf("Server: %s\n", buffer);

            if (strcmp(buffer, "quit") == 0) {
                break;
            }
        }

        removeClient(socketfd);
        close(socketfd);
        printf("Client disconnected: %s\n", clientSockaddr.sin_addr.s_addr);
    }

    return 0;
}