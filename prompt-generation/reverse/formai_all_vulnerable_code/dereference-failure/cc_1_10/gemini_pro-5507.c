//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Usage: %s <target IP> <start port> <end port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *target_ip = argv[1];
  int start_port = atoi(argv[2]);
  int end_port = atoi(argv[3]);

  if (start_port > end_port) {
    printf("Invalid port range: %d-%d\n", start_port, end_port);
    return EXIT_FAILURE;
  }

  if (start_port < 1 || start_port > MAX_PORTS) {
    printf("Invalid start port: %d\n", start_port);
    return EXIT_FAILURE;
  }

  if (end_port < 1 || end_port > MAX_PORTS) {
    printf("Invalid end port: %d\n", end_port);
    return EXIT_FAILURE;
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in target_addr;
  memset(&target_addr, 0, sizeof(target_addr));
  target_addr.sin_family = AF_INET;
  target_addr.sin_addr.s_addr = inet_addr(target_ip);

  for (int port = start_port; port <= end_port; port++) {
    target_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
      printf("Port %d: open\n", port);
    } else {
      printf("Port %d: closed\n", port);
    }
  }

  close(sockfd);
  return EXIT_SUCCESS;
}