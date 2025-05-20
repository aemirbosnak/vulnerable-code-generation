//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *hostname = argv[1];
  char *port = argv[2];

  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  struct addrinfo *result;
  int status = getaddrinfo(hostname, port, &hints, &result);
  if (status != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    exit(EXIT_FAILURE);
  }

  int socket_fd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (socket_fd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  if (connect(socket_fd, result->ai_addr, result->ai_addrlen) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";

  if (send(socket_fd, request, strlen(request), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  char buffer[1024];
  int bytes_received = recv(socket_fd, buffer, sizeof(buffer) - 1, 0);
  if (bytes_received == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  buffer[bytes_received] = '\0';

  printf("Received: %s\n", buffer);

  close(socket_fd);

  freeaddrinfo(result);

  return EXIT_SUCCESS;
}