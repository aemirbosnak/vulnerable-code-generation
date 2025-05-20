//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  int sockfd, n;
  struct sockaddr_in servaddr;
  char recvline[1024], sendline[1024];

  if (argc != 3) {
    fprintf(stderr, "usage: %s <IP address> <port>\n", argv[0]);
    exit(1);
  }

  // Create a socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket error");
    exit(1);
  }

  // Set up the server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton error");
    exit(1);
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect error");
    exit(1);
  }

  // Send a command to the server
  strcpy(sendline, "LOGIN username password\r\n");
  if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
    perror("send error");
    exit(1);
  }

  // Receive the server's response
  if ((n = recv(sockfd, recvline, 1023, 0)) < 0) {
    perror("recv error");
    exit(1);
  }
  recvline[n] = '\0';
  printf("%s", recvline);

  // Close the socket
  close(sockfd);

  return 0;
}