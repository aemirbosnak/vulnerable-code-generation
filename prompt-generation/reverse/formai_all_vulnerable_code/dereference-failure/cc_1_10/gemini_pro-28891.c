//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <pthread.h>

#define PORT 80
#define BUFFER_SIZE 1024

typedef struct {
  char *hostname;
  int port;
} target_t;

typedef struct {
  int sockfd;
  target_t *target;
} thread_args_t;

void *scanner_thread(void *args) {
  thread_args_t *targs = (thread_args_t *)args;

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(targs->target->port);
  addr.sin_addr.s_addr = inet_addr(targs->target->hostname);

  if (connect(targs->sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
    printf("Target %s:%d is alive\n", targs->target->hostname, targs->target->port);
  } else {
    printf("Target %s:%d is not alive\n", targs->target->hostname, targs->target->port);
  }

  close(targs->sockfd);
  free(targs->target->hostname);
  free(targs->target);
  free(targs);

  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <hostname> [<hostname> ...]\n", argv[0]);
    return 1;
  }

  int num_targets = argc - 1;
  target_t *targets = malloc(sizeof(target_t) * num_targets);

  for (int i = 1; i < argc; i++) {
    targets[i - 1].hostname = strdup(argv[i]);
    targets[i - 1].port = PORT;
  }

  int num_threads = 10;
  pthread_t threads[num_threads];

  for (int i = 0; i < num_threads; i++) {
    thread_args_t *targs = malloc(sizeof(thread_args_t));
    targs->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    targs->target = &targets[i % num_targets];

    pthread_create(&threads[i], NULL, scanner_thread, targs);
  }

  for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }

  free(targets);

  return 0;
}