//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
  // Check arguments
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Resolve hostname
  struct hostent *host = gethostbyname(argv[1]);
  if (!host) {
    fprintf(stderr, "Error: gethostbyname() failed\n");
    exit(EXIT_FAILURE);
  }

  // Create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    fprintf(stderr, "Error: socket() failed\n");
    exit(EXIT_FAILURE);
  }

  // Connect to host
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(argv[2]));
  addr.sin_addr = *(struct in_addr *)host->h_addr;
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    fprintf(stderr, "Error: connect() failed\n");
    exit(EXIT_FAILURE);
  }

  // Send request
  char request[] = "GET / HTTP/1.1\r\nHost: "
                   "example.com\r\n\r\n";
  if (send(sock, request, strlen(request), 0) < 0) {
    fprintf(stderr, "Error: send() failed\n");
    exit(EXIT_FAILURE);
  }

  // Receive response
  char buffer[1024];
  while (recv(sock, buffer, sizeof(buffer), 0) > 0) {
    printf("%s", buffer);
  }

  if (ferror(stdout)) {
    fprintf(stderr, "Error: ferror(stdout) failed\n");
    exit(EXIT_FAILURE);
  }

  // Close socket
  close(sock);

  return EXIT_SUCCESS;
}