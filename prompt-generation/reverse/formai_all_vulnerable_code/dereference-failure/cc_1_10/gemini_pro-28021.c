//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ctype.h>

#define MAXLINE 1024

int main(int argc, char *argv[])
{
  int sockfd, n;
  struct sockaddr_in servaddr;
  char sendline[MAXLINE], recvline[MAXLINE];
  struct hostent *hptr;

  if (argc != 3) {
    fprintf(stderr, "usage: %s <server> <port>\n", argv[0]);
    exit(1);
  }

  if ((hptr = gethostbyname(argv[1])) == NULL) {
    fprintf(stderr, "gethostbyname error for %s: %s", argv[1], hstrerror(h_errno));
    exit(1);
  }

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket error");
    exit(1);
  }

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  bcopy(hptr->h_addr, &servaddr.sin_addr, hptr->h_length);

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect error");
    exit(1);
  }

  while (1) {
    printf("> ");
    fgets(sendline, MAXLINE, stdin);

    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
      perror("send error");
      exit(1);
    }

    if (recv(sockfd, recvline, MAXLINE, 0) < 0) {
      perror("recv error");
      exit(1);
    }

    printf("%s", recvline);
  }

  close(sockfd);

  return 0;
}