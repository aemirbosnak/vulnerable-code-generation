//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <server> <port> <message>\n", argv[0]);
    exit(1);
  }

  char *server = argv[1];
  int port = atoi(argv[2]);
  char *message = argv[3];

  int sockfd, n;
  struct sockaddr_in servaddr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  if (inet_pton(AF_INET, server, &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    exit(1);
  }

  n = write(sockfd, message, strlen(message));
  if (n < 0) {
    perror("write");
    exit(1);
  }

  close(sockfd);
  return 0;
}