//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

void die(const char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  const char *host = argv[1];
  int port = atoi(argv[2]);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) die("socket");

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);

  if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
    die("Invalid address/ Address not supported");
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    die("connection failed");
  }

  // Send HTTP request
  const char *request =
    "GET / HTTP/1.1\r\n"
    "Host: %s:%d\r\n"
    "User-Agent: Irregular HTTP Client/1.0\r\n"
    "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
    "Accept-Language: en-US,en;q=0.5\r\n"
    "Accept-Encoding: gzip, deflate\r\n"
    "Connection: keep-alive\r\n\r\n";

  char req[1024];
  snprintf(req, sizeof(req), request, host, port);

  int n = send(sockfd, req, strlen(req), 0);
  if (n < 0) die("send failed");

  // Read HTTP response
  char buf[1024];
  int total = 0;
  while (1) {
    int n = recv(sockfd, buf, sizeof(buf), 0);
    if (n <= 0) break;

    fwrite(buf, n, 1, stdout);
    total += n;
  }

  close(sockfd);
  printf("\nReceived %d bytes\n", total);
  return EXIT_SUCCESS;
}