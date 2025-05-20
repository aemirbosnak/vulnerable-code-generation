//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 5

typedef struct Client {
  int sockfd;
  char name[20];
} Client;

Client clients[MAX_CLIENTS];

void handle_client(int sockfd) {
  Client *client = &clients[sockfd];

  // Receive client message
  char message[200];
  recv(sockfd, message, 200, 0);

  // Print client message
  printf("Client: %s, Message: %s\n", client->name, message);

  // Send server message
  char server_message[100] = "Server: Hello, client!";
  send(sockfd, server_message, 100, 0);

  // Close client connection
  close(sockfd);
}

int main() {
  int sockfd, client_sockfd;
  struct sockaddr_in server_addr, client_addr;
  int clients_count = 0;

  // Bind socket to port
  sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
  if (sockfd < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  while (1) {
    // Get client connection
    client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (client_sockfd < 0) {
      perror("Error accepting client connection");
      continue;
    }

    // Increment clients count
    clients_count++;

    // Create client structure
    Client *client = &clients[clients_count - 1];
    client->sockfd = client_sockfd;
    client->name[0] = '\0';

    // Handle client
    handle_client(client_sockfd);
  }

  return 0;
}