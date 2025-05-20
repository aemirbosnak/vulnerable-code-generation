//Gemma-7B DATASET v1.0 Category: Socket programming ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ChatClient {
  int socketfd;
  char buffer[MAX_BUFFER_SIZE];
  struct ChatClient* next;
} ChatClient;

ChatClient* head = NULL;

void addClient(int socketfd) {
  ChatClient* newNode = malloc(sizeof(ChatClient));
  newNode->socketfd = socketfd;
  newNode->next = head;
  head = newNode;
}

void broadcastMessage(char* message) {
  ChatClient* currentClient = head;
  while (currentClient) {
    send(currentClient->socketfd, message, MAX_BUFFER_SIZE, 0);
  }
}

int main() {
  int serverSocketfd, clientSocketfd;
  struct sockaddr_in serverAddr, clientAddr;
  char message[MAX_BUFFER_SIZE];

  // Create a socket
  serverSocketfd = socket(AF_INET, SOCK_STREAM, htons(65535));

  // Bind the socket to a port
  serverAddr.sin_port = htons(8080);
  bind(serverSocketfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

  // Listen for clients
  while (1) {
    // Accept a client connection
    clientSocketfd = accept(serverSocketfd, (struct sockaddr*)&clientAddr, NULL);

    // Add the client to the list
    addClient(clientSocketfd);

    // Receive a message from the client
    recv(clientSocketfd, message, MAX_BUFFER_SIZE, 0);

    // Broadcast the message to all clients
    broadcastMessage(message);
  }

  return 0;
}