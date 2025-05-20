//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_HOSTS 1000

typedef struct {
  char *hostname;
  int port;
} host_t;

typedef struct {
  int sockfd;
  host_t *hosts;
  int num_hosts;
} thread_data_t;

void *thread_main(void *arg) {
  thread_data_t *data = (thread_data_t *)arg;
  int sockfd = data->sockfd;
  host_t *hosts = data->hosts;
  int num_hosts = data->num_hosts;

  for (int i = 0; i < num_hosts; i++) {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(hosts[i].port);
    addr.sin_addr.s_addr = inet_addr(hosts[i].hostname);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
      perror("connect");
      continue;
    }

    printf("Connected to %s:%d\n", hosts[i].hostname, hosts[i].port);

    close(sockfd);
  }

  free(data);
  return NULL;
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  char *hostname = argv[1];
  int port = atoi(argv[2]);

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(hostname);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    exit(1);
  }

  printf("Connected to %s:%d\n", hostname, port);

  char buffer[1024];
  int n;

  while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
    printf("%s", buffer);
  }

  if (n == -1) {
    perror("read");
  }

  close(sockfd);

  return 0;
}