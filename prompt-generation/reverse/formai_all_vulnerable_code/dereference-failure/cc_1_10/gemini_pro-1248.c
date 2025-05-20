//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
  int listenfd, connfd;
  struct sockaddr_in servaddr;
  char buf[BUFSIZE];
  int n;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if (listenfd < 0) {
    perror("socket");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(atoi(argv[1]));

  if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind");
    exit(1);
  }

  if (listen(listenfd, 10) < 0) {
    perror("listen");
    exit(1);
  }

  for (;;) {
    connfd = accept(listenfd, (struct sockaddr *)NULL, NULL);
    if (connfd < 0) {
      perror("accept");
      continue;
    }

    while ((n = read(connfd, buf, BUFSIZE)) > 0) {
      if (write(connfd, buf, n) < 0) {
        perror("write");
        break;
      }
    }

    if (n < 0) {
      perror("read");
    }

    close(connfd);
  }

  close(listenfd);
  return 0;
}