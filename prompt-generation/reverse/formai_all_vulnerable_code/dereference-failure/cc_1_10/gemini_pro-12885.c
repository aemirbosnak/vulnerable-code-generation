//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_SIZE 1024

int main(int argc, char** argv) {
  int sockfd, n;
  struct sockaddr_in serv_addr;
  char buffer[MAX_SIZE];

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return 1;
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(argv[2]));
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    return 1;
  }

  strcpy(buffer, "GET / HTTP/1.1\r\nHost: ");
  strcat(buffer, argv[1]);
  strcat(buffer, "\r\n\r\n");

  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("write");
    return 1;
  }

  memset(buffer, 0, MAX_SIZE);

  while ((n = read(sockfd, buffer, MAX_SIZE)) > 0) {
    printf("%s", buffer);
  }

  if (n < 0) {
    perror("read");
    return 1;
  }

  close(sockfd);

  return 0;
}