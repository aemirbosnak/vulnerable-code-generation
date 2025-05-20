//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
  // Define the HTTP request string.
  char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";

  // Get the IP address of the host.
  struct hostent *host = gethostbyname("example.com");
  if (host == NULL) {
    perror("gethostbyname");
    return 1;
  }

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Connect to the host.
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(80);
  addr.sin_addr.s_addr = ((struct in_addr *)host->h_addr_list[0])->s_addr;
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    return 1;
  }

  // Send the HTTP request.
  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the HTTP response.
  char response[4096];
  int n = recv(sockfd, response, sizeof(response), 0);
  if (n == -1) {
    perror("recv");
    return 1;
  }

  // Print the HTTP response.
  printf("%s", response);

  // Close the socket.
  close(sockfd);

  return 0;
}