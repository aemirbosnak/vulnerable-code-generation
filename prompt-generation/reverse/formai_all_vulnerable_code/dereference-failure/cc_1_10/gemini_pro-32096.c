//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  char *hostname = argv[1];
  int port = atoi(argv[2]);

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Resolve the hostname.
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    perror("gethostbyname");
    exit(1);
  }

  // Create a sockaddr_in struct.
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  memcpy(&addr.sin_addr, host->h_addr, host->h_length);

  // Connect to the server.
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    exit(1);
  }

  // Send a HTTP request.
  char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
  if (write(sockfd, request, strlen(request)) == -1) {
    perror("write");
    exit(1);
  }

  // Read the HTTP response.
  char response[4096];
  int n = read(sockfd, response, sizeof(response) - 1);
  if (n == -1) {
    perror("read");
    exit(1);
  }

  // Print the HTTP response.
  response[n] = '\0';
  printf("%s", response);

  // Close the socket.
  close(sockfd);

  return 0;
}