//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int sockfd;
  struct sockaddr_in servaddr;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  memset(&servaddr, 0, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));

  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    return EXIT_FAILURE;
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  char buf[BUF_SIZE];
  int n, total = 0;
  struct timeval start, end;

  gettimeofday(&start, NULL);

  while ((n = read(sockfd, buf, BUF_SIZE)) > 0) {
    total += n;
  }

  gettimeofday(&end, NULL);

  if (n < 0) {
    perror("read");
    return EXIT_FAILURE;
  }

  double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
  double speed = (total / elapsed) * 8 / 1024 / 1024;

  printf("Download speed: %.2f Mbps\n", speed);

  close(sockfd);

  return EXIT_SUCCESS;
}