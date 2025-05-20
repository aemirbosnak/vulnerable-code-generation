//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int create_socket(char *host, char *port) {
  struct addrinfo hints, *res;
  int sockfd;
  
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if (getaddrinfo(host, port, &hints, &res) != 0) {
    fprintf(stderr, "Could not resolve hostname\n");
    exit(EXIT_FAILURE);
  }

  sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (sockfd == -1) {
    fprintf(stderr, "Could not create socket\n");
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, res->ai_addr, res->ai_addrlen) != 0) {
    fprintf(stderr, "Could not connect to socket\n");
    exit(EXIT_FAILURE);
  }

  return sockfd;
}

void print_response(char *response) {
  printf("HTTP Response:\n%s", response);
}

void send_request(int sockfd, char *host, char *path) {
  char request[MAX_BUFFER_SIZE], response[MAX_BUFFER_SIZE];
  
  memset(request, 0, sizeof(request));
  sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

  if (send(sockfd, request, strlen(request), 0) == -1) {
    fprintf(stderr, "Could not send request\n");
    exit(EXIT_FAILURE);
  }

  memset(response, 0, sizeof(response));
  while (recv(sockfd, response, MAX_BUFFER_SIZE - 1, 0) > 0);
  print_response(response);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: httpclient host port\n");
    exit(EXIT_FAILURE);
  }

  int sockfd = create_socket(argv[1], argv[2]);
  send_request(sockfd, argv[1], "/");
  close(sockfd);

  return 0;
}