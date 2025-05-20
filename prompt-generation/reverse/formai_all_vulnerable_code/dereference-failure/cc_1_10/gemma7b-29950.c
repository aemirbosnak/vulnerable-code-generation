//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

#define MAX_CLIENTS 10

struct Client {
  char name[256];
  int sockfd;
  struct sockaddr_in sa;
  struct Client *next;
};

void handle_client(struct Client *client) {
  char message[1024];

  // Receive message from client
  recv(client->sockfd, message, 1024, 0);

  // Print message to server
  printf("%s: %s\n", client->name, message);

  // Send message back to client
  sprintf(message, "Hello, %s!", client->name);
  send(client->sockfd, message, strlen(message) + 1, 0);

  // Close client connection
  close(client->sockfd);
}

int main() {
  struct Client *clients = NULL;
  int listenfd, sockfd, client_sockfd, i;
  struct sockaddr_in sa;
  struct sockaddr_in client_sa;
  char message[1024];

  // Create a listening socket
  listenfd = socket(AF_INET, SOCK_STREAM, htons(8080));

  // Bind the listening socket
  bind(listenfd, (struct sockaddr *)&sa, sizeof(sa));

  // Listen for clients
  while (1) {
    // Accept a client connection
    client_sockfd = accept(listenfd, (struct sockaddr *)&client_sa, NULL);

    // Create a new client structure
    struct Client *new_client = malloc(sizeof(struct Client));
    new_client->sockfd = client_sockfd;
    new_client->sa = client_sa;
    new_client->next = clients;
    clients = new_client;

    // Handle the client
    handle_client(new_client);
  }

  return 0;
}