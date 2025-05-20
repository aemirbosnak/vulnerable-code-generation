//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_LENGTH 1024
#define DEFAULT_PORT 80

int main(int argc, char** argv) {
  const char* server_endpoint = "www.example.com";
  int port = DEFAULT_PORT; // default port is 80

  if (argc > 1) {
    server_endpoint = argv[1];
    if (argc > 2) {
      port = atoi(argv[2]);
    }
  }

  // Get server information
  struct hostent* server;
  server = gethostbyname(server_endpoint);
  if (server == NULL) {
    fprintf(stderr, "Could not find host: %s\n", server_endpoint);
    exit(EXIT_FAILURE);
  }

  // Create a TCP socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set server connection information
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  // Connect to server
  if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send HTTP request to server
  const char* request =
    "GET / HTTP/1.1\r\n"
    "Host: www.example.com\r\n"
    "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.14; rv:69.0) Gecko/20100101 Firefox/69.0\r\n"
    "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
    "Accept-Language: en-US,en;q=0.5\r\n"
    "Accept-Encoding: gzip, deflate, br\r\n"
    "Connection: keep-alive\r\n"
    "Upgrade-Insecure-Requests: 1\r\n\r\n";

  if (write(sockfd, request, strlen(request)) == -1) {
    perror("write");
    exit(EXIT_FAILURE);
  }

  // Read response from server
  char buffer[BUFFER_LENGTH + 1];
  ssize_t bytes_read;
  while ((bytes_read = read(sockfd, buffer, BUFFER_LENGTH)) > 0) {
    buffer[bytes_read] = '\0';
    printf("%s", buffer);
  }
  if (bytes_read == -1) {
    perror("read");
    exit(EXIT_FAILURE);
  }

  // Close socket
  if (close(sockfd) == -1) {
    perror("close");
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}