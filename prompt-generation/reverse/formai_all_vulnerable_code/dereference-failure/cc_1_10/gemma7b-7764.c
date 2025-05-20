//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ProxyData {
  char **buffer;
  int bufferSize;
  int readPos;
  int writePos;
  int connectionfd;
  struct ProxyData *next;
} ProxyData;

ProxyData *proxyHead = NULL;

void addProxyData(int connectionfd) {
  ProxyData *newNode = malloc(sizeof(ProxyData));
  newNode->buffer = NULL;
  newNode->bufferSize = MAX_BUFFER_SIZE;
  newNode->readPos = 0;
  newNode->writePos = 0;
  newNode->connectionfd = connectionfd;
  newNode->next = NULL;

  if (proxyHead == NULL) {
    proxyHead = newNode;
  } else {
    ProxyData *traversal = proxyHead;
    while (traversal->next) {
      traversal = traversal->next;
    }
    traversal->next = newNode;
  }
}

int main() {
  int listenfd, connectionfd;
  struct sockaddr_in serverSock, clientSock;
  char buffer[MAX_BUFFER_SIZE];

  listenfd = socket(AF_INET, SOCK_STREAM, htons(8080));
  serverSock.sin_family = AF_INET;
  serverSock.sin_port = htons(8080);
  serverSock.sin_addr.s_addr = htonl(INADDR_ANY);

  bind(listenfd, (struct sockaddr *)&serverSock, sizeof(serverSock));

  while (1) {
    connectionfd = accept(listenfd, (struct sockaddr *)&clientSock, NULL);
    addProxyData(connectionfd);
  }

  return 0;
}