//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Parse the URL
  char *url = argv[1];
  char *host = NULL;
  char *path = NULL;

  if (strncmp(url, "http://", 7) != 0) {
    fprintf(stderr, "Invalid URL format\n");
    exit(EXIT_FAILURE);
  }

  url += 7;
  host = strsep(&url, "/");
  path = url;

  printf("Host: %s\nPath: %s\n", host, path);

  // Resolve the hostname
  struct hostent *hent = gethostbyname(host);
  if (hent == NULL) {
    fprintf(stderr, "Could not resolve hostname\n");
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  struct sockaddr_in addr;
  memcpy(&addr.sin_addr, hent->h_addr, hent->h_length);
  addr.sin_port = htons(80);
  addr.sin_family = AF_INET;

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send the HTTP request
  char request[BUFFER_SIZE];
  snprintf(request, BUFFER_SIZE, "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the response
  char response[BUFFER_SIZE];
  ssize_t res_size;
  while ((res_size = recv(sockfd, response, BUFFER_SIZE - 1, 0)) > 0) {
    response[res_size] = '\0';
    printf("%s", response);
  }

  if (res_size < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Close the socket
  close(sockfd);

  return 0;
}