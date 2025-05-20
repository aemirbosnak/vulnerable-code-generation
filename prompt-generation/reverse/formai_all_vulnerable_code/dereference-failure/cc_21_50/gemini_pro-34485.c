//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) 
{
  int sockfd, n;
  struct sockaddr_in servaddr;
  char sendline[MAXLINE], recvline[MAXLINE];

  if (argc != 3) {
    printf("Usage: %s <server_address> <port_number>\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

  if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
    printf("connect error\n");
    exit(1);
  }

  while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
    printf("%s", recvline);
    if (recvline[n-1] == '\n') {
      break;
    }
  }

  if (n < 0) {
    printf("read error\n");
    exit(1);
  }

  strcpy(sendline, "HELO localhost\r\n");
  write(sockfd, sendline, strlen(sendline));

  while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
    printf("%s", recvline);
    if (recvline[n-1] == '\n') {
      break;
    }
  }

  if (n < 0) {
    printf("read error\n");
    exit(1);
  }

  strcpy(sendline, "MAIL FROM: <sender@example.com>\r\n");
  write(sockfd, sendline, strlen(sendline));

  while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
    printf("%s", recvline);
    if (recvline[n-1] == '\n') {
      break;
    }
  }

  if (n < 0) {
    printf("read error\n");
    exit(1);
  }

  strcpy(sendline, "RCPT TO: <recipient@example.com>\r\n");
  write(sockfd, sendline, strlen(sendline));

  while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
    printf("%s", recvline);
    if (recvline[n-1] == '\n') {
      break;
    }
  }

  if (n < 0) {
    printf("read error\n");
    exit(1);
  }

  strcpy(sendline, "DATA\r\n");
  write(sockfd, sendline, strlen(sendline));

  while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
    printf("%s", recvline);
    if (recvline[n-1] == '\n') {
      break;
    }
  }

  if (n < 0) {
    printf("read error\n");
    exit(1);
  }

  strcpy(sendline, "Subject: Test email\r\n\r\nThis is a test email.\r\n.\r\n");
  write(sockfd, sendline, strlen(sendline));

  while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
    printf("%s", recvline);
    if (recvline[n-1] == '\n') {
      break;
    }
  }

  if (n < 0) {
    printf("read error\n");
    exit(1);
  }

  strcpy(sendline, "QUIT\r\n");
  write(sockfd, sendline, strlen(sendline));

  while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
    printf("%s", recvline);
    if (recvline[n-1] == '\n') {
      break;
    }
  }

  if (n < 0) {
    printf("read error\n");
    exit(1);
  }

  close(sockfd);
  return 0;
}