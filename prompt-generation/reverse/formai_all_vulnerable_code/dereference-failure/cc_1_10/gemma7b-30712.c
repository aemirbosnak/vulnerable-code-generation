//Gemma-7B DATASET v1.0 Category: Firewall ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define SERVER_PORT 8888

// Define a structure to store client information
typedef struct Client {
  char name[255];
  int sockfd;
  struct Client* next;
} Client;

Client* head = NULL;

void handleClient(int sockfd) {
  char msg[255];
  recv(sockfd, msg, 255, 0);

  // Check if the client is new
  Client* client = head;
  while (client) {
    if (client->sockfd == sockfd) {
      break;
    }
    client = client->next;
  }

  // If the client is new, add it to the list
  if (client == NULL) {
    client = malloc(sizeof(Client));
    memset(client, 0, sizeof(Client));
    strcpy(client->name, msg);
    client->sockfd = sockfd;
    client->next = head;
    head = client;
  }

  // Send a message back to the client
  sprintf(msg, "Hello, %s!", client->name);
  send(sockfd, msg, strlen(msg) + 1, 0);
}

int main() {
  // Listen for clients on the server port
  int sockfd = listen(SERVER_PORT, 10);

  // Handle clients
  while (1) {
    int newsockfd = accept(sockfd, NULL, NULL);
    handleClient(newsockfd);
  }

  return 0;
}