//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_LEN 1024

int main() {
  char* host = "example.com";
  char* username = "sample";
  char* password = "pass";

  struct hostent* server = gethostbyname(host);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR: Unable to open socket");
    exit(1);
  }

  struct sockaddr_in serv_addr;
  bzero((char*)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(110);
  bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);

  if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR: Unable to connect to server");
    exit(1);
  }

  char buffer[MAX_LEN];
  bzero(buffer, MAX_LEN);

  read(sockfd, buffer, MAX_LEN - 1);
  printf("%s\n", buffer);

  sprintf(buffer, "USER %s\r\n", username);
  write(sockfd, buffer, strlen(buffer));
  bzero(buffer, MAX_LEN);

  read(sockfd, buffer, MAX_LEN - 1);
  printf("%s\n", buffer);

  sprintf(buffer, "PASS %s\r\n", password);
  write(sockfd, buffer, strlen(buffer));
  bzero(buffer, MAX_LEN);

  read(sockfd, buffer, MAX_LEN - 1);
  printf("%s\n", buffer);

  sprintf(buffer, "LIST\r\n");
  write(sockfd, buffer, strlen(buffer));
  bzero(buffer, MAX_LEN);

  read(sockfd, buffer, MAX_LEN - 1);
  printf("%s\n", buffer);

  close(sockfd);
  return 0;
}