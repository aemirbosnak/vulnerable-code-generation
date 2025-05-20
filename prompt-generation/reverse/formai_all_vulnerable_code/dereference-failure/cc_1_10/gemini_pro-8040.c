//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 100

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <IP address> <start port> [<end port>]\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get IP address
  char *ip_address = argv[1];

  // Get start port
  int start_port = atoi(argv[2]);

  // Get end port (optional)
  int end_port = (argc >= 4) ? atoi(argv[3]) : MAX_PORTS;

  // Create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set socket options
  int optval = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
    perror("setsockopt");
    return EXIT_FAILURE;
  }

  // Resolve IP address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(ip_address);

  // Scan ports
  for (int port = start_port; port <= end_port; port++) {
    server_addr.sin_port = htons(port);

    // Connect to port
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
      printf("Port %d: open\n", port);
    }
  }

  // Close socket
  close(sockfd);

  return EXIT_SUCCESS;
}