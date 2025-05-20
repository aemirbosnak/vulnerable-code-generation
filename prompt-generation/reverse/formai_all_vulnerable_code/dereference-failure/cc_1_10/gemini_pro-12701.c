//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 100
#define MAX_HOSTS 100

// Function to check if a port is open on a host
int port_is_open(char *host, int port) {
  int sockfd;
  struct sockaddr_in addr;
  int ret;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error creating socket");
    return -1;
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(host);

  ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  if (ret == -1) {
    if (errno == ECONNREFUSED) {
      close(sockfd);
      return 0;
    } else {
      perror("Error connecting to host");
      close(sockfd);
      return -1;
    }
  } else {
    close(sockfd);
    return 1;
  }
}

// Function to scan a range of ports on a host
int port_scan(char *host, int start_port, int end_port) {
  int i;
  int open_ports = 0;

  for (i = start_port; i <= end_port; i++) {
    if (port_is_open(host, i)) {
      printf("Port %d is open on host %s\n", i, host);
      open_ports++;
    }
  }

  return open_ports;
}

int main(int argc, char **argv) {
  char *host;
  int start_port;
  int end_port;
  int open_ports;

  if (argc < 4) {
    printf("Usage: %s <host> <start_port> <end_port>\n", argv[0]);
    return 1;
  }

  host = argv[1];
  start_port = atoi(argv[2]);
  end_port = atoi(argv[3]);

  open_ports = port_scan(host, start_port, end_port);

  printf("Found %d open ports on host %s\n", open_ports, host);

  return 0;
}