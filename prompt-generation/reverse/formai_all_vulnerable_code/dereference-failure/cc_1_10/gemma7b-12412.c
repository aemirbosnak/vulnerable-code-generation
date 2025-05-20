//Gemma-7B DATASET v1.0 Category: Chat server ; Style: visionary
#include <stdio.h>
#include <string.h>
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

  while (temp) {
    if (temp->sockfd == sockfd) {
      if (prev) {
        prev->next = temp->next;
      } else {
        head = temp->next;
      }
      free(temp);
      return;
    }
    prev = temp;
    temp = temp->next;
  }
}

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in serverSockaddr, clientSockaddr;
  char buffer[1024];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));

  // Bind the socket to a port
  serverSockaddr.sin_port = htons(8080);
  bind(sockfd, (struct sockaddr*)&serverSockaddr, sizeof(serverSockaddr));

  // Listen for clients
  while (1) {
    // Accept a client connection
    newsockfd = accept(sockfd, (struct sockaddr*)&clientSockaddr, NULL);

    // Add the client to the list
    addClient(clientSockaddr.sin_addr.s_addr, newsockfd);

    // Send a welcome message to the client
    sprintf(buffer, "Welcome to the Chat Server, %s!", clientSockaddr.sin_addr.s_addr);
    send(newsockfd, buffer, strlen(buffer), 0);

    // Listen for messages from the client
    while (1) {
      // Receive a message from the client
      recv(newsockfd, buffer, 1024, 0);

      // Broadcast the message to the other clients
      for (Client* client = head; client; client = client->next) {
        if (client->sockfd != newsockfd) {
          send(client->sockfd, buffer, strlen(buffer), 0);
        }
      }

      // Check if the client has disconnected
      if (strcmp(buffer, "disconnect") == 0) {
        removeClient(newsockfd);
        break;
      }
    }

    // Close the client connection
    close(newsockfd);
  }

  return 0;
}