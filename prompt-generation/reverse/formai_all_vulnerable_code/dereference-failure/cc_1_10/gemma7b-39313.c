//Gemma-7B DATASET v1.0 Category: Chat server ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define MAX_CLIENTS 10

typedef struct Client {
  char name[20];
  int sockfd;
  struct Client* next;
} Client;

Client* head = NULL;

void addClient(char* name, int sockfd) {
  Client* newClient = (Client*)malloc(sizeof(Client));
  strcpy(newClient->name, name);
  newClient->sockfd = sockfd;
  newClient->next = head;
  head = newClient;
}

void removeClient(int sockfd) {
  Client* prevClient = NULL;
  Client* currentClient = head;
  while (currentClient) {
    if (currentClient->sockfd == sockfd) {
      if (prevClient) {
        prevClient->next = currentClient->next;
      } else {
        head = currentClient->next;
      }
      free(currentClient);
      return;
    }
    prevClient = currentClient;
    currentClient = currentClient->next;
  }
}

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in serverSock, clientSock;
  char buffer[1024];

  sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
  bind(sockfd, (struct sockaddr*)&serverSock, sizeof(serverSock));

  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr*)&clientSock, NULL);
    addClient(inet_ntoa(clientSock.sin_addr), newsockfd);

    printf("Client connected: %s\n", inet_ntoa(clientSock.sin_addr));

    while (1) {
      recv(newsockfd, buffer, 1024, 0);
      printf("Client: %s\n", buffer);

      if (strcmp(buffer, "quit") == 0) {
        break;
      }

      send(newsockfd, buffer, 1024, 0);
    }

    removeClient(newsockfd);
    printf("Client disconnected: %s\n", inet_ntoa(clientSock.sin_addr));
  }

  return 0;
}