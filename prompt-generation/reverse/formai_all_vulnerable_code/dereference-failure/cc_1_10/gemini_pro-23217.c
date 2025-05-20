//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

// A simple HTTP client
int main(int argc, char *argv[]) {
  // Check the arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the host and port
  char *host = argv[1];
  int port = atoi(argv[2]);

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Get the host's IP address
  struct hostent *hostent = gethostbyname(host);
  if (hostent == NULL) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }

  // Create the socket address
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  memcpy(&servaddr.sin_addr, hostent->h_addr, hostent->h_length);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send the HTTP request
  char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the HTTP response
  char buffer[4096];
  int n;
  while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
    // Print the HTTP response
    printf("%s", buffer);
  }
  if (n == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}