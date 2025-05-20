//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 4096

// This program builds a simple HTTP client that sends a GET request to a server and prints the response to the console

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <url>\n", argv[0]);
    return 1;
  }

  // Parse the server URL
  char* url = argv[1];
  char* hostname;
  char* path;

  if (strstr(url, "http://") != NULL) {
    hostname = strdup(url + 7);
  } else {
    hostname = strdup(url);
  }

  path = strchr(hostname, '/');

  if (path == NULL) {
    path = "/";
  } else {
    *path = '\0';
    path++;
  }

  struct addrinfo hints, *addr;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  // Resolve the hostname
  int code;
  if ((code = getaddrinfo(hostname, "80", &hints, &addr)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(code));
    return 2;
  }

  // Create a socket and connect to the server
  int sockfd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
  if (sockfd < 0) {
    perror("socket");
    return 3;
  }

  if (connect(sockfd, addr->ai_addr, addr->ai_addrlen) < 0) {
    perror("connect");
    return 4;
  }

  // Send the GET request to the server
  char request[MAX_LINE];
  sprintf(request, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, hostname);

  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("send");
    return 5;
  }

  // Read the response from the server and print it to the console
  char response[MAX_LINE];

  while (recv(sockfd, response, MAX_LINE, 0) > 0) {
    printf("%s", response);
    memset(response, 0, MAX_LINE);
  }

  // Close the socket and free memory
  close(sockfd);
  freeaddrinfo(addr);
  free(hostname);

  return 0;
}