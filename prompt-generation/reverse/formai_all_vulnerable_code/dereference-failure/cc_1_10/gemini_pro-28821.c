//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define BUFFSIZE 1024

int main(int argc, char *argv[])
{
  int sockfd, ret, n;
  struct sockaddr_in servaddr;
  char sendline[BUFFSIZE], recvline[BUFFSIZE], hostname[BUFFSIZE];
  socklen_t len;

  if (argc != 3) {
    fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(2);
  }

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));

  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(3);
  }

  ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
  if (ret < 0) {
    perror("connect");
    exit(4);
  }

  while (1) {
    printf("Ping: ");
    fgets(sendline, BUFFSIZE, stdin);

    if (strncmp(sendline, "quit\n", 5) == 0) {
      break;
    }

    n = send(sockfd, sendline, strlen(sendline), 0);
    if (n < 0) {
      perror("send");
      exit(5);
    }

    n = recv(sockfd, recvline, BUFFSIZE, 0);
    if (n < 0) {
      perror("recv");
      exit(6);
    }
    recvline[n] = 0;
    printf("Pong: %s\n", recvline);
  }

  close(sockfd);
  return 0;
}