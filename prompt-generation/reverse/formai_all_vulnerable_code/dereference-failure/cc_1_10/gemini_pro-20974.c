//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define MAXLINE 1024

int main(int argc, char **argv) {
  int sockfd, n;
  char recvline[MAXLINE + 1];
  struct sockaddr_in servaddr;

  if (argc != 3) {
    fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    fprintf(stderr, "socket error: %s\n", strerror(errno));
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    fprintf(stderr, "inet_pton error for %s\n", argv[1]);
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    fprintf(stderr, "connect error: %s\n", strerror(errno));
    exit(1);
  }

  while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
    recvline[n] = '\0';
    printf("%s", recvline);
  }

  if (n < 0) {
    fprintf(stderr, "read error: %s\n", strerror(errno));
    exit(1);
  }

  exit(0);
}