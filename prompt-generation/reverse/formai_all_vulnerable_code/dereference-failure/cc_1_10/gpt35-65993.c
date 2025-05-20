//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#include <pthread.h>

#define MAX_PORT 65535
#define THREAD_NUM 50

int open_port(int port) {
  int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sock < 0) {
    return -1;
  }
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(port);
  if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    close(sock);
    return -1;
  }
  return sock;
}

void *scan_port(void *arg) {
  int port = *((int *)arg);
  int sock = -1;
  if ((sock = open_port(port)) >= 0) {
    printf("Port %d open\n", port);
    close(sock);
  }
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("Usage: %s [IP addr]\n", argv[0]);
    return 1;
  }
  char *ip = argv[1];
  printf("Scanning %s...\n", ip);

  // Set up async threads to scan ports
  pthread_t threads[THREAD_NUM];
  for (int i = 0; i < THREAD_NUM; i++) {
    int *port = malloc(sizeof(int));
    *port = i * MAX_PORT / THREAD_NUM;
    pthread_create(&threads[i], NULL, scan_port, port);
  }
  for (int i = 0; i < THREAD_NUM; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("Done scanning %s\n", ip);
  return 0;
}