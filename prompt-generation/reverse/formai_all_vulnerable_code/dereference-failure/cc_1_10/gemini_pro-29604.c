//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>

#define SMTP_PORT 25

void die(char *error) {
  perror(error);
  exit(1);
}

int main(int argc, char **argv) {
  int sockfd, port;
  struct sockaddr_in serv_addr;
  char buffer[4096];

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
    exit(1);
  }

  port = atoi(argv[2]);

  /* Create a socket. */
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    die("socket");
  }

  /* Initialize the server address. */
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
    fprintf(stderr, "Invalid address: %s\n", argv[1]);
    exit(1);
  }

  /* Connect to the server. */
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    die("connect");
  }

  /* Read the server's welcome message. */
  if (read(sockfd, buffer, sizeof(buffer)) <= 0) {
    die("read");
  }
  printf("%s", buffer);

  /* Send the EHLO command. */
  snprintf(buffer, sizeof(buffer), "EHLO %s\r\n", argv[0]);
  if (write(sockfd, buffer, strlen(buffer)) <= 0) {
    die("write");
  }

  /* Read the server's response. */
  if (read(sockfd, buffer, sizeof(buffer)) <= 0) {
    die("read");
  }
  printf("%s", buffer);

  /* Send the MAIL FROM command. */
  snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", "youremail@example.com");
  if (write(sockfd, buffer, strlen(buffer)) <= 0) {
    die("write");
  }

  /* Read the server's response. */
  if (read(sockfd, buffer, sizeof(buffer)) <= 0) {
    die("read");
  }
  printf("%s", buffer);

  /* Send the RCPT TO command. */
  snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", "receiveremail@example.com");
  if (write(sockfd, buffer, strlen(buffer)) <= 0) {
    die("write");
  }

  /* Read the server's response. */
  if (read(sockfd, buffer, sizeof(buffer)) <= 0) {
    die("read");
  }
  printf("%s", buffer);

  /* Send the DATA command. */
  snprintf(buffer, sizeof(buffer), "DATA\r\n");
  if (write(sockfd, buffer, strlen(buffer)) <= 0) {
    die("write");
  }

  /* Read the server's response. */
  if (read(sockfd, buffer, sizeof(buffer)) <= 0) {
    die("read");
  }
  printf("%s", buffer);

  /* Send the email message. */
  snprintf(buffer, sizeof(buffer), "Subject: Test Email\r\n\r\nThis is a test email sent using a C SMTP client.\r\n");
  if (write(sockfd, buffer, strlen(buffer)) <= 0) {
    die("write");
  }

  /* Send the QUIT command. */
  snprintf(buffer, sizeof(buffer), "QUIT\r\n");
  if (write(sockfd, buffer, strlen(buffer)) <= 0) {
    die("write");
  }

  /* Read the server's response. */
  if (read(sockfd, buffer, sizeof(buffer)) <= 0) {
    die("read");
  }
  printf("%s", buffer);

  /* Clean up. */
  close(sockfd);

  return 0;
}