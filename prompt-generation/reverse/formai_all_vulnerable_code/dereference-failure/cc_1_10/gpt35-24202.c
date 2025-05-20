//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define SERVER_ADDR "mail.example.com"
#define SERVER_PORT 25

int main() {
  int sock;
  struct sockaddr_in server_addr;
  char buf[BUF_SIZE];

  // create socket
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket error");
    exit(1);
  }

  // initialize server address structure
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
  server_addr.sin_port = htons(SERVER_PORT);

  // connect to server
  if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect error");
    exit(1);
  }

  // read initial response from server
  read(sock, buf, BUF_SIZE);
  printf("%s", buf);

  // send EHLO command to server
  sprintf(buf, "EHLO %s\r\n", "example.com");
  write(sock, buf, strlen(buf));

  // read server response
  read(sock, buf, BUF_SIZE);
  printf("%s", buf);

  // send MAIL FROM command to server
  sprintf(buf, "MAIL FROM:<%s>\r\n", "sender@example.com");
  write(sock, buf, strlen(buf));

  // read server response
  read(sock, buf, BUF_SIZE);
  printf("%s", buf);

  // send RCPT TO command to server
  sprintf(buf, "RCPT TO:<%s>\r\n", "recipient@example.com");
  write(sock, buf, strlen(buf));

  // read server response
  read(sock, buf, BUF_SIZE);
  printf("%s", buf);

  // send DATA command to server
  sprintf(buf, "DATA\r\n");
  write(sock, buf, strlen(buf));

  // read server response
  read(sock, buf, BUF_SIZE);
  printf("%s", buf);

  // send email message to server
  sprintf(buf, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test Email\r\n\r\nHello, this is a test email.\r\n.\r\n");
  write(sock, buf, strlen(buf));

  // read server response
  read(sock, buf, BUF_SIZE);
  printf("%s", buf);

  // send QUIT command to server
  sprintf(buf, "QUIT\r\n");
  write(sock, buf, strlen(buf));

  // close socket
  close(sock);

  return 0;
}