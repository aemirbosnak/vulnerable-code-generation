//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define SERVER_PORT 8888

struct ClientData {
  char name[256];
  int sockfd;
  struct ClientData* next;
};

void handleClient(int sockfd) {
  struct ClientData* clientData = (struct ClientData*)malloc(sizeof(struct ClientData));
  clientData->sockfd = sockfd;
  printf("Client connected: %s\n", clientData->name);

  char message[256];
  while (1) {
    printf("Enter your message: ");
    scanf("%s", message);

    send(sockfd, message, sizeof(message), 0);
  }
}

int main() {
  // Create a linked list of clients
  struct ClientData* clients = NULL;

  // Bind the server to a port
  int serverSockfd = bind(SERVER_PORT);

  // Listen for clients
  for (;;) {
    int clientSockfd = accept(serverSockfd, NULL, NULL);

    // Add the client to the linked list
    struct ClientData* clientData = (struct ClientData*)malloc(sizeof(struct ClientData));
    clientData->sockfd = clientSockfd;
    strcpy(clientData->name, "Client");
    clientData->next = clients;
    clients = clientData;

    // Handle the client
    handleClient(clientSockfd);
  }

  return 0;
}