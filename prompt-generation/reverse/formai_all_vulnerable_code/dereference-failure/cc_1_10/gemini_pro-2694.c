//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <string.h>

#define MAX_ATTEMPTS 3

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *hostname = argv[1];
  struct sockaddr_in addr;
  struct hostent *host;

  // Resolve the hostname to an IP address
  if ((host = gethostbyname(hostname)) == NULL) {
    herror("gethostbyname");
    exit(EXIT_FAILURE);
  }

  memcpy(&addr.sin_addr, host->h_addr, host->h_length);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(80);

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set a timeout on the socket
  struct timeval timeout;
  timeout.tv_sec = 1;
  timeout.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) == -1) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send a HTTP HEAD request to the server
  char request[] = "HEAD / HTTP/1.1\r\nHost: ";
  strcat(request, hostname);
  strcat(request, "\r\n\r\n");
  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the response from the server
  char buffer[1024];
  int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Print the response to the console
  printf("%s", buffer);

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}