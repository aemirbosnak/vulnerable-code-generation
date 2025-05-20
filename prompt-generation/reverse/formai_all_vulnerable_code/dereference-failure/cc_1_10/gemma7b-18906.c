//Gemma-7B DATASET v1.0 Category: System administration ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTS 10

typedef struct Client {
  char name[255];
  int id;
  struct Client* next;
} Client;

Client* head = NULL;

void addClient(char* name, int id) {
  Client* newClient = (Client*)malloc(sizeof(Client));
  strcpy(newClient->name, name);
  newClient->id = id;
  newClient->next = NULL;

  if (head == NULL) {
    head = newClient;
  } else {
    Client* currentClient = head;
    while (currentClient->next) {
      currentClient = currentClient->next;
    }
    currentClient->next = newClient;
  }
}

void removeClient(int id) {
  Client* previousClient = NULL;
  Client* currentClient = head;

  while (currentClient) {
    if (currentClient->id == id) {
      if (previousClient) {
        previousClient->next = currentClient->next;
      } else {
        head = currentClient->next;
      }
      free(currentClient);
      return;
    }
    previousClient = currentClient;
    currentClient = currentClient->next;
  }

  printf("Client not found.\n");
}

int main() {
  addClient("John Doe", 1);
  addClient("Jane Doe", 2);
  addClient("Peter Pan", 3);

  removeClient(2);

  Client* currentClient = head;
  while (currentClient) {
    printf("%s (%d)\n", currentClient->name, currentClient->id);
    currentClient = currentClient->next;
  }

  return 0;
}