//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: retro
#include <stdio.h>
#include <netdb.h>
#include <string.h>

#define MAX_Clients 10

typedef struct Client {
  int sockfd;
  char name[20];
  struct Client* next;
} Client;

Client* head = NULL;

void handleClient(int sockfd) {
  Client* newClient = malloc(sizeof(Client));
  newClient->sockfd = sockfd;
  newClient->next = NULL;

  if (head == NULL) {
    head = newClient;
  } else {
    head->next = newClient;
  }

  printf("Client connected: %s\n", newClient->name);

  char message[200];
  printf("Enter a message: ");
  scanf("%s", message);

  send(sockfd, message, sizeof(message), 0);

  printf("Message sent: %s\n", message);

  free(newClient);
}

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in serverSock, clientSock;
  char buffer[1024];

  // Bind socket to port 8080
  sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
  serverSock.sin_family = AF_INET;
  serverSock.sin_port = htons(8080);
  bind(sockfd, (struct sockaddr *)&serverSock, sizeof(serverSock));

  // Listen for clients
  while (1) {
    // Accept client connection
    newsockfd = accept(sockfd, (struct sockaddr *)&clientSock, NULL);

    // Handle client
    handleClient(newsockfd);
  }

  return 0;
}