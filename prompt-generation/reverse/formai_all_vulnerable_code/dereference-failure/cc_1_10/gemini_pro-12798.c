//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>
#include <sys/types.h>

#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>

#define MAX_SIZE (50 * 1024 * 1024)
#define MAX_TRIES 10

#define PORT 80

int main(int argc, char *argv[]) {
  struct hostent *he;
  struct sockaddr_in server;
  struct timeval start, end;
  int sockfd, i, j, bytes_recv, total_bytes_recv, total_time;
  char *buffer;

  if (argc != 2) {
    printf("Usage: %s <hostname>\n", argv[0]);
    exit(1);
  }

  if ((he = gethostbyname(argv[1])) == NULL) {
    perror("gethostbyname");
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr = *((struct in_addr *)he->h_addr);

  if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("connect");
    exit(1);
  }

  buffer = malloc(MAX_SIZE);
  if (buffer == NULL) {
    perror("malloc");
    exit(1);
  }

  total_bytes_recv = 0;
  total_time = 0;

  for (i = 0; i < MAX_TRIES; i++) {
    bytes_recv = 0;
    gettimeofday(&start, NULL);

    while (bytes_recv < MAX_SIZE) {
      j = recv(sockfd, buffer + bytes_recv, MAX_SIZE - bytes_recv, 0);
      if (j < 0) {
        perror("recv");
        exit(1);
      }
      bytes_recv += j;
    }

    gettimeofday(&end, NULL);

    total_bytes_recv += bytes_recv;
    total_time += (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
  }

  double avg_speed = total_bytes_recv * 8.0 / (total_time / 1000.0);
  printf("Average speed: %.2f Mbps\n", avg_speed);

  close(sockfd);
  free(buffer);

  return 0;
}