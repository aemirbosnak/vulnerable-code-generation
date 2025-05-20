//Gemma-7B DATASET v1.0 Category: Chat server ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT 8080

typedef struct Client {
  char name[20];
  int sockfd;
  struct Client* next;
} Client;

Client* head = NULL;

void addClient(char* name, int sockfd) {
  Client* newClient = malloc(sizeof(Client));
  strcpy(newClient->name, name);
  newClient->sockfd = sockfd;
  newClient->next = NULL;

  if (head == NULL) {
    head = newClient;
  } else {
    Client* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newClient;
  }
}

void removeClient(int sockfd) {
  Client* temp = head;
  Client* prev = NULL;

  while (temp && temp->sockfd != sockfd) {
    prev = temp;
    temp = temp->next;
  }

  if (prev) {
    prev->next = temp->next;
  } else {
    head = temp->next;
  }

  free(temp);
}

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in serverSock, clientSock;
  char buffer[1024];

  sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
  serverSock.sin_family = AF_INET;
  serverSock.sin_port = htons(PORT);
  bind(sockfd, (struct sockaddr*)&serverSock, sizeof(serverSock));

  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr*)&clientSock, NULL);
    addClient(inet_ntoa(clientSock.sin_addr), newsockfd);

    printf("Client connected: %s\n", inet_ntoa(clientSock.sin_addr));

    while (1) {
      int len = recv(newsockfd, buffer, 1024, 0);
      if (len > 0) {
        printf("Client: %s\n", buffer);
      } else {
        removeClient(newsockfd);
        break;
      }
    }

    close(newsockfd);
  }

  return 0;
}