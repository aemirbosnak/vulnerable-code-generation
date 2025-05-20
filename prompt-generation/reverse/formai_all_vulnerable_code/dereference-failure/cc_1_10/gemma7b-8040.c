//Gemma-7B DATASET v1.0 Category: Building a HTTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ClientState {
  int socketfd;
  char buffer[MAX_BUFFER_SIZE];
  struct ClientState *next;
} ClientState;

ClientState *head = NULL;

void connectToHost(char *hostname, int port) {
  ClientState *newState = malloc(sizeof(ClientState));
  memset(newState, 0, sizeof(ClientState));

  struct sockaddr_in sockAddr;
  sockAddr.sin_family = AF_INET;
  sockAddr.sin_port = htons(port);
  sockAddr.sin_addr.s_addr = inet_addr(hostname);

  newState->socketfd = socket(AF_INET, SOCK_STREAM, htons(port));
  connect(newState->socketfd, (struct sockaddr *)&sockAddr, sizeof(sockAddr));

  newState->next = head;
  head = newState;
}

void sendHttpRequest(char *method, char *path, char *data) {
  ClientState *currentState = head;

  while (currentState) {
    if (currentState->socketfd != -1) {
      char message[MAX_BUFFER_SIZE];
      sprintf(message, "%s %s %s\r\n", method, path, data);

      send(currentState->socketfd, message, strlen(message), 0);

      break;
    }
    currentState = currentState->next;
  }

  if (currentState == NULL) {
    printf("Error: No active connections.\n");
  }
}

int main() {
  connectToHost("localhost", 8080);
  sendHttpRequest("GET", "/users", NULL);
  sendHttpRequest("POST", "/users", "John Doe");
  sendHttpRequest("PUT", "/users/1", "Jane Doe");
  sendHttpRequest("DELETE", "/users/1", NULL);

  return 0;
}