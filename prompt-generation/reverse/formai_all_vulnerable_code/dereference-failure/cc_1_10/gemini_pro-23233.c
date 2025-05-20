//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

void scan(char *host, int port) {
  int sockfd, bytes;
  struct sockaddr_in serv_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_addr.s_addr = inet_addr(host);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  bytes = send(sockfd, "Hello", 6, 0);
  if (bytes < 0) {
    perror("send");
    exit(1);
  }

  bytes = recv(sockfd, "World", 6, 0);
  if (bytes < 0) {
    perror("recv");
    exit(1);
  }

  printf("%s\n", "Port open");

  close(sockfd);
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <host> <port>\n", argv[0]);
    exit(1);
  }

  scan(argv[1], atoi(argv[2]));

  return 0;
}