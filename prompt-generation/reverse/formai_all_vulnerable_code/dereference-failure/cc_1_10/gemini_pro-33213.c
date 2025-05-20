//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  // Create a socket
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Resolve the hostname
  struct hostent *host = gethostbyname("example.com");
  if (host == NULL) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }

  // Connect to the server
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(80);
  server_address.sin_addr.s_addr = inet_addr(host->h_addr);
  if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send an HTTP request
  char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
  if (send(socket_fd, request, strlen(request), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the HTTP response
  char response[1024];
  if (recv(socket_fd, response, sizeof(response), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Parse the HTTP response
  char *content_type = strstr(response, "Content-Type:");
  char *content_length = strstr(response, "Content-Length:");
  char *content = strstr(response, "\r\n\r\n");
  if (content_type == NULL || content_length == NULL || content == NULL) {
    fprintf(stderr, "Invalid HTTP response\n");
    return EXIT_FAILURE;
  }

  // Print the response
  printf("Content-Type: %s\n", content_type + 13);
  printf("Content-Length: %s\n", content_length + 16);
  printf("Content:\n%s\n", content + 4);

  // Close the socket
  if (close(socket_fd) == -1) {
    perror("close");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}