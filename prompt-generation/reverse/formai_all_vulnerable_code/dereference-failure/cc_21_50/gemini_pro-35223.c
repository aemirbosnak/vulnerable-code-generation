//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define POP3_PORT "110"

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
    return EXIT_FAILURE;
  }

  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  struct addrinfo *result;
  if (getaddrinfo(argv[1], POP3_PORT, &hints, &result) != 0) {
    perror("getaddrinfo");
    return EXIT_FAILURE;
  }

  int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  freeaddrinfo(result);

  char buf[1024];
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  printf("%s", buf);

  snprintf(buf, sizeof(buf), "USER %s\r\n", argv[2]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  printf("%s", buf);

  snprintf(buf, sizeof(buf), "PASS %s\r\n", argv[3]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  printf("%s", buf);

  snprintf(buf, sizeof(buf), "STAT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  printf("%s", buf);

  snprintf(buf, sizeof(buf), "LIST\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  while (1) {
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
      perror("recv");
      return EXIT_FAILURE;
    }

    printf("%s", buf);

    if (strcmp(buf, ".\r\n") == 0) {
      break;
    }
  }

  snprintf(buf, sizeof(buf), "RETR 1\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  while (1) {
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
      perror("recv");
      return EXIT_FAILURE;
    }

    printf("%s", buf);

    if (strcmp(buf, ".\r\n") == 0) {
      break;
    }
  }

  snprintf(buf, sizeof(buf), "QUIT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  close(sockfd);

  return EXIT_SUCCESS;
}