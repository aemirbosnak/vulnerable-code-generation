//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <url>\n", argv[0]);
    return 0;
  }

  char *url = argv[1];
  char *host = strtok(url, "/");
  char *path = strtok(NULL, "");

  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  if (getaddrinfo(host, "http", &hints, &res) != 0) {
    perror("getaddrinfo");
    return 1;
  }

  int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  if (connect(sockfd, res->ai_addr, res->ai_addrlen) != 0) {
    perror("connect");
    return 1;
  }

  char request[1000];
  sprintf(request, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, host);

  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("send");
    return 1;
  }

  char response[1024];
  if (recv(sockfd, response, 1024, 0) == -1) {
    perror("recv");
    return 1;
  }

  printf("%s", response);

  close(sockfd);

  return 0;
}