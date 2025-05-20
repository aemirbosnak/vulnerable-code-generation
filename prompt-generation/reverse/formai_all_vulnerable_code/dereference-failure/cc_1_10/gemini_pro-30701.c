//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <signal.h>

#define MAX_PORT 65535

struct sockaddr_in target;

void usage(char *prog) {
  fprintf(stderr, "Usage: %s <hostname> <port> [<port> ...]\n", prog);
}

void error(char *msg) {
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}

void *scan_thread(void *arg) {
  int port = *(int *)arg;
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    error("Failed to create socket");
  }
  if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
    printf("Port %d: open\n", port);
  } else {
    printf("Port %d: closed\n", port);
  }
  close(sock);
  return NULL;
}

int main(int argc, char **argv) {
  if (argc < 3) {
    usage(argv[0]);
    return 1;
  }
  char *hostname = argv[1];
  int start_port = atoi(argv[2]);
  int end_port = argc > 3 ? atoi(argv[3]) : MAX_PORT;
  if (start_port < 0 || end_port > MAX_PORT || start_port > end_port) {
    error("Invalid port range");
  }
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    error("Failed to resolve hostname");
  }
  target.sin_family = AF_INET;
  target.sin_port = htons(start_port);
  target.sin_addr = **(struct in_addr **)host->h_addr_list;
  pthread_t threads[end_port - start_port + 1];
  int ports[end_port - start_port + 1];
  for (int i = 0; i <= end_port - start_port; i++) {
    ports[i] = start_port + i;
    int rc = pthread_create(&threads[i], NULL, scan_thread, &ports[i]);
    if (rc) {
      error("Failed to create thread");
    }
  }
  for (int i = 0; i <= end_port - start_port; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}