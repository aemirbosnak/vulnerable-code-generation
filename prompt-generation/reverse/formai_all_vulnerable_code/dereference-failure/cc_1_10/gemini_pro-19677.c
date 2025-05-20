//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

typedef struct {
  char *host;
  int port;
  int timeout;
  int interval;
  int count;
  int success;
  int failure;
} monitor_t;

int monitor_init(monitor_t *m, char *host, int port, int timeout, int interval, int count) {
  m->host = strdup(host);
  m->port = port;
  m->timeout = timeout;
  m->interval = interval;
  m->count = count;
  m->success = 0;
  m->failure = 0;
  return 0;
}

int monitor_close(monitor_t *m) {
  free(m->host);
  return 0;
}

int monitor_run(monitor_t *m) {
  int sockfd;
  struct sockaddr_in addr;
  int ret;

  for (int i = 0; i < m->count; i++) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
      perror("socket");
      return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(m->port);
    addr.sin_addr.s_addr = inet_addr(m->host);

    ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0) {
      perror("connect");
      m->failure++;
    } else {
      m->success++;
      close(sockfd);
    }

    sleep(m->interval);
  }

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 7) {
    fprintf(stderr, "Usage: %s <host> <port> <timeout> <interval> <count>\n", argv[0]);
    return -1;
  }

  monitor_t m;
  int ret;

  ret = monitor_init(&m, argv[1], atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));
  if (ret < 0) {
    fprintf(stderr, "Error initializing monitor\n");
    return -1;
  }

  ret = monitor_run(&m);
  if (ret < 0) {
    fprintf(stderr, "Error running monitor\n");
    return -1;
  }

  monitor_close(&m);

  printf("Success: %d\n", m.success);
  printf("Failure: %d\n", m.failure);

  return 0;
}