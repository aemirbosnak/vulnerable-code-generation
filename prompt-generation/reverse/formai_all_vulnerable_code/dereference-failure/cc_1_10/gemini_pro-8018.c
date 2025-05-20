//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Resolve the hostname.
  struct hostent *hostent = gethostbyname(argv[1]);
  if (hostent == NULL) {
    perror("gethostbyname");
    exit(EXIT_FAILURE);
  }

  // Create the socket address.
  struct sockaddr_in sockaddr_in;
  sockaddr_in.sin_family = AF_INET;
  sockaddr_in.sin_port = htons(atoi(argv[2]));
  memcpy(&sockaddr_in.sin_addr, hostent->h_addr, hostent->h_length);

  // Connect to the server.
  if (connect(sockfd, (const struct sockaddr *)&sockaddr_in,
              sizeof(sockaddr_in)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send a message to the server.
  char *message = "Hello, world!";
  if (write(sockfd, message, strlen(message)) == -1) {
    perror("write");
    exit(EXIT_FAILURE);
  }

  // Receive a response from the server.
  char buf[MAX_BUF_SIZE];
  int nbytes = read(sockfd, buf, MAX_BUF_SIZE);
  if (nbytes == -1) {
    perror("read");
    exit(EXIT_FAILURE);
  }

  // Print the response from the server.
  printf("Received: %s\n", buf);

  // Close the socket.
  close(sockfd);

  return EXIT_SUCCESS;
}