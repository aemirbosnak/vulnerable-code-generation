//Gemma-7B DATASET v1.0 Category: Chat server ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_CLIENTS 10

struct Client {
  int sockfd;
  char name[255];
  struct Client *next;
};

void handle_client(struct Client *client) {
  char buffer[1024];

  // Receive message from client
  recv(client->sockfd, buffer, 1024, 0);

  // Print message to server console
  printf("%s: %s\n", client->name, buffer);

  // Send message back to client
  sprintf(buffer, "Server: %s", client->name);
  send(client->sockfd, buffer, strlen(buffer) + 1, 0);
}

int main() {
  int listenfd, sockfd, clientfd;
  struct Client *clients = NULL;

  // Create a socket for listening
  listenfd = socket(AF_INET, SOCK_STREAM, htons(65535));

  // Bind the socket to a port
  bind(listenfd, NULL, 0);

  // Listen for clients
  while (1) {
    // Accept a client connection
    sockfd = accept(listenfd, NULL, NULL);

    // Create a new client structure
    struct Client *client = malloc(sizeof(struct Client));
    client->sockfd = sockfd;
    client->next = clients;
    clients = client;

    // Handle the client
    handle_client(client);

    // Close the client connection
    close(sockfd);
  }

  return 0;
}