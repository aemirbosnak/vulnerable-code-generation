//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  char *host, *port, *sender, *recipient, *subject, *body;
  if (argc < 6) {
    printf("Usage: %s <host> <port> <sender> <recipient> <subject> <body>\n", argv[0]);
    return EXIT_FAILURE;
  }
  host = argv[1];
  port = argv[2];
  sender = argv[3];
  recipient = argv[4];
  subject = argv[5];
  body = argv[6];

  struct addrinfo hints, *result;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  int status = getaddrinfo(host, port, &hints, &result);
  if (status != 0) {
    printf("getaddrinfo: %s\n", gai_strerror(status));
    return EXIT_FAILURE;
  }

  int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  if (connect(sockfd, result->ai_addr, result->ai_addrlen) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  freeaddrinfo(result);

  char buffer[1024];
  sprintf(buffer, "HELO %s\r\n", host);
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, sizeof(buffer), 0);

  sprintf(buffer, "MAIL FROM:<%s>\r\n", sender);
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, sizeof(buffer), 0);

  sprintf(buffer, "RCPT TO:<%s>\r\n", recipient);
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, sizeof(buffer), 0);

  sprintf(buffer, "DATA\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, sizeof(buffer), 0);

  sprintf(buffer, "Subject: %s\r\n", subject);
  send(sockfd, buffer, strlen(buffer), 0);

  sprintf(buffer, "To: %s\r\n", recipient);
  send(sockfd, buffer, strlen(buffer), 0);

  sprintf(buffer, "From: %s\r\n", sender);
  send(sockfd, buffer, strlen(buffer), 0);

  sprintf(buffer, "\r\n%s\r\n", body);
  send(sockfd, buffer, strlen(buffer), 0);

  sprintf(buffer, ".\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, sizeof(buffer), 0);

  sprintf(buffer, "QUIT\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, sizeof(buffer), 0);

  close(sockfd);

  return EXIT_SUCCESS;
}