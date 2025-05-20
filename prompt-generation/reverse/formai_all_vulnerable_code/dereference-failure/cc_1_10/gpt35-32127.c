//FormAI DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void scan_ports(const char *ip_addr, int start_port, int end_port) {
  struct sockaddr_in target_addr;
  int sockfd, status, port;

  memset(&target_addr, 0, sizeof target_addr);
  target_addr.sin_family = AF_INET;

  if (inet_pton(AF_INET, ip_addr, &target_addr.sin_addr) == 0) {
    printf("Error: invalid IP address\n");
    exit(EXIT_FAILURE);
  }

  for (port = start_port; port <= end_port; port++) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
      printf("Error: failed to create socket\n");
      close(sockfd);
      continue;
    }

    target_addr.sin_port = htons(port);
    status = connect(sockfd, (struct sockaddr *)&target_addr, sizeof target_addr);
    if (status == 0) {
      printf("Port %d is open\n", port);
    } else {
      printf("Port %d is closed\n", port);
    }

    close(sockfd);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <ip_addr> <start_port> <end_port>\n", argv[0]);
    exit(EXIT_SUCCESS);
  }

  char *ip_addr = argv[1];
  int start_port = atoi(argv[2]);
  int end_port = atoi(argv[3]);

  if (start_port < 1 || start_port > 65535 || end_port < 1 || end_port > 65535 || start_port > end_port) {
    printf("Error: invalid port range\n");
    exit(EXIT_FAILURE);
  }

  scan_ports(ip_addr, start_port, end_port);

  return 0;
}