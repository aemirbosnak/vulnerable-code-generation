//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: peaceful
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: %s <host> <port> <request path>\n", argv[0]);
    return 1;
  }
  const char *host = argv[1];
  const char *port = argv[2];
  const char *path = argc == 3 ? "/" : argv[3];
  struct in_addr addr;
  if (inet_pton(AF_INET, host, &addr) != 1) {
    printf("Invalid host\n");
    return 1;
  }
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Failed to create socket\n");
    return 1;
  }
  struct sockaddr_in addr_in = {
    .sin_family = AF_INET,
    .sin_addr = addr,
    .sin_port = htons(atoi(port))
  };
  if (connect(sockfd, (struct sockaddr *)&addr_in, sizeof(addr_in)) == -1) {
    printf("Failed to connect to server\n");
    return 1;
  }
  char request[BUFF_SIZE];
  snprintf(request, BUFF_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
  if (send(sockfd, request, strlen(request), 0) < strlen(request)) {
    printf("Failed to send request\n");
    return 1;
  }
  char buffer[BUFF_SIZE];
  int num_bytes;
  while ((num_bytes = recv(sockfd, buffer, BUFF_SIZE - 1, 0)) > 0) {
    buffer[num_bytes] = '\0';
    printf("%s", buffer);
  }
  if (num_bytes == -1) {
    printf("Failed to receive data\n");
    return 1;
  }
  return 0;
}