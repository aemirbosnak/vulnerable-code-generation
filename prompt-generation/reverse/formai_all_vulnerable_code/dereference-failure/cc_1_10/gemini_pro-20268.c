//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXLINE 1024

int main(int argc, char **argv) {
  int sockfd, n;
  char recvline[MAXLINE + 1];
  struct sockaddr_in servaddr;

  if (argc != 3) {
    fprintf(stderr, "usage: %s <IP address> <port>\n", argv[0]);
    exit(1);
  }

  // Create a socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket error");
    exit(1);
  }

  // Resolve the server's address and port
  struct hostent *host;
  if ((host = gethostbyname(argv[1])) == NULL) {
    perror("gethostbyname error");
    exit(1);
  }

  // Set up the server's address and port
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect error");
    exit(1);
  }

  // Send a message to the server
  char *message = "Hello, server!";
  if (send(sockfd, message, strlen(message), 0) < 0) {
    perror("send error");
    exit(1);
  }

  // Receive a message from the server
  if (recv(sockfd, recvline, MAXLINE, 0) < 0) {
    perror("recv error");
    exit(1);
  }
  recvline[n] = '\0'; // Null-terminate the received message

  // Print the received message
  printf("Received: %s\n", recvline);

  // Close the socket
  close(sockfd);

  return 0;
}