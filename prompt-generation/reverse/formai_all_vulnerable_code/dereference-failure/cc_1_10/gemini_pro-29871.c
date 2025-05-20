//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 10

typedef struct {
  char *host;
  int port;
} target_t;

typedef struct {
  int sockfd;
  target_t target;
} thread_data_t;

void *thread_func(void *arg) {
  thread_data_t *data = (thread_data_t *)arg;
  struct sockaddr_in serv_addr;
  int ret;

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(data->target.port);
  serv_addr.sin_addr.s_addr = inet_addr(data->target.host);

  data->sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (data->sockfd == -1) {
    perror("socket");
    pthread_exit(NULL);
  }

  ret = connect(data->sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  if (ret == -1) {
    perror("connect");
    close(data->sockfd);
    pthread_exit(NULL);
  }

  printf("Connected to %s:%d\n", data->target.host, data->target.port);

  close(data->sockfd);
  pthread_exit(NULL);
}

int main(int argc, char **argv) {
  int i;
  pthread_t threads[MAX_THREADS];
  thread_data_t data[MAX_THREADS];

  if (argc < 2) {
    printf("Usage: %s <target1> <target2> ... <targetN>\n", argv[0]);
    return 1;
  }

  for (i = 1; i < argc; i++) {
    char *host, *port;
    host = strtok(argv[i], ":");
    port = strtok(NULL, ":");
    if (host == NULL || port == NULL) {
      printf("Invalid target: %s\n", argv[i]);
      return 1;
    }

    data[i - 1].target.host = host;
    data[i - 1].target.port = atoi(port);
  }

  for (i = 0; i < argc - 1; i++) {
    pthread_create(&threads[i], NULL, thread_func, &data[i]);
  }

  for (i = 0; i < argc - 1; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}