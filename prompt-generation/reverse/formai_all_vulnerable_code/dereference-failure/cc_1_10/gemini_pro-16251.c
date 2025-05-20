//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 100

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip address> <port range>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Parse the IP address and port range.
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &addr.sin_addr) != 1) {
    fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set the socket options.
  int optval = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Bind the socket to the IP address and port.
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // Listen for connections.
  if (listen(sockfd, 10) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  // Accept connections.
  while (1) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sockfd == -1) {
      perror("accept");
      continue;
    }

    // Send a message to the client.
    char *message = "Hello, world!\n";
    if (send(client_sockfd, message, strlen(message), 0) == -1) {
      perror("send");
      close(client_sockfd);
      continue;
    }

    // Close the client socket.
    close(client_sockfd);
  }

  // Close the socket.
  close(sockfd);

  return 0;
}