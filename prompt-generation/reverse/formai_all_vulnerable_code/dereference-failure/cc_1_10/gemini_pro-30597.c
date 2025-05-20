//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: paranoid
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static const int PORT = 12345;
static const int MAX_PENDING = 5;
static const int MAX_EVENTS = 10;

static int server_fd = -1;
static int epoll_fd = -1;
static struct epoll_event *events;

static void sigchld_handler(int signum) {
  while (waitpid(-1, NULL, WNOHANG) > 0) {}
}

static void error(const char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

static int create_server_socket(unsigned short port) {
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd < 0) error("socket");

  int optval = 1;
  if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) < 0) error("setsockopt");

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(port);

  if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) error("bind");

  if (listen(fd, MAX_PENDING) < 0) error("listen");

  return fd;
}

static int create_epoll_fd(int server_fd) {
  int fd = epoll_create1(0);
  if (fd < 0) error("epoll_create1");

  struct epoll_event event;
  memset(&event, 0, sizeof(event));
  event.events = EPOLLIN;
  event.data.fd = server_fd;

  if (epoll_ctl(fd, EPOLL_CTL_ADD, server_fd, &event) < 0) error("epoll_ctl");

  return fd;
}

static void handle_client(int client_fd) {
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));

  ssize_t bytes_read = recv(client_fd, buffer, sizeof(buffer), 0);
  if (bytes_read < 0) error("recv");

  if (bytes_read == 0) {
    printf("Client closed connection\n");
    close(client_fd);
    return;
  }

  printf("Received from client: %s\n", buffer);

  char *response = "Hello, world!\n";
  ssize_t bytes_sent = send(client_fd, response, strlen(response), 0);
  if (bytes_sent < 0) error("send");

  printf("Sent to client: %s\n", response);

  close(client_fd);
}

static void main_loop() {
  while (1) {
    int nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
    if (nfds < 0) error("epoll_wait");

    for (int i = 0; i < nfds; ++i) {
      if (events[i].data.fd == server_fd) {
        struct sockaddr_in addr;
        socklen_t addrlen = sizeof(addr);
        int client_fd = accept(server_fd, (struct sockaddr *)&addr, &addrlen);
        if (client_fd < 0) error("accept");

        printf("Accepted connection from %s:%d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));

        struct epoll_event event;
        memset(&event, 0, sizeof(event));
        event.events = EPOLLIN;
        event.data.fd = client_fd;

        if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &event) < 0) error("epoll_ctl");
      } else {
        handle_client(events[i].data.fd);
      }
    }
  }
}

int main(void) {
  signal(SIGCHLD, sigchld_handler);

  server_fd = create_server_socket(PORT);
  epoll_fd = create_epoll_fd(server_fd);
  events = calloc(MAX_EVENTS, sizeof(struct epoll_event));

  main_loop();

  close(server_fd);
  close(epoll_fd);
  free(events);

  return EXIT_SUCCESS;
}