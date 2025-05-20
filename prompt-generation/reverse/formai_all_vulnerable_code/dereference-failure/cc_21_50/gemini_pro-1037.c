//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
  if (argc != 5) {
    fprintf(stderr, "usage: %s <server> <port> <from> <to>\n", argv[0]);
    return 1;
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(argv[2]));
  if (inet_aton(argv[1], &addr.sin_addr) == -1) {
    perror("inet_aton");
    return 1;
  }

  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    return 1;
  }

  char buf[1024];
  snprintf(buf, sizeof(buf), "HELO %s\r\n", argv[1]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return 1;
  }

  if (strncmp(buf, "250 ", 4) != 0) {
    fprintf(stderr, "server did not respond with a 250 code: %s\n", buf);
    return 1;
  }

  snprintf(buf, sizeof(buf), "MAIL FROM:<%s>\r\n", argv[3]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return 1;
  }

  if (strncmp(buf, "250 ", 4) != 0) {
    fprintf(stderr, "server did not respond with a 250 code: %s\n", buf);
    return 1;
  }

  snprintf(buf, sizeof(buf), "RCPT TO:<%s>\r\n", argv[4]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return 1;
  }

  if (strncmp(buf, "250 ", 4) != 0) {
    fprintf(stderr, "server did not respond with a 250 code: %s\n", buf);
    return 1;
  }

  snprintf(buf, sizeof(buf), "DATA\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return 1;
  }

  if (strncmp(buf, "354 ", 4) != 0) {
    fprintf(stderr, "server did not respond with a 354 code: %s\n", buf);
    return 1;
  }

  snprintf(buf, sizeof(buf), "Subject: %s\r\n\r\n", "Hello World!");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  snprintf(buf, sizeof(buf), "This is an email message.\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  snprintf(buf, sizeof(buf), ".\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return 1;
  }

  if (strncmp(buf, "250 ", 4) != 0) {
    fprintf(stderr, "server did not respond with a 250 code: %s\n", buf);
    return 1;
  }

  snprintf(buf, sizeof(buf), "QUIT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return 1;
  }

  if (strncmp(buf, "221 ", 4) != 0) {
    fprintf(stderr, "server did not respond with a 221 code: %s\n", buf);
    return 1;
  }

  close(sockfd);
  return 0;
}