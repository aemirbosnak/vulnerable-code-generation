//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535
#define MAX_HOSTNAME_LENGTH 256

void print_usage() {
  printf("Usage: portscanner <hostname> [port range start] [port range end]\n");
  printf("Example: portscanner example.com 1000 2000\n");
}

int main(int argc, char *argv[]) {
  if (argc < 2 || argc > 4) {
    print_usage();
    return EXIT_FAILURE;
  }

  char *hostname = argv[1];
  int port_range_start = PORT_RANGE_START;
  int port_range_end = PORT_RANGE_END;

  if (argc >= 3) {
    port_range_start = atoi(argv[2]);
  }

  if (argc == 4) {
    port_range_end = atoi(argv[3]);
  }

  if (port_range_start < PORT_RANGE_START || port_range_start > port_range_end || port_range_end > PORT_RANGE_END) {
    printf("Invalid port range. Port range must be between %d and %d.\n", PORT_RANGE_START, PORT_RANGE_END);
    return EXIT_FAILURE;
  }

  struct sockaddr_in sa;
  sa.sin_family = AF_INET;
  sa.sin_port = htons(port_range_start);
  inet_pton(AF_INET, hostname, &sa.sin_addr);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  int result;
  for (int port = port_range_start; port <= port_range_end; port++) {
    sa.sin_port = htons(port);

    result = connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
    if (result == 0) {
      printf("Port %d is open\n", port);
    } else {
      printf("Port %d is closed\n", port);
    }
  }

  close(sockfd);
  return EXIT_SUCCESS;
}