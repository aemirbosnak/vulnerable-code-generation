//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <server IP> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int sockfd;
  struct sockaddr_in servaddr;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    return EXIT_FAILURE;
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  char buffer[4096];
  while (1) {
    memset(buffer, 0, sizeof(buffer));
    printf("> ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
      break;
    }

    if (strncmp(buffer, "quit", 4) == 0) {
      break;
    }

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
      perror("send");
      return EXIT_FAILURE;
    }

    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
      perror("recv");
      return EXIT_FAILURE;
    }

    printf("%s", buffer);
  }

  close(sockfd);
  return EXIT_SUCCESS;
}