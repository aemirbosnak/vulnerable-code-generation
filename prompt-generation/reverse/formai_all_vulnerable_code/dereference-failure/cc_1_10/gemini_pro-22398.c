//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_CONNECTIONS 10

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return 1;
  }

  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if (getaddrinfo(argv[1], argv[2], &hints, &res) != 0) {
    perror("getaddrinfo");
    return 1;
  }

  int sockets[MAX_CONNECTIONS];

  for (int i = 0; i < MAX_CONNECTIONS; i++) {
    sockets[i] = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (sockets[i] == -1) {
      perror("socket");
      return 1;
    }

    if (connect(sockets[i], res->ai_addr, res->ai_addrlen) == -1) {
      perror("connect");
      return 1;
    }
  }

  freeaddrinfo(res);

  for (int i = 0; i < MAX_CONNECTIONS; i++) {
    close(sockets[i]);
  }

  return 0;
}