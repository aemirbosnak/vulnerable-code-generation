//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <IP address> <command>\n", argv[0]);
    return 1;
  }

  int sockfd;
  struct sockaddr_in server_addr;
  char buf[BUF_SIZE];
  int nbytes;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  nbytes = recv(sockfd, buf, BUF_SIZE, 0);
  if (nbytes < 0) {
    perror("recv");
    return 1;
  }

  printf("%s", buf);

  send(sockfd, argv[2], strlen(argv[2]), 0);

  while ((nbytes = recv(sockfd, buf, BUF_SIZE, 0)) > 0) {
    printf("%s", buf);
  }

  if (nbytes < 0) {
    perror("recv");
    return 1;
  }

  close(sockfd);

  return 0;
}