//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char* argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  char* hostname = argv[1];
  int port = atoi(argv[2]);

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(hostname);
  server_addr.sin_port = htons(port);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    exit(1);
  }

  char buffer[1024];
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s", buffer);

  char* username = "username";
  char* password = "password";

  sprintf(buffer, "USER %s\r\n", username);
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s", buffer);

  sprintf(buffer, "PASS %s\r\n", password);
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s", buffer);

  sprintf(buffer, "STAT\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s", buffer);

  sprintf(buffer, "LIST\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s", buffer);

  sprintf(buffer, "RETR 1\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s", buffer);

  sprintf(buffer, "QUIT\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s", buffer);

  close(sockfd);
  return 0;
}