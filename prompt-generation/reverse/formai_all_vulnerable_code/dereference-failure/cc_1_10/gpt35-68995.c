//FormAI DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define PING_TIMEOUT 1

typedef struct packet {
  struct timeval send_time;
} packet;

typedef struct ping_result {
  char* address;
  int time;
} ping_result;

double timeval_diff(struct timeval x , struct timeval y) {
  return (double)(y.tv_sec - x.tv_sec) + (double)(y.tv_usec - x.tv_usec) / 1000000;
}

void print_ping_result(ping_result* result) {
  printf("%s: ", result->address);

  if (result->time == -1) {
    printf("Timeout\n");
  } else {
    printf("%.2fms\n", (double)result->time);
  }
}

ping_result* ping(char* address) {
  int sock = socket(AF_INET , SOCK_RAW , IPPROTO_ICMP);

  if (sock < 0) {
    perror("socket");
    return NULL;
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(address);

  packet pkt;
  memset(&pkt, 0, sizeof(pkt));
  pkt.send_time.tv_sec = time(NULL);

  if (sendto(sock, &pkt, sizeof(pkt), 0, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
    perror("sendto");
    close(sock);
    return NULL;
  }

  char buf[3000];
  socklen_t addr_len = sizeof(addr);
  struct timeval timeout;
  memset(&timeout, 0, sizeof(timeout));
  timeout.tv_sec = PING_TIMEOUT;
  fd_set fds;

  do {
    FD_ZERO(&fds);
    FD_SET(sock, &fds);
  } while (select(sock + 1, &fds, NULL, NULL, &timeout) == 0);

  if (recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr*)&addr, &addr_len) < 0) {
    perror("recvfrom");
    close(sock);
    return NULL;
  }

  pkt.send_time = ((packet*)buf)->send_time;
  pkt.send_time.tv_sec = ntohl(pkt.send_time.tv_sec);
  pkt.send_time.tv_usec = ntohl(pkt.send_time.tv_usec);

  struct timeval now;
  gettimeofday(&now, NULL);

  ping_result* result = malloc(sizeof(ping_result));
  result->address = address;

  if (timeval_diff(pkt.send_time, now) < PING_TIMEOUT) {
    result->time = (int)(timeval_diff(pkt.send_time, now) * 1000);
  } else {
    result->time = -1;
  }

  close(sock);

  return result;
}

int main(int argc, char** argv) {
  ping_result* results[argc - 1];

  for (int i = 1; i < argc; i++) {
    results[i - 1] = ping(argv[i]);
  }

  for (int i = 0; i < argc - 1; i++) {
    print_ping_result(results[i]);
  }

  return 0;
}