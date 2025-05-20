//Gemma-7B DATASET v1.0 Category: Chat server ; Style: curious
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CLIENTS 10

typedef struct Client {
  char name[256];
  int sockfd;
  struct Client* next;
} Client;

Client* clients = NULL;

void handle_client(int sockfd) {
  Client* client = malloc(sizeof(Client));
  client->sockfd = sockfd;

  // Get client name
  char name[256];
  recv(sockfd, name, 256, 0);
  strcpy(client->name, name);

  // Add client to list
  client->next = clients;
  clients = client;

  // Echo client name back
  send(sockfd, client->name, strlen(client->name), 0);

  // Listen for client messages
  while (1) {
    char message[256];
    recv(sockfd, message, 256, 0);

    // Broadcast message to all clients
    for (Client* currentClient = clients; currentClient; currentClient = currentClient->next) {
      if (currentClient->sockfd != sockfd) {
        send(currentClient->sockfd, message, strlen(message), 0);
      }
    }

    // Check if client has disconnected
    if (strcmp(message, "disconnect") == 0) {
      break;
    }
  }

  // Remove client from list
  Client* previousClient = NULL;
  for (Client* currentClient = clients; currentClient; currentClient = currentClient->next) {
    if (currentClient->sockfd == sockfd) {
      if (previousClient) {
        previousClient->next = currentClient->next;
      } else {
        clients = currentClient->next;
      }
      free(currentClient);
      break;
    }
    previousClient = currentClient;
  }
}

int main() {
  // Listen for clients
  int sockfd, newsockfd;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_len;

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));

  // Bind socket
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

  // Listen for connections
  while (1) {
    // Accept connection
    client_len = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);

    // Handle client
    handle_client(newsockfd);
  }

  return 0;
}