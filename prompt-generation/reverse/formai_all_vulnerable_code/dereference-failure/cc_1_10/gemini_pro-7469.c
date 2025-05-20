//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_CONNECTIONS 1000

struct connection {
  int sockfd;
  struct sockaddr_in addr;
  time_t last_activity;
};

struct connection connections[MAX_CONNECTIONS];
int num_connections = 0;

void handle_new_connection(int listenfd) {
  struct sockaddr_in addr;
  socklen_t addrlen = sizeof(addr);
  int sockfd = accept(listenfd, (struct sockaddr *)&addr, &addrlen);
  if (sockfd < 0) {
    perror("accept");
    return;
  }

  // Set the socket to non-blocking mode.
  int flags = fcntl(sockfd, F_GETFL, 0);
  if (flags < 0) {
    perror("fcntl");
    return;
  }
  flags |= O_NONBLOCK;
  if (fcntl(sockfd, F_SETFL, flags) < 0) {
    perror("fcntl");
    return;
  }

  // Add the new connection to the list of connections.
  connections[num_connections].sockfd = sockfd;
  connections[num_connections].addr = addr;
  connections[num_connections].last_activity = time(NULL);
  num_connections++;
}

void handle_data(int sockfd) {
  char buffer[1024];
  int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received < 0) {
    perror("recv");
    return;
  }

  // Process the data.

  // Send a response.
  send(sockfd, buffer, bytes_received, 0);
}

void handle_timeout() {
  time_t now = time(NULL);
  for (int i = 0; i < num_connections; i++) {
    if (now - connections[i].last_activity > 60) {
      // Close the connection.
      close(connections[i].sockfd);

      // Remove the connection from the list of connections.
      for (int j = i; j < num_connections - 1; j++) {
        connections[j] = connections[j + 1];
      }
      num_connections--;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return 1;
  }

  int port = atoi(argv[1]);

  // Create a listening socket.
  int listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if (listenfd < 0) {
    perror("socket");
    return 1;
  }

  // Set the socket to non-blocking mode.
  int flags = fcntl(listenfd, F_GETFL, 0);
  if (flags < 0) {
    perror("fcntl");
    return 1;
  }
  flags |= O_NONBLOCK;
  if (fcntl(listenfd, F_SETFL, flags) < 0) {
    perror("fcntl");
    return 1;
  }

  // Bind the socket to the specified port.
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(listenfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
    return 1;
  }

  // Start listening for connections.
  if (listen(listenfd, 10) < 0) {
    perror("listen");
    return 1;
  }

  // Set up the signal handler.
  struct sigaction sa;
  memset(&sa, 0, sizeof(sa));
  sa.sa_handler = handle_timeout;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_RESTART;
  if (sigaction(SIGALRM, &sa, NULL) < 0) {
    perror("sigaction");
    return 1;
  }

  // Set up the alarm.
  alarm(60);

  // Main loop.
  while (1) {
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(listenfd, &readfds);
    for (int i = 0; i < num_connections; i++) {
      FD_SET(connections[i].sockfd, &readfds);
    }

    int num_ready = select(FD_SETSIZE, &readfds, NULL, NULL, NULL);
    if (num_ready < 0) {
      perror("select");
      return 1;
    }

    if (FD_ISSET(listenfd, &readfds)) {
      handle_new_connection(listenfd);
    }

    for (int i = 0; i < num_connections; i++) {
      if (FD_ISSET(connections[i].sockfd, &readfds)) {
        handle_data(connections[i].sockfd);
      }
    }
  }

  return 0;
}