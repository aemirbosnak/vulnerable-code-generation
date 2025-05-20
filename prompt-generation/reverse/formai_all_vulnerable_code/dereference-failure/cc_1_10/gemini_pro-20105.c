//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define POP3_PORT 110
#define MAX_LINE_LENGTH 1024

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  char buffer[MAX_LINE_LENGTH];
  int n;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    error("Error opening socket");
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
    error("Error converting host address");
  }

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    error("Error connecting to server");
  }

  memset(buffer, 0, MAX_LINE_LENGTH);
  n = read(sockfd, buffer, MAX_LINE_LENGTH - 1);
  if (n < 0) {
    error("Error reading from server");
  }
  printf("%s", buffer);

  memset(buffer, 0, MAX_LINE_LENGTH);
  sprintf(buffer, "USER %s\r\n", "user");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    error("Error writing to server");
  }

  memset(buffer, 0, MAX_LINE_LENGTH);
  n = read(sockfd, buffer, MAX_LINE_LENGTH - 1);
  if (n < 0) {
    error("Error reading from server");
  }
  printf("%s", buffer);

  memset(buffer, 0, MAX_LINE_LENGTH);
  sprintf(buffer, "PASS %s\r\n", "password");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    error("Error writing to server");
  }

  memset(buffer, 0, MAX_LINE_LENGTH);
  n = read(sockfd, buffer, MAX_LINE_LENGTH - 1);
  if (n < 0) {
    error("Error reading from server");
  }
  printf("%s", buffer);

  memset(buffer, 0, MAX_LINE_LENGTH);
  sprintf(buffer, "LIST\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    error("Error writing to server");
  }

  memset(buffer, 0, MAX_LINE_LENGTH);
  n = read(sockfd, buffer, MAX_LINE_LENGTH - 1);
  if (n < 0) {
    error("Error reading from server");
  }
  printf("%s", buffer);

  memset(buffer, 0, MAX_LINE_LENGTH);
  sprintf(buffer, "RETR 1\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    error("Error writing to server");
  }

  memset(buffer, 0, MAX_LINE_LENGTH);
  n = read(sockfd, buffer, MAX_LINE_LENGTH - 1);
  if (n < 0) {
    error("Error reading from server");
  }
  printf("%s", buffer);

  memset(buffer, 0, MAX_LINE_LENGTH);
  sprintf(buffer, "QUIT\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    error("Error writing to server");
  }

  memset(buffer, 0, MAX_LINE_LENGTH);
  n = read(sockfd, buffer, MAX_LINE_LENGTH - 1);
  if (n < 0) {
    error("Error reading from server");
  }
  printf("%s", buffer);

  close(sockfd);

  return 0;
}