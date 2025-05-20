//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
  if (argc!= 3) {
    printf("Usage: %s <hostname/IP address> <port number>\n", argv[0]);
    exit(1);
  }

  char *hostname = argv[1];
  int port = atoi(argv[2]);

  struct addrinfo hints, *result;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
    printf("Error: %s\n", gai_strerror(errno));
    exit(1);
  }

  int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (sockfd == -1) {
    printf("Error: %s\n", strerror(errno));
    exit(1);
  }

  if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
    printf("Error: %s\n", strerror(errno));
    exit(1);
  }

  char buffer[BUFFER_SIZE];
  memset(buffer, 0, BUFFER_SIZE);

  send(sockfd, "PING", strlen("PING"), 0);

  int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (bytes_received == -1) {
    printf("Error: %s\n", strerror(errno));
    exit(1);
  }

  buffer[bytes_received] = '\0';
  printf("Response: %s\n", buffer);

  close(sockfd);
  freeaddrinfo(result);

  return 0;
}