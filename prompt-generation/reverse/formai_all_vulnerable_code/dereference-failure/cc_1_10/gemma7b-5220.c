//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ClientInfo {
  char hostname[256];
  int port;
  struct ClientInfo* next;
} ClientInfo;

ClientInfo* insertClient(ClientInfo* head, char* hostname, int port) {
  ClientInfo* newNode = malloc(sizeof(ClientInfo));
  strcpy(newNode->hostname, hostname);
  newNode->port = port;
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  ClientInfo* current = head;
  while (current->next) {
    current = current->next;
  }

  current->next = newNode;
  return head;
}

void proxyHandler(ClientInfo* head) {
  int clientSocketFd, serverSocketFd, numBytesRead, numBytesWritten;
  char buffer[MAX_BUFFER_SIZE];
  struct sockaddr_in clientAddr, serverAddr;

  clientSocketFd = accept(serverSocketFd, (struct sockaddr*)&clientAddr, NULL);

  printf("Client connected: %s:%d\n", clientAddr.sin_addr.s_addr, clientAddr.sin_port);

  ClientInfo* client = insertClient(head, inet_ntoa(clientAddr.sin_addr), clientAddr.sin_port);

  while (numBytesRead = read(clientSocketFd, buffer, MAX_BUFFER_SIZE) > 0) {
    numBytesWritten = write(serverSocketFd, buffer, numBytesRead);
  }

  close(clientSocketFd);
  close(serverSocketFd);
  printf("Client disconnected: %s:%d\n", client->hostname, client->port);
}

int main() {
  ClientInfo* head = NULL;
  int serverSocketFd;

  // Create a socket for listening
  serverSocketFd = socket(AF_INET, SOCK_STREAM, htons(80));
  if (serverSocketFd < 0) {
    perror("Error creating socket");
    return 1;
  }

  // Bind the socket to a port
  if (bind(serverSocketFd, NULL, 0) < 0) {
    perror("Error binding socket");
    return 1;
  }

  // Listen for clients
  while (1) {
    proxyHandler(head);
  }

  return 0;
}