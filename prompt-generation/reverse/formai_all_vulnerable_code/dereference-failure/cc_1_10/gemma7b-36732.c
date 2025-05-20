//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 4096

#define LISTEN_PORT 8080

typedef struct ClientConnection {
  int clientSocketfd;
  struct ClientConnection* next;
} ClientConnection;

ClientConnection* head = NULL;

void handleClientConnection(int clientSocketfd) {
  ClientConnection* newClientConnection = malloc(sizeof(ClientConnection));
  newClientConnection->clientSocketfd = clientSocketfd;
  newClientConnection->next = head;
  head = newClientConnection;

  char buffer[MAX_BUFFER_SIZE];
  int bytesRead = read(clientSocketfd, buffer, MAX_BUFFER_SIZE);
  if (bytesRead > 0) {
    printf("Client: %s sent: %s\n", inet_ntoa((struct sockaddr_in*)head->clientSocketfd), buffer);
  }

  close(clientSocketfd);
}

int main() {
  int listenSocketfd = socket(AF_INET, SOCK_STREAM, htons(LISTEN_PORT));
  if (listenSocketfd == -1) {
    perror("Error creating listen socket");
    exit(1);
  }

  bind(listenSocketfd, (struct sockaddr_in*)NULL, 0);

  while (1) {
    int clientSocketfd = accept(listenSocketfd, NULL, NULL);
    if (clientSocketfd == -1) {
      perror("Error accepting client connection");
      continue;
    }

    handleClientConnection(clientSocketfd);
  }

  return 0;
}