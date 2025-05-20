//FormAI DATASET v1.0 Category: Port Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void usage(char *prog_name) {
  fprintf(stderr, "Usage: %s <IP Address> <Start Port> <End Port>\n", prog_name);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  // Check that we have three command-line arguments
  if (argc != 4) {
    usage(argv[0]);
  }

  char *target_ip = argv[1];
  int start_port = atoi(argv[2]);
  int end_port = atoi(argv[3]);

  // Check that the start and end ports are valid
  if (start_port <= 0 || end_port <= 0 || start_port > 65535 || end_port > 65535 || start_port > end_port) {
    fprintf(stderr, "Invalid port range: %d-%d\n", start_port, end_port);
    exit(EXIT_FAILURE);
  }

  // Create a socket object
  int sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sock_fd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Prepare the target address structure
  struct sockaddr_in target_addr;
  memset(&target_addr, 0, sizeof(target_addr));
  target_addr.sin_family = AF_INET;
  target_addr.sin_addr.s_addr = inet_addr(target_ip);

  // Loop through the port range and attempt to connect to each port
  printf("Scanning ports %d-%d on %s\n", start_port, end_port, target_ip);
  for (int port = start_port; port <= end_port; ++port) {
    target_addr.sin_port = htons(port);

    // Attempt to connect to the target port
    if (connect(sock_fd, (struct sockaddr *)&target_addr, sizeof(target_addr)) != -1) {
      printf("Port %d is open\n", port);
    }
  }

  // Close the socket
  close(sock_fd);

  return EXIT_SUCCESS;
}