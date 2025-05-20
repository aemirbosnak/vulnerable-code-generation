//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <time.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
  int sockfd, n;
  struct sockaddr_in servaddr;
  char buf[BUF_SIZE];
  struct timeval start, end;
  double elapsed;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(argv[1]);
  servaddr.sin_port = htons(atoi(argv[2]));

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    exit(1);
  }

  gettimeofday(&start, NULL);

  for (int i = 0; i < BUF_SIZE; i++) {
    buf[i] = rand() % 256;
  }

  if (send(sockfd, buf, BUF_SIZE, 0) == -1) {
    perror("send");
    exit(1);
  }

  if ((n = recv(sockfd, buf, BUF_SIZE, 0)) == -1) {
    perror("recv");
    exit(1);
  }

  gettimeofday(&end, NULL);

  elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

  printf("Round trip time: %.6f seconds\n", elapsed);

  close(sockfd);

  return 0;
}