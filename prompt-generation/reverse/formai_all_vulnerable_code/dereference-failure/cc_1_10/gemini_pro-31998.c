//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_TRIES 5
#define TIMEOUT 1000 // milliseconds

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
    return EXIT_FAILURE;
  }

  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    herror("gethostbyname");
    return EXIT_FAILURE;
  }

  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = ((struct in_addr *)(host->h_addr))->s_addr;
  addr.sin_port = htons(33434);

  int tries = 0;
  int success = 0;
  long long total_time = 0;
  while (tries++ < MAX_TRIES) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    if (sendto(sockfd, "ping", 4, 0, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
      perror("sendto");
      continue;
    }

    struct sockaddr_in recvaddr;
    socklen_t recvaddrlen = sizeof(recvaddr);
    int bytes = recvfrom(sockfd, NULL, 0, MSG_DONTWAIT, (struct sockaddr *)&recvaddr, &recvaddrlen);
    if (bytes != -1 && memcmp(&addr, &recvaddr, sizeof(addr)) == 0) {
      clock_gettime(CLOCK_MONOTONIC, &end);
      long long time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
      total_time += time;
      success++;
      printf("Reply from %s: time=%lld ms\n", inet_ntoa(recvaddr.sin_addr), time);
    } else {
      usleep(100000);
    }
  }

  close(sockfd);

  printf("Total %d tries, %d successes, average time=%lld ms\n", tries, success, total_time / success);

  return EXIT_SUCCESS;
}