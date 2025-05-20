//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <poll.h>

#define BUFFER_SIZE 16384
#define MAX_CONNECTIONS 10

typedef struct {
  int sockfd;
  char *buffer;
  struct timeval start;
  struct timeval end;
  long long bytes_received;
} connection_t;

void die(char *msg) {
  perror(msg);
  exit(1);
}

void print_usage() {
  printf("Usage: speedtest <host> <port>\n");
  exit(1);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    print_usage();
  }

  char *host = argv[1];
  int port = atoi(argv[2]);

  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  struct addrinfo *result;
  int err = getaddrinfo(host, argv[2], &hints, &result);
  if (err != 0) {
    die("getaddrinfo");
  }

  int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (sockfd == -1) {
    die("socket");
  }

  if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
    die("connect");
  }

  freeaddrinfo(result);

  char *buffer = malloc(BUFFER_SIZE);
  if (buffer == NULL) {
    die("malloc");
  }

  connection_t connections[MAX_CONNECTIONS];
  for (int i = 0; i < MAX_CONNECTIONS; i++) {
    connections[i].sockfd = -1;
    connections[i].buffer = NULL;
    connections[i].bytes_received = 0;
  }

  struct pollfd pfds[MAX_CONNECTIONS + 1];
  pfds[0].fd = sockfd;
  pfds[0].events = POLLIN;

  int max_fd = sockfd;
  int num_connections = 0;
  int running = 1;

  while (running) {
    int nfds = poll(pfds, max_fd + 1, -1);
    if (nfds == -1) {
      die("poll");
    }

    if (pfds[0].revents & POLLIN) {
      int new_sockfd = accept(sockfd, NULL, NULL);
      if (new_sockfd == -1) {
        die("accept");
      }

      if (num_connections >= MAX_CONNECTIONS) {
        close(new_sockfd);
        continue;
      }

      connections[num_connections].sockfd = new_sockfd;
      connections[num_connections].buffer = malloc(BUFFER_SIZE);
      if (connections[num_connections].buffer == NULL) {
        die("malloc");
      }

      gettimeofday(&connections[num_connections].start, NULL);

      pfds[num_connections + 1].fd = new_sockfd;
      pfds[num_connections + 1].events = POLLIN;
      max_fd = fmax(max_fd, new_sockfd);

      num_connections++;
    }

    for (int i = 1; i <= num_connections; i++) {
      if (pfds[i].revents & POLLIN) {
        int nbytes = recv(connections[i - 1].sockfd, connections[i - 1].buffer, BUFFER_SIZE, 0);
        if (nbytes == -1) {
          die("recv");
        } else if (nbytes == 0) {
          gettimeofday(&connections[i - 1].end, NULL);

          long long elapsed_time = (connections[i - 1].end.tv_sec - connections[i - 1].start.tv_sec) * 1000000 +
                                  (connections[i - 1].end.tv_usec - connections[i - 1].start.tv_usec);

          double speed = (double)connections[i - 1].bytes_received / elapsed_time * 8;
          printf("Connection %d: %.2f Mbit/s\n", i, speed * 1e-6);

          close(connections[i - 1].sockfd);
          free(connections[i - 1].buffer);

          connections[i - 1] = connections[num_connections - 1];
          pfds[i + 1] = pfds[num_connections + 1];
          num_connections--;

          if (num_connections == 0) {
            running = 0;
            break;
          }
        } else {
          connections[i - 1].bytes_received += nbytes;
        }
      }
    }
  }

  close(sockfd);
  free(buffer);

  return 0;
}