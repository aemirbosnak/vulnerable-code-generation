//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

// Define the HTTP GET request
#define HTTP_GET "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n"

int main(int argc, char *argv[]) {
  // Check if the user provided a URL
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse the URL
  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  int status = getaddrinfo(argv[1], "80", &hints, &res);
  if (status != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    return EXIT_FAILURE;
  }

  // Create the socket
  int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connect to the server
  if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send the HTTP GET request
  if (send(sockfd, HTTP_GET, strlen(HTTP_GET), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the HTTP response
  char buffer[1024];
  int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the HTTP response
  printf("%s", buffer);

  // Close the socket
  close(sockfd);

  freeaddrinfo(res);

  return EXIT_SUCCESS;
}