//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
  int sockfd, n;
  struct sockaddr_in servaddr;
  char sendline[MAX_LINE], recvline[MAX_LINE];

  if (argc != 3) {
    printf("usage: %s <server address> <port>\n", argv[0]);
    exit(1);
  }

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(argv[1]);
  servaddr.sin_port = htons(atoi(argv[2]));

  if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    exit(1);
  }

  while (1) {
    printf("> ");
    fgets(sendline, MAX_LINE, stdin);

    if (strcmp(sendline, "quit\n") == 0) {
      break;
    }

    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
      perror("send");
      exit(1);
    }

    if ((n = recv(sockfd, recvline, MAX_LINE, 0)) < 0) {
      perror("recv");
      exit(1);
    }

    recvline[n] = '\0';
    printf("%s", recvline);
  }

  close(sockfd);
  return 0;
}