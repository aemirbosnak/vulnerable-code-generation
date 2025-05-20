//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define MAX_THREADS 10
#define MAX_HOSTS 1000
#define MAX_PORTS 100

typedef struct {
  uint32_t ip_addr;
  uint16_t port;
  int status;
} host_t;

pthread_t threads[MAX_THREADS];
host_t hosts[MAX_HOSTS];
int num_hosts = 0;

void *worker_thread(void *arg) {
  int i;
  for (i = 0; i < num_hosts; i++) {
    if (hosts[i].status == -1) {
      int sockfd = socket(AF_INET, SOCK_STREAM, 0);
      if (sockfd < 0) {
        perror("socket");
        continue;
      }

      struct sockaddr_in addr;
      memset(&addr, 0, sizeof(addr));
      addr.sin_family = AF_INET;
      addr.sin_addr.s_addr = hosts[i].ip_addr;
      addr.sin_port = htons(hosts[i].port);

      if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        close(sockfd);
        hosts[i].status = 0;
        continue;
      }

      hosts[i].status = 1;
      close(sockfd);
    }
  }

  return NULL;
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <ip_address> <port>\n", argv[0]);
    return 1;
  }

  uint32_t ip_addr = inet_addr(argv[1]);
  uint16_t port = atoi(argv[2]);

  hosts[num_hosts].ip_addr = ip_addr;
  hosts[num_hosts].port = port;
  hosts[num_hosts].status = -1;
  num_hosts++;

  int i;
  for (i = 0; i < MAX_THREADS; i++) {
    if (pthread_create(&threads[i], NULL, worker_thread, NULL) != 0) {
      perror("pthread_create");
      exit(1);
    }
  }

  for (i = 0; i < MAX_THREADS; i++) {
    if (pthread_join(threads[i], NULL) != 0) {
      perror("pthread_join");
      exit(1);
    }
  }

  for (i = 0; i < num_hosts; i++) {
    if (hosts[i].status == 1) {
      printf("%s:%d is up\n", inet_ntoa((struct in_addr) { hosts[i].ip_addr }), hosts[i].port);
    } else {
      printf("%s:%d is down\n", inet_ntoa((struct in_addr) { hosts[i].ip_addr }), hosts[i].port);
    }
  }

  return 0;
}