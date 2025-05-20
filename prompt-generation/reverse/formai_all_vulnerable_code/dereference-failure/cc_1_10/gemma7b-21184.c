//Gemma-7B DATASET v1.0 Category: Chat server ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

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
  Client* previous = NULL;
  Client* current = head;

  while (current) {
    if (current->sockfd == sockfd) {
      if (previous) {
        previous->next = current->next;
        free(current);
      } else {
        head = current->next;
        free(current);
      }
      return;
    }
    previous = current;
    current = current->next;
  }
}

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in sockAddr;
  Client* clientList = NULL;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
  if (sockfd == -1) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket
  sockAddr.sin_family = AF_INET;
  sockAddr.sin_port = htons(8080);
  if (bind(sockfd, (struct sockaddr*)&sockAddr, sizeof(sockAddr)) == -1) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  while (1) {
    // Accept a client
    newsockfd = accept(sockfd, NULL, NULL);
    if (newsockfd == -1) {
      perror("Error accepting client");
      continue;
    }

    // Add the client to the list
    addClient("Client", newsockfd);

    // Send a welcome message to the client
    write(newsockfd, "Welcome to the dungeon, traveler!", 38);

    // Listen for messages from the client
    char message[200];
    while (1) {
      // Receive a message from the client
      int bytesRead = read(newsockfd, message, 200);
      if (bytesRead == 0) {
        // Client has disconnected, remove from list
        removeClient(newsockfd);
        break;
      }

      // Print the message to the console
      printf("%s: %s\n", clientList->name, message);

      // Send a message back to the client
      write(newsockfd, message, bytesRead);
    }

    // Close the client socket
    close(newsockfd);
  }

  return 0;
}