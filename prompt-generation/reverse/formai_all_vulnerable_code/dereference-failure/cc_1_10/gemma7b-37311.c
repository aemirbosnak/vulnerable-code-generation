//Gemma-7B DATASET v1.0 Category: System administration ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTS 10

typedef struct Client {
    char name[256];
    int id;
    struct Client* next;
} Client;

Client* clients = NULL;

void addClient(char* name) {
    Client* newClient = (Client*)malloc(sizeof(Client));
    strcpy(newClient->name, name);
    newClient->id = clients ? clients->id + 1 : 0;
    newClient->next = clients;
    clients = newClient;
}

void removeClient(int id) {
    Client* prevClient = NULL;
    Client* currentClient = clients;

    while (currentClient) {
        if (currentClient->id == id) {
            if (prevClient) {
                prevClient->next = currentClient->next;
            } else {
                clients = currentClient->next;
            }
            free(currentClient);
            return;
        }

        prevClient = currentClient;
        currentClient = currentClient->next;
    }

    return;
}

int main() {
    addClient("John Doe");
    addClient("Jane Doe");
    addClient("Peter Pan");

    removeClient(2);

    Client* currentClient = clients;

    while (currentClient) {
        printf("Name: %s, ID: %d\n", currentClient->name, currentClient->id);
        currentClient = currentClient->next;
    }

    return 0;
}