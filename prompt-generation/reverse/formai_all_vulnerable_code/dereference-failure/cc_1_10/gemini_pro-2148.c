//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024
#define MAX_TIMEOUT 1000

struct ping_packet {
  uint16_t seq;
  uint16_t checksum;
  char data[MAX_PACKET_SIZE];
};

uint16_t calculate_checksum(uint16_t *data, int len) {
  uint32_t sum = 0;
  while (len > 1) {
    sum += *data++;
    len -= 2;
  }
  if (len == 1) {
    sum += *(uint8_t *)data;
  }
  while (sum >> 16) {
    sum = (sum & 0xffff) + (sum >> 16);
  }
  return ~sum;
}

int send_ping(int sockfd, struct sockaddr_in *addr, int seq) {
  struct ping_packet packet;
  packet.seq = seq;
  packet.checksum = calculate_checksum((uint16_t *)&packet, sizeof(packet));
  if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)addr, sizeof(*addr)) < 0) {
    return -1;
  }
  return 0;
}

int recv_ping(int sockfd, struct sockaddr_in *addr, int *seq, int timeout) {
  struct timeval tv;
  tv.tv_sec = timeout / 1000;
  tv.tv_usec = (timeout % 1000) * 1000;
  fd_set readfds;
  FD_ZERO(&readfds);
  FD_SET(sockfd, &readfds);
  if (select(sockfd + 1, &readfds, NULL, NULL, &tv) <= 0) {
    return -1;
  }
  struct ping_packet packet;
  socklen_t addr_len = sizeof(*addr);
  if (recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)addr, &addr_len) < 0) {
    return -1;
  }
  if (packet.checksum != calculate_checksum((uint16_t *)&packet, sizeof(packet))) {
    return -1;
  }
  *seq = packet.seq;
  return 0;
}

int ping(const char *host, int count, int timeout) {
  struct sockaddr_in addr;
  if (inet_pton(AF_INET, host, &addr.sin_addr) <= 0) {
    return -1;
  }
  addr.sin_family = AF_INET;
  addr.sin_port = htons(33434);
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    return -1;
  }
  int seq = 0;
  struct timespec start, end;
  double elapsed;
  for (int i = 0; i < count; i++) {
    if (send_ping(sockfd, &addr, seq) < 0) {
      close(sockfd);
      return -1;
    }
    clock_gettime(CLOCK_MONOTONIC, &start);
    if (recv_ping(sockfd, &addr, &seq, timeout) < 0) {
      close(sockfd);
      return -1;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;
    printf("Reply from %s: seq=%d time=%f ms\n", host, seq, elapsed);
    seq++;
  }
  close(sockfd);
  return 0;
}

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: %s <host> <count> [timeout]\n", argv[0]);
    return 1;
  }
  int count = atoi(argv[2]);
  int timeout = MAX_TIMEOUT;
  if (argc >= 4) {
    timeout = atoi(argv[3]);
  }
  if (ping(argv[1], count, timeout) < 0) {
    perror("ping");
    return 1;
  }
  return 0;
}