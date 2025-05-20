//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MAXLINE 8192

int main(int argc, char **argv) {
  int listenfd, connfd;
  struct sockaddr_in servaddr;
  char buf[MAXLINE];
  int n;

  if (argc != 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(1);
  }

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(atoi(argv[1]));

  bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
  listen(listenfd, 10);

  for (;;) {
    connfd = accept(listenfd, (struct sockaddr *)NULL, NULL);
    if (connfd < 0) {
      perror("accept");
      continue;
    }

    while ((n = read(connfd, buf, MAXLINE)) > 0) {
      printf("Received %d bytes\n", n);
      write(connfd, buf, n);
    }

    if (n < 0) {
      perror("read");
    }

    close(connfd);
  }

  close(listenfd);

  return 0;
}