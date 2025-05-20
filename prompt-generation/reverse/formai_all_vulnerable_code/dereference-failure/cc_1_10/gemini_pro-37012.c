//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// A simple server that listens on a port and echoes back any data it receives.

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int port = atoi(argv[1]);

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Bind the socket to an address.
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(port);
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for connections.
  if (listen(sockfd, 5) < 0) {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Accept a connection.
  int connfd = accept(sockfd, NULL, NULL);
  if (connfd < 0) {
    perror("accept");
    return EXIT_FAILURE;
  }

  // Read data from the client.
  char buf[1024];
  int n;
  while ((n = read(connfd, buf, sizeof(buf))) > 0) {
    // Write the data back to the client.
    if (write(connfd, buf, n) < 0) {
      perror("write");
      return EXIT_FAILURE;
    }
  }

  // Close the connection.
  close(connfd);

  // Close the socket.
  close(sockfd);

  return EXIT_SUCCESS;
}