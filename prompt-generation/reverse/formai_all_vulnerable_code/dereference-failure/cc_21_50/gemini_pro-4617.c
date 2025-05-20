//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAXLINE 4096

int main(int argc, char *argv[]) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <server> <port> <from> <to>\n", argv[0]);
    return 1;
  }

  char *server = argv[1];
  int port = atoi(argv[2]);
  char *from = argv[3];
  char *to = argv[4];

  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  if (inet_pton(AF_INET, server, &servaddr.sin_addr) <= 0) {
    fprintf(stderr, "Invalid server address\n");
    return 1;
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    return 1;
  }

  char buffer[MAXLINE];
  memset(buffer, 0, MAXLINE);
  if (recv(sockfd, buffer, MAXLINE, 0) < 0) {
    perror("recv");
    return 1;
  }

  if (strncmp(buffer, "220", 3) != 0) {
    fprintf(stderr, "Unexpected response from server: %s\n", buffer);
    return 1;
  }

  snprintf(buffer, MAXLINE, "HELO %s\n", server);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  memset(buffer, 0, MAXLINE);
  if (recv(sockfd, buffer, MAXLINE, 0) < 0) {
    perror("recv");
    return 1;
  }

  if (strncmp(buffer, "250", 3) != 0) {
    fprintf(stderr, "Unexpected response from server: %s\n", buffer);
    return 1;
  }

  snprintf(buffer, MAXLINE, "MAIL FROM:<%s>\n", from);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  memset(buffer, 0, MAXLINE);
  if (recv(sockfd, buffer, MAXLINE, 0) < 0) {
    perror("recv");
    return 1;
  }

  if (strncmp(buffer, "250", 3) != 0) {
    fprintf(stderr, "Unexpected response from server: %s\n", buffer);
    return 1;
  }

  snprintf(buffer, MAXLINE, "RCPT TO:<%s>\n", to);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  memset(buffer, 0, MAXLINE);
  if (recv(sockfd, buffer, MAXLINE, 0) < 0) {
    perror("recv");
    return 1;
  }

  if (strncmp(buffer, "250", 3) != 0) {
    fprintf(stderr, "Unexpected response from server: %s\n", buffer);
    return 1;
  }

  snprintf(buffer, MAXLINE, "DATA\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  memset(buffer, 0, MAXLINE);
  if (recv(sockfd, buffer, MAXLINE, 0) < 0) {
    perror("recv");
    return 1;
  }

  if (strncmp(buffer, "354", 3) != 0) {
    fprintf(stderr, "Unexpected response from server: %s\n", buffer);
    return 1;
  }

  snprintf(buffer, MAXLINE, "Subject: Test email\n\nThis is a test email.\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  snprintf(buffer, MAXLINE, ".\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  memset(buffer, 0, MAXLINE);
  if (recv(sockfd, buffer, MAXLINE, 0) < 0) {
    perror("recv");
    return 1;
  }

  if (strncmp(buffer, "250", 3) != 0) {
    fprintf(stderr, "Unexpected response from server: %s\n", buffer);
    return 1;
  }

  snprintf(buffer, MAXLINE, "QUIT\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  memset(buffer, 0, MAXLINE);
  if (recv(sockfd, buffer, MAXLINE, 0) < 0) {
    perror("recv");
    return 1;
  }

  if (strncmp(buffer, "221", 3) != 0) {
    fprintf(stderr, "Unexpected response from server: %s\n", buffer);
    return 1;
  }

  close(sockfd);

  return 0;
}