//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFERSIZE 1024

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the hostname and port number.
  char *hostname = argv[1];
  int port = atoi(argv[2]);

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Resolve the hostname to an IP address.
  struct hostent *hostinfo = gethostbyname(hostname);
  if (hostinfo == NULL) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }

  // Create a sockaddr_in structure.
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  memcpy(&addr.sin_addr, hostinfo->h_addr, hostinfo->h_length);

  // Connect to the server.
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send a message to the server.
  char *msg = "Hello, world!\n";
  if (send(sockfd, msg, strlen(msg), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive a response from the server.
  char buffer[BUFFERSIZE];
  int nbytes = recv(sockfd, buffer, BUFFERSIZE, 0);
  if (nbytes < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the response from the server.
  printf("Received %d bytes from the server:\n%s\n", nbytes, buffer);

  // Close the connection.
  if (close(sockfd) < 0) {
    perror("close");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}