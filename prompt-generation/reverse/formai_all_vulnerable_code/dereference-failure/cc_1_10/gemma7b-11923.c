//Gemma-7B DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define MAX_CLIENTS 10

struct Client {
  char name[20];
  int sockfd;
  struct Client* next;
};

void handle_client(struct Client* client) {
  char msg[200];

  // Receive message from client
  recv(client->sockfd, msg, 200, 0);

  // Print message to other clients
  struct Client* current = client;
  while (current) {
    if (current->sockfd != client->sockfd) {
      send(current->sockfd, msg, strlen(msg) + 1, 0);
    }
    current = current->next;
  }

  // Send message back to client
  send(client->sockfd, msg, strlen(msg) + 1, 0);

  // Free client resources
  free(client);
}

int main() {
  struct Client* clients = NULL;
  int listenfd, clientfd;
  struct sockaddr_in server_addr, client_addr;

  // Create listening socket
  listenfd = socket(AF_INET, SOCK_STREAM, htons(65535));

  // Bind socket to port
  bind(listenfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  // Listen for clients
  while (1) {
    // Accept client connection
    clientfd = accept(listenfd, (struct sockaddr *)&client_addr, NULL);

    // Create new client structure
    struct Client* new_client = malloc(sizeof(struct Client));
    new_client->sockfd = clientfd;
    strcpy(new_client->name, "Client");
    new_client->next = clients;
    clients = new_client;

    // Handle client
    handle_client(new_client);
  }

  return 0;
}