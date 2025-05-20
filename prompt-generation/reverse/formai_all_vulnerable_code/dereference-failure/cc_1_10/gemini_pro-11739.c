//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
  if (argc != 6) {
    printf("Usage: %s <sender> <recipient> <server> <port> <message>\n", argv[0]);
    return 1;
  }

  char *sender = argv[1];
  char *recipient = argv[2];
  char *server = argv[3];
  int port = atoi(argv[4]);
  char *message = argv[5];

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  if (inet_pton(AF_INET, server, &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    return 1;
  }

  char buffer[1024];

  // SMTP handshake
  memset(buffer, 0, 1024);
  sprintf(buffer, "EHLO %s\r\n", server);
  send(sockfd, buffer, strlen(buffer), 0);
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, 1024, 0);

  memset(buffer, 0, 1024);
  sprintf(buffer, "MAIL FROM: <%s>\r\n", sender);
  send(sockfd, buffer, strlen(buffer), 0);
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, 1024, 0);

  memset(buffer, 0, 1024);
  sprintf(buffer, "RCPT TO: <%s>\r\n", recipient);
  send(sockfd, buffer, strlen(buffer), 0);
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, 1024, 0);

  memset(buffer, 0, 1024);
  sprintf(buffer, "DATA\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, 1024, 0);

  memset(buffer, 0, 1024);
  sprintf(buffer, "%s\r\n.", message);
  send(sockfd, buffer, strlen(buffer), 0);
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, 1024, 0);

  memset(buffer, 0, 1024);
  sprintf(buffer, "QUIT\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, 1024, 0);

  close(sockfd);

  return 0;
}