//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 4096

typedef struct ProxyContext {
  int clientSocketFd;
  int serverSocketFd;
  char buffer[MAX_BUFFER_SIZE];
  struct ProxyContext* next;
} ProxyContext;

ProxyContext* proxyHead = NULL;

void addProxyContext(int clientSocketFd, int serverSocketFd) {
  ProxyContext* newContext = malloc(sizeof(ProxyContext));
  newContext->clientSocketFd = clientSocketFd;
  newContext->serverSocketFd = serverSocketFd;
  newContext->next = proxyHead;
  proxyHead = newContext;
}

void handleProxyRequest() {
  ProxyContext* currentContext = proxyHead;
  while (currentContext) {
    int clientReadBytes = read(currentContext->clientSocketFd, currentContext->buffer, MAX_BUFFER_SIZE);
    int serverWriteBytes = write(currentContext->serverSocketFd, currentContext->buffer, clientReadBytes);
    if (serverWriteBytes < 0) {
      perror("Error writing to server");
    }
    currentContext = currentContext->next;
  }
}

int main() {
  int listenSocketFd = socket(AF_INET, SOCK_STREAM, htons(8080));
  bind(listenSocketFd, NULL, 0);

  while (1) {
    int clientSocketFd = accept(listenSocketFd, NULL, NULL);
    int serverSocketFd = socket(AF_INET, SOCK_STREAM, htons(8080));

    addProxyContext(clientSocketFd, serverSocketFd);

    handleProxyRequest();

    close(clientSocketFd);
    close(serverSocketFd);
  }

  return 0;
}