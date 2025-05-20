//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <arpa/inet.h>

#define BUF_SIZE 1500

int main(int argc, char **argv) {
  int sockfd, n;
  struct sockaddr_in servaddr;
  char buf[BUF_SIZE];
  struct timeval start, end;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1) {
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

  memset(buf, 'a', BUF_SIZE);
  gettimeofday(&start, NULL);

  for (int i = 0; i < 10000; i++) {
    n = sendto(sockfd, buf, BUF_SIZE, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (n == -1) {
      perror("sendto");
      return EXIT_FAILURE;
    }
    n = recvfrom(sockfd, buf, BUF_SIZE, 0, NULL, NULL);
    if (n == -1) {
      perror("recvfrom");
      return EXIT_FAILURE;
    }
  }

  gettimeofday(&end, NULL);

  printf("Total time: %f\n", (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000.0);

  return EXIT_SUCCESS;
}