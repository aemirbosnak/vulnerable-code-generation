//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <ip address> <port>\n", argv[0]);
    return 1;
  }
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
  }
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    return 1;
  }
  char buffer[1024];
  while (1) {
    printf("ftp> ");
    fgets(buffer, sizeof(buffer), stdin);
    if (strcmp(buffer, "quit\n") == 0) {
      break;
    }
    send(sockfd, buffer, strlen(buffer), 0);
    int n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n > 0) {
      printf("%s", buffer);
    } else if (n == 0) {
      printf("Connection closed by server.\n");
      break;
    } else {
      perror("recv");
      break;
    }
  }
  close(sockfd);
  return 0;
}