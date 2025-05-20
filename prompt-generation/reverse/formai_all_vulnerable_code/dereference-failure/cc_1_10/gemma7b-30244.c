//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_CONNECTIONS 10

typedef struct Client {
  int sockfd;
  struct Client *next;
} Client;

Client *head = NULL;

void addClient(int sockfd) {
  Client *newClient = malloc(sizeof(Client));
  newClient->sockfd = sockfd;
  newClient->next = NULL;

  if (head == NULL) {
    head = newClient;
  } else {
    Client *lastClient = head;
    while (lastClient->next) {
      lastClient = lastClient->next;
    }
    lastClient->next = newClient;
  }
}

int main() {
  int listenfd, sockfd, clientfd;
  struct sockaddr_in serverSock, clientSock;
  struct hostent *host;

  listenfd = socket(AF_INET, SOCK_STREAM, htons(8080));
  serverSock.sin_family = AF_INET;
  serverSock.sin_port = htons(8080);
  serverSock.sin_addr.s_addr = INADDR_ANY;

  bind(listenfd, (struct sockaddr *)&serverSock, sizeof(serverSock));

  while (1) {
    clientfd = accept(listenfd, (struct sockaddr *)&clientSock, NULL);
    addClient(clientfd);
  }

  return 0;
}