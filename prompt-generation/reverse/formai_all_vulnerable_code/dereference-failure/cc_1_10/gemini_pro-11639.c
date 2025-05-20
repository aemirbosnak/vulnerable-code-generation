//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: speedtest <hostname>\n");
    return 1;
  }

  char *hostname = argv[1];

  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    fprintf(stderr, "Could not resolve hostname %s\n", hostname);
    return 1;
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr = *(struct in_addr *)*host->h_addr_list;
  addr.sin_port = htons(80);

  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    return 1;
  }

  char buf[BUFSIZE];
  memset(buf, 'A', BUFSIZE);

  clock_t start_time = clock();

  int bytes_sent = 0;
  while (bytes_sent < BUFSIZE) {
    int n = send(sock, buf + bytes_sent, BUFSIZE - bytes_sent, 0);
    if (n < 0) {
      perror("send");
      return 1;
    }
    bytes_sent += n;
  }

  clock_t end_time = clock();

  double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  double speed = bytes_sent / elapsed_time;

  printf("Speed: %.2f bytes/s\n", speed);

  close(sock);

  return 0;
}