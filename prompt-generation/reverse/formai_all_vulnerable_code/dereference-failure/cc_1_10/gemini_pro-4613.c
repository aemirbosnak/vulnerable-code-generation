//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int sockfd;
  struct sockaddr_in servaddr;

  // Create a socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set the server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    return EXIT_FAILURE;
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send a HTTP request
  char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the HTTP response
  char response[MAX_LINE];
  while (recv(sockfd, response, MAX_LINE, 0) > 0) {
    printf("%s", response);
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}