//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
  int sockfd, n;
  char recvline[MAXLINE + 1];
  struct sockaddr_in servaddr;
  struct hostent *hptr;

  if (argc != 3) {
    fprintf(stderr, "usage: %s <IP address> <port>\n", argv[0]);
    exit(1);
  }

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }

  if ((hptr = gethostbyname(argv[1])) == NULL) {
    fprintf(stderr, "gethostbyname error: %s\n", hstrerror(h_errno));
    exit(1);
  }

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  bcopy(hptr->h_addr_list[0], (char *)&servaddr.sin_addr.s_addr, hptr->h_length);

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    exit(1);
  }

  while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
    recvline[n] = 0;
    if (fputs(recvline, stdout) == EOF) {
      perror("fputs");
      exit(1);
    }
  }

  if (n < 0) {
    perror("read");
    exit(1);
  }

  close(sockfd);

  return 0;
}