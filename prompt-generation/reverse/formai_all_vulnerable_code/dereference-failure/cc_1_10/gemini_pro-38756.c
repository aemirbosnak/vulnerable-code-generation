//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

const int PORT = 80;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s <ip-address>\n", argv[0]);
    exit(1);
  }

  struct timeval timeout;
  timeout.tv_sec = 1;
  timeout.tv_usec = 0;

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    exit(1);
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  if (inet_pton(AF_INET, argv[1], &addr.sin_addr) != 1) {
    perror("inet_pton");
    exit(1);
  }

  if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
    perror("setsockopt");
    exit(1);
  }
  if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout)) < 0) {
    perror("setsockopt");
    exit(1);
  }

  int res = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
  if (res < 0) {
    if (errno == ETIMEDOUT) {
      printf("Host %s is not reachable.\n", argv[1]);
    } else {
      perror("connect");
    }
    exit(1);
  }

  printf("Host %s is reachable.\n", argv[1]);
  close(sock);
  return 0;
}