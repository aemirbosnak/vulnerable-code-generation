//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PING_SIZE 64

void ping(const char *ip_address, int count, int timeout) {
  int sockfd, n;
  struct sockaddr_in addr;
  char buffer[PING_SIZE];
  struct timeval tv;

  sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  tv.tv_sec = timeout;
  tv.tv_usec = 0;
  setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(ip_address);

  for (int i = 0; i < count; i++) {
    int seq = i + 1;

    memset(buffer, 0, sizeof(buffer));
    buffer[0] = 0x08;  // ICMP Echo Request
    buffer[1] = 0x00;  // Code
    buffer[2] = 0x00;  // Checksum
    buffer[3] = 0x00;  // Identifier
    *(uint16_t *) (buffer + 4) = htons(seq);  // Sequence number
    for (int j = 8; j < PING_SIZE; j++) {
      buffer[j] = j;
    }

    n = sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *) &addr, sizeof(addr));
    if (n < 0) {
      perror("sendto");
      continue;
    }

    n = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
    if (n < 0) {
      printf("timeout\n");
      continue;
    }

    if (buffer[0] != 0x00 || buffer[1] != 0x00 || buffer[2] != 0x00 || buffer[3] != 0x00) {
      printf("invalid ICMP header\n");
      continue;
    }

    uint16_t seq_received = ntohs(*(uint16_t *) (buffer + 4));
    if (seq_received != seq) {
      printf("invalid sequence number\n");
      continue;
    }

    printf("seq=%d time=%ldms\n", seq, (long) (tv.tv_sec * 1000 + tv.tv_usec / 1000));
  }

  close(sockfd);
}

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Usage: %s <ip_address> <count> <timeout>\n", argv[0]);
    exit(1);
  }

  int count = atoi(argv[2]);
  int timeout = atoi(argv[3]);
  ping(argv[1], count, timeout);

  return 0;
}