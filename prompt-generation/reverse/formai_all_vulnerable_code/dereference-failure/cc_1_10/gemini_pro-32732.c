//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
  if (argc != 3) {
    fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *hostname = argv[1];
  char *port = argv[2];

  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  struct addrinfo *result;
  int status = getaddrinfo(hostname, port, &hints, &result);
  if (status != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    return EXIT_FAILURE;
  }

  int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (sockfd == -1) {
    perror("socket");
    freeaddrinfo(result);
    return EXIT_FAILURE;
  }

  if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
    perror("connect");
    freeaddrinfo(result);
    close(sockfd);
    return EXIT_FAILURE;
  }

  freeaddrinfo(result);

  char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  char buffer[4096];
  int bytes_received;
  while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
    printf("%s", buffer);
  }

  if (bytes_received == -1) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }

  close(sockfd);

  return EXIT_SUCCESS;
}