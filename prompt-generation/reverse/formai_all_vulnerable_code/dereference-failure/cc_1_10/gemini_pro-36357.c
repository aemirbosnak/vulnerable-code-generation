//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// A function to send an HTTP request to a server
int send_http_request(char *hostname, char *port, char *path) {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }

  // Resolve the hostname to an IP address
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    perror("gethostbyname");
    return -1;
  }

  // Connect to the server
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(port));
  addr.sin_addr = *((struct in_addr *)host->h_addr);
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    return -1;
  }

  // Send the HTTP request
  char request[1024];
  sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("send");
    return -1;
  }

  // Receive the HTTP response
  char response[1024];
  int n = recv(sockfd, response, sizeof(response) - 1, 0);
  if (n == -1) {
    perror("recv");
    return -1;
  }

  // Print the HTTP response
  printf("%s", response);

  // Close the socket
  close(sockfd);

  return 0;
}

// The main function
int main(int argc, char *argv[]) {
  // Check if the user has provided enough arguments
  if (argc != 4) {
    fprintf(stderr, "Usage: %s hostname port path\n", argv[0]);
    return -1;
  }

  // Send the HTTP request
  if (send_http_request(argv[1], argv[2], argv[3]) == -1) {
    return -1;
  }

  return 0;
}