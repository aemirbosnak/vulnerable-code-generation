//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

void ping(char *host, int count) {
  int sockfd;
  struct sockaddr_in servaddr;
  struct timeval start, end;
  int i, n;
  char buf[1024];

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(80);
  if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(1);
  }

  for (i = 0; i < count; i++) {
    gettimeofday(&start, NULL);

    n = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (n < 0) {
      perror("sendto");
      exit(1);
    }

    n = recvfrom(sockfd, buf, sizeof(buf), 0, NULL, NULL);
    if (n < 0) {
      perror("recvfrom");
      exit(1);
    }

    gettimeofday(&end, NULL);

    printf("%d bytes from %s: time=%ld ms\n", n, host, (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000);
  }

  close(sockfd);
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <host> <count>\n", argv[0]);
    exit(1);
  }

  ping(argv[1], atoi(argv[2]));

  return 0;
}