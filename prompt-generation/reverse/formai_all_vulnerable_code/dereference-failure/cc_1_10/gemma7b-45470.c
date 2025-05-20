//Gemma-7B DATASET v1.0 Category: System administration ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define SERVER_PORT 8888
#define MAX_NUM_CLIENTS 10

typedef struct Client {
  char name[20];
  int socketfd;
  struct Client* next;
} Client;

Client* head = NULL;

void handleClient(int sockfd) {
  Client* newClient = malloc(sizeof(Client));
  newClient->socketfd = sockfd;

  // Get client name
  char name[20];
  recv(sockfd, name, 20, 0);
  strcpy(newClient->name, name);

  // Add client to head
  newClient->next = head;
  head = newClient;

  // Broadcast message to all clients
  char message[200];
  strcpy(message, "New client joined: ");
  strcat(message, newClient->name);
  send(newClient->socketfd, message, strlen(message), 0);

  // Client loop
  while (1) {
    // Receive message from client
    recv(sockfd, message, 200, 0);

    // Broadcast message to all clients
    strcat(message, " - ");
    strcat(message, newClient->name);
    send(newClient->socketfd, message, strlen(message), 0);

    // Check if client wants to leave
    char leave[20];
    recv(sockfd, leave, 20, 0);
    if (strcmp(leave, "leave") == 0) {
      break;
    }
  }

  // Remove client from head
  Client* prevClient = NULL;
  for (Client* currentClient = head; currentClient; currentClient = currentClient->next) {
    if (currentClient->socketfd == sockfd) {
      if (prevClient) {
        prevClient->next = currentClient->next;
      } else {
        head = currentClient->next;
      }
      free(currentClient);
      break;
    }
    prevClient = currentClient;
  }

  // Close client socket
  close(sockfd);
}

int main() {
  // Start listening for clients
  int sockfd = listen(SERVER_PORT, MAX_NUM_CLIENTS);

  // Handle clients
  while (1) {
    int newsockfd = accept(sockfd);
    handleClient(newsockfd);
  }

  return 0;
}