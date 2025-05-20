//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 4096

typedef struct ProxyClient {
  int clientSockfd;
  struct sockaddr_in clientAddr;
  char buffer[MAX_BUFFER_SIZE];
  int bufferSize;
  struct ProxyClient* next;
} ProxyClient;

ProxyClient* insertClient(ProxyClient* head, int sockfd, struct sockaddr_in clientAddr, int bufferSize) {
  ProxyClient* newNode = (ProxyClient*)malloc(sizeof(ProxyClient));
  newNode->clientSockfd = sockfd;
  newNode->clientAddr = clientAddr;
  newNode->bufferSize = bufferSize;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void handleClient(ProxyClient* client) {
  int readBytes = read(client->clientSockfd, client->buffer, client->bufferSize);
  client->bufferSize = readBytes;

  if (readBytes > 0) {
    printf("Client: %s sent %d bytes\n", inet_ntoa(client->clientAddr), readBytes);
  }

  write(client->clientSockfd, client->buffer, client->bufferSize);
  close(client->clientSockfd);
  free(client);
}

int main() {
  int listenSockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
  bind(listenSockfd, NULL, 0);

  ProxyClient* clients = NULL;

  while (1) {
    struct sockaddr_in clientAddr;
    int clientSockfd = accept(listenSockfd, (struct sockaddr*)&clientAddr, NULL);

    insertClient(clients, clientSockfd, clientAddr, MAX_BUFFER_SIZE);

    handleClient(clients);
  }

  return 0;
}