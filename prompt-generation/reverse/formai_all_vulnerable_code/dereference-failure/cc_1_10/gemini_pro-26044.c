//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

//  Ada Lovelace style includes.
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define BUFSIZE 1024

//  Ada Lovelace style socket function.
int socket_connect(const char *host, int port) {
  struct addrinfo hints, *res;
  int sockfd;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  getaddrinfo(host, NULL, &hints, &res);

  sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
    perror("connect");
    return -1;
  }

  freeaddrinfo(res);
  return sockfd;
}

//  Ada Lovelace style proxy function.
void proxy(int client_sockfd, int server_sockfd) {
  char buf[BUFSIZE];
  int n;

  while ((n = read(client_sockfd, buf, BUFSIZE)) > 0) {
    write(server_sockfd, buf, n);
  }

  if (n < 0) {
    perror("read");
  }
}

int main(int argc, char **argv) {
  int client_sockfd, server_sockfd;
  int client_port, server_port;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <client_port> <server_port>\n", argv[0]);
    return 1;
  }

  client_port = atoi(argv[1]);
  server_port = atoi(argv[2]);

  client_sockfd = socket_connect("localhost", client_port);
  if (client_sockfd < 0) {
    return 1;
  }

  server_sockfd = socket_connect("localhost", server_port);
  if (server_sockfd < 0) {
    return 1;
  }

  proxy(client_sockfd, server_sockfd);

  close(client_sockfd);
  close(server_sockfd);

  return 0;
}