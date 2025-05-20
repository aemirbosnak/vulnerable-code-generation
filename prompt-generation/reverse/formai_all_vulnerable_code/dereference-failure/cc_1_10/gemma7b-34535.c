//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define MAX_CLIENTS 10

typedef struct Client {
  int sockfd;
  char name[256];
  struct Client* next;
} Client;

Client* head = NULL;

void addClient(int sockfd, char* name) {
  Client* newClient = malloc(sizeof(Client));
  newClient->sockfd = sockfd;
  strcpy(newClient->name, name);
  newClient->next = NULL;

  if (head == NULL) {
    head = newClient;
  } else {
    Client* currentClient = head;
    while (currentClient->next) {
      currentClient = currentClient->next;
    }
    currentClient->next = newClient;
  }
}

void removeClient(int sockfd) {
  Client* currentClient = head;
  Client* previousClient = NULL;

  while (currentClient) {
    if (currentClient->sockfd == sockfd) {
      if (previousClient) {
        previousClient->next = currentClient->next;
      } else {
        head = currentClient->next;
      }
      free(currentClient);
      return;
    }

    previousClient = currentClient;
    currentClient = currentClient->next;
  }
}

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in serverSock, clientSock;
  char buffer[1024];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  serverSock.sin_family = AF_INET;
  serverSock.sin_port = htons(8080);
  if (bind(sockfd, (struct sockaddr*)&serverSock, sizeof(serverSock)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  while (1) {
    // Accept a client connection
    newsockfd = accept(sockfd, (struct sockaddr*)&clientSock, NULL);
    if (newsockfd < 0) {
      perror("Error accepting client connection");
      continue;
    }

    // Add the client to the list
    addClient(newsockfd, clientSock.sin_addr.s_addr);

    // Send a welcome message to the client
    write(newsockfd, "Welcome to the server!", 22);

    // Receive a message from the client
    read(newsockfd, buffer, 1024);

    // Print the message to the console
    printf("Client: %s, Message: %s\n", clientSock.sin_addr.s_addr, buffer);

    // Remove the client from the list
    removeClient(newsockfd);

    // Close the client connection
    close(newsockfd);
  }

  return 0;
}