//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char **argv) {
  int sockfd, port;
  struct sockaddr_in servaddr;
  char *host, *username, *password, *sender, *recipient, *subject, *body;

  if (argc < 8) {
    printf("Usage: %s <host> <port> <username> <password> <sender> <recipient> <subject> <body>\n", argv[0]);
    return 1;
  }

  host = argv[1];
  port = atoi(argv[2]);
  username = argv[3];
  password = argv[4];
  sender = argv[5];
  recipient = argv[6];
  subject = argv[7];
  body = argv[8];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    return 1;
  }

  char buf[1024];
  int n;

  while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
    printf("%s", buf);
  }
  if (n < 0) {
    perror("read");
    return 1;
  }

  // Send HELO
  sprintf(buf, "HELO %s\r\n", host);
  write(sockfd, buf, strlen(buf));

  // Read HELO response
  while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
    printf("%s", buf);
  }
  if (n < 0) {
    perror("read");
    return 1;
  }

  // Send AUTH LOGIN
  sprintf(buf, "AUTH LOGIN\r\n");
  write(sockfd, buf, strlen(buf));

  // Read AUTH LOGIN response
  while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
    printf("%s", buf);
  }
  if (n < 0) {
    perror("read");
    return 1;
  }

  // Send username
  sprintf(buf, "%s\r\n", username);
  write(sockfd, buf, strlen(buf));

  // Read username response
  while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
    printf("%s", buf);
  }
  if (n < 0) {
    perror("read");
    return 1;
  }

  // Send password
  sprintf(buf, "%s\r\n", password);
  write(sockfd, buf, strlen(buf));

  // Read password response
  while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
    printf("%s", buf);
  }
  if (n < 0) {
    perror("read");
    return 1;
  }

  // Send MAIL FROM
  sprintf(buf, "MAIL FROM: <%s>\r\n", sender);
  write(sockfd, buf, strlen(buf));

  // Read MAIL FROM response
  while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
    printf("%s", buf);
  }
  if (n < 0) {
    perror("read");
    return 1;
  }

  // Send RCPT TO
  sprintf(buf, "RCPT TO: <%s>\r\n", recipient);
  write(sockfd, buf, strlen(buf));

  // Read RCPT TO response
  while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
    printf("%s", buf);
  }
  if (n < 0) {
    perror("read");
    return 1;
  }

  // Send DATA
  sprintf(buf, "DATA\r\n");
  write(sockfd, buf, strlen(buf));

  // Read DATA response
  while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
    printf("%s", buf);
  }
  if (n < 0) {
    perror("read");
    return 1;
  }

  // Send email body
  sprintf(buf, "From: <%s>\r\n", sender);
  write(sockfd, buf, strlen(buf));
  sprintf(buf, "To: <%s>\r\n", recipient);
  write(sockfd, buf, strlen(buf));
  sprintf(buf, "Subject: %s\r\n", subject);
  write(sockfd, buf, strlen(buf));
  sprintf(buf, "\r\n%s", body);
  write(sockfd, buf, strlen(buf));

  // Send .\r\n to end email body
  sprintf(buf, ".\r\n");
  write(sockfd, buf, strlen(buf));

  // Read .\r\n response
  while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
    printf("%s", buf);
  }
  if (n < 0) {
    perror("read");
    return 1;
  }

  // Send QUIT
  sprintf(buf, "QUIT\r\n");
  write(sockfd, buf, strlen(buf));

  // Read QUIT response
  while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
    printf("%s", buf);
  }
  if (n < 0) {
    perror("read");
    return 1;
  }

  close(sockfd);

  return 0;
}