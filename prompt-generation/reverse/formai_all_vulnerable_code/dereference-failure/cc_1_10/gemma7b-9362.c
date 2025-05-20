//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ProxySession {
  int clientFd;
  int serverFd;
  char buffer[MAX_BUFFER_SIZE];
  struct ProxySession* next;
} ProxySession;

ProxySession* proxy_session_head = NULL;

void add_proxy_session(int clientFd, int serverFd) {
  ProxySession* new_session = malloc(sizeof(ProxySession));
  new_session->clientFd = clientFd;
  new_session->serverFd = serverFd;
  new_session->next = proxy_session_head;
  proxy_session_head = new_session;
}

void handle_proxy_session(ProxySession* session) {
  int bytes_read = read(session->clientFd, session->buffer, MAX_BUFFER_SIZE);
  if (bytes_read > 0) {
    write(session->serverFd, session->buffer, bytes_read);
  } else if (bytes_read == 0) {
    close(session->clientFd);
    close(session->serverFd);
    free(session);
  }
}

int main() {
  int serverFd = listen(8080, 10);
  if (serverFd == -1) {
    perror("Error listening on port");
    return 1;
  }

  while (1) {
    int clientFd = accept(serverFd, NULL, NULL);
    if (clientFd == -1) {
      perror("Error accepting connection");
      continue;
    }

    add_proxy_session(clientFd, serverFd);

    handle_proxy_session(proxy_session_head);
  }

  return 0;
}