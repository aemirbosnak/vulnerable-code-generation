//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 10

struct Client {
  char name[256];
  int sockfd;
  struct Client* next;
};

void handleClient(struct Client* client) {
  char message[256];
  printf("Client: %s\n", client->name);
  printf("Enter a message: ");
  scanf("%s", message);
  send(client->sockfd, message, sizeof(message), 0);
  printf("Message sent: %s\n", message);
}

int main() {
  int listenfd, clientfd;
  struct Client* head = NULL;

  // Create a socket for listening
  listenfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
  if (listenfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Listen for clients
  while (1) {
    clientfd = accept(listenfd, NULL, NULL);
    if (clientfd < 0) {
      perror("Error accepting client");
      continue;
    }

    // Create a new client structure
    struct Client* newClient = malloc(sizeof(struct Client));
    newClient->sockfd = clientfd;
    strcpy(newClient->name, "Client");

    // Add the new client to the head of the list
    if (head == NULL) {
      head = newClient;
    } else {
      newClient->next = head;
      head = newClient;
    }

    // Handle the client
    handleClient(newClient);

    // Close the client socket
    close(clientfd);
  }

  return 0;
}