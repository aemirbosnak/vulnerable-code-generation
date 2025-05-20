//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>

#define PORT 5001
#define MAX_MSG_LEN 1024

int main(int argc, char **argv) {
  int sockfd, n, i, j, k;
  struct sockaddr_in servaddr;
  char sendline[MAX_MSG_LEN], recvline[MAX_MSG_LEN];
  struct timeval start, end;
  double rtt, avg_rtt = 0.0;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server IP> <num pings>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  if (inet_aton(argv[1], &servaddr.sin_addr) == 0) {
    fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  // Ping loop
  for (i = 0; i < atoi(argv[2]); i++) {
    // Send ping
    sprintf(sendline, "PING %d", i);
    gettimeofday(&start, NULL);
    n = sendto(sockfd, sendline, strlen(sendline), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (n < 0) {
      perror("sendto");
      exit(EXIT_FAILURE);
    }

    // Receive pong
    n = recvfrom(sockfd, recvline, MAX_MSG_LEN, 0, NULL, NULL);
    if (n < 0) {
      perror("recvfrom");
      exit(EXIT_FAILURE);
    }

    // Check response
    if (strncmp(recvline, "PONG", 4) != 0) {
      fprintf(stderr, "Invalid response: %s\n", recvline);
      exit(EXIT_FAILURE);
    }

    // Calculate RTT
    gettimeofday(&end, NULL);
    rtt = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
    printf("PING %d: %.3f ms\n", i, rtt);

    // Update average RTT
    avg_rtt += rtt;
  }

  // Calculate average RTT
  avg_rtt /= atoi(argv[2]);
  printf("Average RTT: %.3f ms\n", avg_rtt);

  close(sockfd);
  return 0;
}