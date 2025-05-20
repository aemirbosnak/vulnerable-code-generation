//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 10

typedef struct Client {
  char name[20];
  int sockfd;
  struct Client* next;
} Client;

Client* clients = NULL;

void handleClient(int sockfd) {
  Client* client = malloc(sizeof(Client));
  client->sockfd = sockfd;
  client->next = clients;
  clients = client;

  char message[200];
  recv(sockfd, message, 200, 0);

  printf("%s: %s\n", client->name, message);

  free(client);
}

int main() {
  int sockfd, clientfd;
  struct sockaddr_in server_addr, client_addr;
  int sin_size = sizeof(client_addr);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

  while (1) {
    clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &sin_size);
    handleClient(clientfd);
  }

  return 0;
}