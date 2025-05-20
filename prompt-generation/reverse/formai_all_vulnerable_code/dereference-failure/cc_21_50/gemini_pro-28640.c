//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFERSIZE 1024

typedef struct {
  int fd;
  struct sockaddr_in addr;
  char buf[BUFFERSIZE];
  int buflen;
  int state;
} client;

int main(int argc, char **argv) {
  int listenfd, connfd;
  struct sockaddr_in servaddr;
  fd_set readset, writeset;
  client clients[FD_SETSIZE];

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if (listenfd == -1) {
    perror("socket");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(atoi(argv[1]));

  if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("bind");
    exit(1);
  }

  if (listen(listenfd, 5) == -1) {
    perror("listen");
    exit(1);
  }

  FD_ZERO(&readset);
  FD_ZERO(&writeset);

  while (1) {
    FD_SET(listenfd, &readset);

    for (int i = 0; i < FD_SETSIZE; i++) {
      if (clients[i].fd != -1) {
        FD_SET(clients[i].fd, &readset);
        if (clients[i].state == 1) {
          FD_SET(clients[i].fd, &writeset);
        }
      }
    }

    if (select(FD_SETSIZE, &readset, &writeset, NULL, NULL) == -1) {
      perror("select");
      exit(1);
    }

    if (FD_ISSET(listenfd, &readset)) {
      connfd = accept(listenfd, NULL, NULL);
      if (connfd == -1) {
        perror("accept");
        exit(1);
      }

      for (int i = 0; i < FD_SETSIZE; i++) {
        if (clients[i].fd == -1) {
          clients[i].fd = connfd;
          clients[i].state = 0;
          break;
        }
      }
    }

    for (int i = 0; i < FD_SETSIZE; i++) {
      if (clients[i].fd != -1 && FD_ISSET(clients[i].fd, &readset)) {
        clients[i].buflen = read(clients[i].fd, clients[i].buf, BUFFERSIZE);
        if (clients[i].buflen == 0) {
          close(clients[i].fd);
          clients[i].fd = -1;
        } else if (clients[i].buflen == -1) {
          perror("read");
          exit(1);
        } else {
          clients[i].state = 1;
        }
      }

      if (clients[i].fd != -1 && FD_ISSET(clients[i].fd, &writeset)) {
        if (write(clients[i].fd, clients[i].buf, clients[i].buflen) == -1) {
          perror("write");
          exit(1);
        }

        clients[i].state = 0;
      }
    }
  }

  return 0;
}