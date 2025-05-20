//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// The web server we want to connect to
#define HOST "google.com"
// The port number of the web server
#define PORT 80
// The path to the resource we want to request
#define PATH "/index.html"

// A simple HTTP request
#define REQUEST \
  "GET " PATH " HTTP/1.1\r\n" \
  "Host: " HOST "\r\n" \
  "Connection: close\r\n" \
  "\r\n"

int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Get the IP address of the web server
  struct hostent *host = gethostbyname(HOST);
  if (host == NULL) {
    perror("gethostbyname");
    return 1;
  }

  // Create a sockaddr_in structure
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr = *(struct in_addr *)host->h_addr;

  // Connect to the web server
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    return 1;
  }

  // Send the HTTP request
  if (send(sockfd, REQUEST, strlen(REQUEST), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the HTTP response
  char buffer[1024];
  while (1) {
    int n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1) {
      perror("recv");
      return 1;
    } else if (n == 0) {
      break;
    }
    // Print the HTTP response
    fwrite(buffer, n, 1, stdout);
  }

  // Close the socket
  close(sockfd);

  return 0;
}