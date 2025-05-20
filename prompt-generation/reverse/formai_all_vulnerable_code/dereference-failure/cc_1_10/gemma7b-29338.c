//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define MAX_CLIENTS 10

typedef struct Client {
  int sockfd;
  char name[255];
  struct Client* next;
} Client;

Client* clients = NULL;

void handleClient(int sockfd) {
  Client* client = malloc(sizeof(Client));
  client->sockfd = sockfd;
  client->next = clients;
  clients = client;

  char message[255];
  printf("Client connected: %s\n", client->name);

  while (1) {
    printf("Enter a message: ");
    scanf("%s", message);

    send(sockfd, message, strlen(message) + 1, 0);

    if (strcmp(message, "exit") == 0) {
      break;
    }
  }

  printf("Client disconnected: %s\n", client->name);
  free(client);
}

int main() {
  int sockfd, clientfd;
  struct sockaddr_in serverSockAddr;
  struct sockaddr_in clientSockAddr;
  int yes = 1;

  // Bind socket to port 8080
  sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
  serverSockAddr.sin_family = AF_INET;
  serverSockAddr.sin_port = htons(8080);
  serverSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  bind(sockfd, (struct sockaddr *)&serverSockAddr, sizeof(serverSockAddr));

  // Listen for clients
  while (yes) {
    clientfd = accept(sockfd, (struct sockaddr *)&clientSockAddr, NULL);

    // Handle client
    handleClient(clientfd);
  }

  return 0;
}