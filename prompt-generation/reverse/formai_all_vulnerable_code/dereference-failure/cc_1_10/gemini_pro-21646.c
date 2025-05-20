//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>

#define MAX_PORTS 65535
#define MAX_HOST_LEN 1024

struct port_scanner_options {
  char *host;
  int start_port;
  int end_port;
  int timeout;
};

static void print_help(const char *program_name) {
  printf("Usage: %s <host> <start_port> <end_port> [timeout]\n", program_name);
  printf("Example: %s google.com 1 1000\n", program_name);
}

static int parse_args(int argc, char **argv, struct port_scanner_options *options) {
  if (argc < 4) {
    print_help(argv[0]);
    return -1;
  }

  options->host = argv[1];
  options->start_port = atoi(argv[2]);
  options->end_port = atoi(argv[3]);
  if (argc >= 5) {
    options->timeout = atoi(argv[4]);
  } else {
    options->timeout = 1;
  }

  return 0;
}

static int create_socket(struct port_scanner_options *options) {
  struct sockaddr_in addr;
  int sockfd;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(options->start_port);
  addr.sin_addr.s_addr = inet_addr(options->host);

  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    close(sockfd);
    return -1;
  }

  return sockfd;
}

static int scan_ports(struct port_scanner_options *options) {
  int sockfd, i;
  struct sockaddr_in addr;
  socklen_t addrlen;

  addrlen = sizeof(addr);

  for (i = options->start_port; i <= options->end_port; i++) {
    sockfd = create_socket(options);
    if (sockfd == -1) {
      continue;
    }

    addr.sin_port = htons(i);
    if (connect(sockfd, (struct sockaddr *)&addr, addrlen) == 0) {
      printf("Port %d is open\n", i);
    }

    close(sockfd);
  }

  return 0;
}

int main(int argc, char **argv) {
  struct port_scanner_options options;

  if (parse_args(argc, argv, &options) == -1) {
    return -1;
  }

  scan_ports(&options);

  return 0;
}