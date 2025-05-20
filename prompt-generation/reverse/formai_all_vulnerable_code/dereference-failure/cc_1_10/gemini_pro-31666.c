//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
  int sockfd, n, i;
  struct timeval start, end;
  double elapsed;
  char buf[BUFSIZE];

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));

  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  //  MEASURE UPLOAD
  for (i = 0; i < 1000; i++)
    send(sockfd, buf, i % BUFSIZE, 0);

  // MEASURE DOWNLOAD
  int sum = 0;
  gettimeofday(&start, NULL);
  for (i = 0; i < 100000; i++)
    sum += read(sockfd, buf, i % BUFSIZE);

  gettimeofday(&end, NULL);
  close(sockfd);

  elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
  printf("Time taken: %.3f seconds\n", elapsed);

  double bytes_transferred = sum;
  double mbps = (bytes_transferred / 1024.0 / 1024.0) / elapsed;
  printf("Speed: %.3f Mbps\n", mbps);

  return 0;
}