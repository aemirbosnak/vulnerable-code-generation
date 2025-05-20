//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
    return 1;
  }

  struct addrinfo hints, *result;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  int status = getaddrinfo(argv[1], argv[2], &hints, &result);
  if (status != 0) {
    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
    return 1;
  }

  int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
    perror("connect");
    return 1;
  }

  freeaddrinfo(result);

  char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
  send(sockfd, request, strlen(request), 0);

  char buffer[4096];
  int n;
  while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
    write(1, buffer, n);
  }

  if (n == -1) {
    perror("recv");
    return 1;
  }

  close(sockfd);

  return 0;
}