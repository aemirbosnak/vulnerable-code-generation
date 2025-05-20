//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024
#define PROXY_PORT 8080

struct addrinfo *server;
int server_socket;

void error(const char *msg) {
  perror(msg);
  exit(1);
}

void *thread_func(void *arg) {
  int client_socket = *(int *) arg;

  char buffer[MAX_LINE];
  while (fgets(buffer, MAX_LINE, stdin)) {
    send(client_socket, buffer, strlen(buffer), 0);
  }

  close(client_socket);
  return NULL;
}

int main(int argc, char **argv) {
  if (argc!= 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return 1;
  }

  int proxy_port = atoi(argv[1]);

  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  struct addrinfo *result;
  int gai_err;

  gai_err = getaddrinfo("localhost", NULL, &hints, &result);
  if (gai_err!= 0) {
    error("getaddrinfo");
  }

  server = result;
  server_socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (server_socket == -1) {
    error("socket");
  }

  if (connect(server_socket, result->ai_addr, result->ai_addrlen) == -1) {
    error("connect");
  }

  freeaddrinfo(result);

  while (1) {
    int client_socket = accept(server_socket, NULL, NULL);
    if (client_socket == -1) {
      error("accept");
    }

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_func, (void *) &client_socket);
  }

  return 0;
}