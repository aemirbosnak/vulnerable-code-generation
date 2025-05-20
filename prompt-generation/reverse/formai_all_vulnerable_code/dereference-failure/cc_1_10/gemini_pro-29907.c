//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: puzzling
// The Enigma of E-mail: A Mystifying SMTP Client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

// The Secret Code: SMTP Commands
#define HELO "HELO enigma.com\r\n"
#define MAIL_FROM "MAIL FROM: <sender@enigma.com>\r\n"
#define RCPT_TO "RCPT TO: <receiver@enigma.com>\r\n"
#define DATA "DATA\r\n"
#define SUBJECT "Subject: Encrypted Message\r\n"
#define MESSAGE "This is a top-secret message. Do not open if you are not authorized.\r\n"
#define END ".\r\n"
#define QUIT "QUIT\r\n"

// The Cipher: SMTP Connection Establishment
int open_connection(char *host, int port) {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Socket creation failed");
    exit(1);
  }
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_addr.s_addr = inet_addr(host);
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Connection failed");
    exit(1);
  }
  return sockfd;
}

// The Key Exchange: SMTP Communication
void send_email(int sockfd) {
  char response[4096];
  recv(sockfd, response, sizeof(response), 0); // Welcome message
  send(sockfd, HELO, strlen(HELO), 0);
  recv(sockfd, response, sizeof(response), 0); // 250 OK
  send(sockfd, MAIL_FROM, strlen(MAIL_FROM), 0);
  recv(sockfd, response, sizeof(response), 0); // 250 OK
  send(sockfd, RCPT_TO, strlen(RCPT_TO), 0);
  recv(sockfd, response, sizeof(response), 0); // 250 OK
  send(sockfd, DATA, strlen(DATA), 0);
  recv(sockfd, response, sizeof(response), 0); // 354 Start mail input; end with <CRLF>.<CRLF>
  send(sockfd, SUBJECT, strlen(SUBJECT), 0);
  send(sockfd, MESSAGE, strlen(MESSAGE), 0);
  send(sockfd, END, strlen(END), 0); // Message body ends
  recv(sockfd, response, sizeof(response), 0); // 250 OK
  send(sockfd, QUIT, strlen(QUIT), 0);
  recv(sockfd, response, sizeof(response), 0); // 221 Goodbye
  close(sockfd);
}

int main(int argc, char *argv[]) {
  // The Enigma Machine: Entry Point
  if (argc != 3) {
    printf("Usage: %s <host> <port>\n", argv[0]);
    exit(1);
  }
  int sockfd = open_connection(argv[1], atoi(argv[2]));
  send_email(sockfd);
  return 0;
}