//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

typedef struct ClientConnection {
  int socketfd;
  char buffer[MAX_BUFFER_SIZE];
  struct ClientConnection* next;
} ClientConnection;

ClientConnection* head = NULL;

void handleClientConnection(int sockfd) {
  ClientConnection* newClient = malloc(sizeof(ClientConnection));
  newClient->socketfd = sockfd;

  // Receive client message
  int bytesRead = recv(sockfd, newClient->buffer, MAX_BUFFER_SIZE, 0);
  if (bytesRead > 0) {
    // Process client message
    printf("Client: %s\n", newClient->buffer);

    // Send server response
    char serverResponse[] = "Hello, client!";
    send(sockfd, serverResponse, strlen(serverResponse), 0);
  }

  // Add client to linked list
  newClient->next = head;
  head = newClient;

  // Close client socket
  close(sockfd);
}

int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  struct sockaddr_in serverAddr;
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(8080);
  bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

  // Listen for client connections
  while (1) {
    // Accept client connection
    int clientSockfd = accept(sockfd, NULL, NULL);
    if (clientSockfd > 0) {
      handleClientConnection(clientSockfd);
    }
  }

  return 0;
}