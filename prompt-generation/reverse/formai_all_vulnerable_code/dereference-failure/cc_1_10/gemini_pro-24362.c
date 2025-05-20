//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  struct addrinfo hints, *result;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  int status = getaddrinfo(argv[1], argv[2], &hints, &result);
  if (status != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
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

  char buffer[1024];
  while (1) {
    memset(buffer, 0, sizeof(buffer));
    printf("> ");
    fgets(buffer, sizeof(buffer), stdin);

    if (strcmp(buffer, "quit\n") == 0) {
      break;
    }

    int len = strlen(buffer);
    if (send(sockfd, buffer, len, 0) == -1) {
      perror("send");
      break;
    }

    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
      perror("recv");
      break;
    }

    printf("%s", buffer);
  }

  close(sockfd);

  return EXIT_SUCCESS;
}