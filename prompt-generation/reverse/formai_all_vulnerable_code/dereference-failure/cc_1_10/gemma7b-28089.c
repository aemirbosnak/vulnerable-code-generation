//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ProxyClient {
  char *hostname;
  int port;
  struct ProxyClient *next;
} ProxyClient;

void addClient(ProxyClient **head, char *hostname, int port) {
  ProxyClient *newClient = malloc(sizeof(ProxyClient));
  newClient->hostname = strdup(hostname);
  newClient->port = port;
  newClient->next = NULL;

  if (*head == NULL) {
    *head = newClient;
  } else {
    (*head)->next = newClient;
  }
}

int main() {
  ProxyClient *clients = NULL;
  addClient(&clients, "localhost", 8080);
  addClient(&clients, "192.168.1.10", 8080);

  char buffer[MAX_BUFFER_SIZE];
  int clientSocketFD, serverSocketFD, bytesRead, bytesWritten;
  struct sockaddr_in clientSockAddr, serverSockAddr;

  serverSocketFD = socket(AF_INET, SOCK_STREAM, htons(8080));
  bind(serverSocketFD, (struct sockaddr *)&serverSockAddr, sizeof(serverSockAddr));

  while (1) {
    clientSocketFD = accept(serverSocketFD, (struct sockaddr *)&clientSockAddr, NULL);

    bytesRead = recv(clientSocketFD, buffer, MAX_BUFFER_SIZE, 0);

    for (ProxyClient *client = clients; client; client = client->next) {
      if (strcmp(client->hostname, clientSockAddr.sin_addr.s_addr) == 0) {
        bytesWritten = send(clientSocketFD, buffer, bytesRead, 0);
      }
    }

    close(clientSocketFD);
  }

  return 0;
}