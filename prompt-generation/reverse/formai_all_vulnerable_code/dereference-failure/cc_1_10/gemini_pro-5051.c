//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_EVENTS 1024

struct epoll_event events[MAX_EVENTS];
int epoll_fd;

void add_event(int fd, int events) {
  struct epoll_event event;
  event.data.fd = fd;
  event.events = events;
  if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event) == -1) {
    perror("epoll_ctl");
    exit(1);
  }
}

void modify_event(int fd, int events) {
  struct epoll_event event;
  event.data.fd = fd;
  event.events = events;
  if (epoll_ctl(epoll_fd, EPOLL_CTL_MOD, fd, &event) == -1) {
    perror("epoll_ctl");
    exit(1);
  }
}

void del_event(int fd) {
  if (epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, NULL) == -1) {
    perror("epoll_ctl");
    exit(1);
  }
}

int main(int argc, char *argv[]) {
  int listen_fd;
  struct sockaddr_in addr;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  listen_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_fd == -1) {
    perror("socket");
    exit(1);
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(argv[1]));
  addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(listen_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    exit(1);
  }

  if (listen(listen_fd, 5) == -1) {
    perror("listen");
    exit(1);
  }

  epoll_fd = epoll_create1(0);
  if (epoll_fd == -1) {
    perror("epoll_create1");
    exit(1);
  }

  add_event(listen_fd, EPOLLIN | EPOLLET);

  while (1) {
    int nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
    if (nfds == -1) {
      perror("epoll_wait");
      exit(1);
    }

    for (int i = 0; i < nfds; i++) {
      int fd = events[i].data.fd;

      if (fd == listen_fd) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
          perror("accept");
          continue;
        }

        add_event(client_fd, EPOLLIN | EPOLLET);
      } else {
        char buffer[1024];
        int nbytes = read(fd, buffer, sizeof(buffer));
        if (nbytes == -1) {
          perror("read");
          del_event(fd);
          close(fd);
          continue;
        } else if (nbytes == 0) {
          del_event(fd);
          close(fd);
          continue;
        }

        // Parse the log line here

        write(fd, "OK\n", 3);
      }
    }
  }

  return 0;
}