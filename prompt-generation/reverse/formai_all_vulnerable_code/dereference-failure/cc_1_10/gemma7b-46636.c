//Gemma-7B DATASET v1.0 Category: Chat server ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CLIENTS 10

typedef struct Client {
  char name[20];
  int sockfd;
  struct Client *next;
} Client;

Client *head = NULL;

void addClient(char *name, int sockfd) {
  Client *newClient = malloc(sizeof(Client));
  strcpy(newClient->name, name);
  newClient->sockfd = sockfd;
  newClient->next = NULL;

  if (head == NULL) {
    head = newClient;
  } else {
    Client *tmpClient = head;
    while (tmpClient->next) {
      tmpClient = tmpClient->next;
    }
    tmpClient->next = newClient;
  }
}

void removeClient(int sockfd) {
  Client *prevClient = NULL;
  Client *currClient = head;

  while (currClient) {
    if (currClient->sockfd == sockfd) {
      if (prevClient) {
        prevClient->next = currClient->next;
      } else {
        head = currClient->next;
      }
      free(currClient);
      return;
    }
    prevClient = currClient;
    currClient = currClient->next;
  }
}

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in serverSockAddr, clientSockAddr;
  char message[256];

  // Bind socket to port 8080
  sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
  serverSockAddr.sin_family = AF_INET;
  serverSockAddr.sin_port = htons(8080);
  bind(sockfd, (struct sockaddr *)&serverSockAddr, sizeof(serverSockAddr));

  // Listen for clients
  while (1) {
    // Accept client connection
    newsockfd = accept(sockfd, (struct sockaddr *)&clientSockAddr, NULL);
    addClient("Client", newsockfd);

    // Send welcome message
    sprintf(message, "Welcome, %s!", clientSockAddr.sin_addr.s_addr);
    write(newsockfd, message, strlen(message));

    // Listen for client messages
    while (1) {
      // Receive message from client
      read(newsockfd, message, 256);

      // Broadcast message to other clients
      for (Client *client = head; client; client) {
        if (client->sockfd != newsockfd) {
          write(client->sockfd, message, strlen(message));
        }
      }

      // Check if client has disconnected
      if (strcmp(message, "Disconnect") == 0) {
        removeClient(newsockfd);
        break;
      }
    }

    // Close client connection
    close(newsockfd);
  }

  return 0;
}