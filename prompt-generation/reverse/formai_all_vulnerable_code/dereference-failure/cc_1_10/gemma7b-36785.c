//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ClientConnection {
  int clientFd;
  char* clientIp;
  struct ClientConnection* next;
} ClientConnection;

ClientConnection* insertClientConnection(ClientConnection* head, int clientFd, char* clientIp) {
  ClientConnection* newNode = malloc(sizeof(ClientConnection));
  newNode->clientFd = clientFd;
  newNode->clientIp = strdup(clientIp);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }

  return head;
}

void handleClientConnection(ClientConnection* clientConn) {
  char buffer[MAX_BUFFER_SIZE];
  int readBytes = read(clientConn->clientFd, buffer, MAX_BUFFER_SIZE);

  if (readBytes > 0) {
    printf("Client: %s, Message: %s\n", clientConn->clientIp, buffer);
  }

  close(clientConn->clientFd);
  free(clientConn);
}

int main() {
  int serverFd = socket(AF_INET, SOCK_STREAM, htons(8080));
  bind(serverFd, NULL, 0);

  ClientConnection* clients = NULL;

  while (1) {
    int clientFd = accept(serverFd, NULL, NULL);
    char clientIp[256];
    getpeername(clientFd, clientIp, NULL);

    insertClientConnection(clients, clientFd, clientIp);

    handleClientConnection(clients);
  }

  return 0;
}