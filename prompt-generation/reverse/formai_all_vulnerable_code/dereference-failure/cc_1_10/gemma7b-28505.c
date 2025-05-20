//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ProxyClient {
  char hostname[256];
  int port;
  int sockfd;
  struct ProxyClient* next;
} ProxyClient;

ProxyClient* proxyClientHead = NULL;

void addProxyClient(char* hostname, int port) {
  ProxyClient* newClient = malloc(sizeof(ProxyClient));
  strcpy(newClient->hostname, hostname);
  newClient->port = port;
  newClient->sockfd = -1;
  newClient->next = NULL;

  if (proxyClientHead == NULL) {
    proxyClientHead = newClient;
  } else {
    proxyClientHead->next = newClient;
  }
}

int main() {
  addProxyClient("localhost", 8080);
  addProxyClient("localhost", 8081);

  int sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
  bind(sockfd, NULL, 0);

  char buffer[MAX_BUFFER_SIZE];
  int clientfd;

  while (1) {
    clientfd = accept(sockfd, NULL, NULL);

    ProxyClient* client = proxyClientHead;

    while (client) {
      if (client->sockfd == -1) {
        client->sockfd = clientfd;
        break;
      }

      client = client->next;
    }

    if (client) {
      printf("Client connected: %s:%d\n", client->hostname, client->port);
      send(clientfd, "Hello, world!", 13, 0);
    } else {
      printf("No available proxy clients.\n");
      close(clientfd);
    }
  }

  return 0;
}