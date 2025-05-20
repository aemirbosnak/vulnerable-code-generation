//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
  int sockfd;
  struct sockaddr_in addr;
  char *buffer;
  size_t buffer_len;
} client_t;

int main() {
  int listenfd, connfd;
  struct sockaddr_in servaddr;

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if (listenfd < 0) {
    perror("socket");
    return 1;
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(PORT);

  if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind");
    return 1;
  }

  if (listen(listenfd, MAX_CLIENTS) < 0) {
    perror("listen");
    return 1;
  }

  client_t clients[MAX_CLIENTS];

  while (1) {
    connfd = accept(listenfd, (struct sockaddr *)NULL, NULL);
    if (connfd < 0) {
      perror("accept");
      continue;
    }

    int flags = fcntl(connfd, F_GETFL, 0);
    fcntl(connfd, F_SETFL, flags | O_NONBLOCK);

    client_t *client = &clients[connfd];
    client->sockfd = connfd;
    client->buffer = malloc(BUFFER_SIZE);
    client->buffer_len = 0;

    printf("New client connected: %d\n", connfd);
  }

  return 0;
}