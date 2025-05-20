//Gemma-7B DATASET v1.0 Category: Chat server ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

#define MAX_CLIENTS 10

typedef struct Client {
  char name[256];
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
    Client *tail = head;
    while (tail->next) {
      tail = tail->next;
    }
    tail->next = newClient;
  }
}

void removeClient(int sockfd) {
  Client *prevClient = NULL;
  Client *currentClient = head;

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
  return;
}

int main() {
  int sockfd, newsockfd, clientfd, portnum = 8888;
  char buffer[1024];
  struct sockaddr_in serv_addr, client_addr;
  int numbytes;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portnum);
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  while (1) {
    // Accept a client connection
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (newsockfd < 0) {
      perror("Error accepting client connection");
      continue;
    }

    // Add the client to the list
    addClient("Unknown", newsockfd);

    // Receive the client's message
    numbytes = recv(newsockfd, buffer, 1024, 0);
    if (numbytes > 0) {
      // Print the client's message
      printf("%s: %s\n", buffer);
    }

    // Remove the client from the list
    removeClient(newsockfd);

    // Close the client connection
    close(newsockfd);
  }

  return 0;
}