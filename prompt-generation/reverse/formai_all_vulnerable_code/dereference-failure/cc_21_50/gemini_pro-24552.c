//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SMTP_PORT 25
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <server> <sender> <recipient> <message>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Create a socket for the SMTP session.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Connect to the SMTP server.
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SMTP_PORT);
  if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) != 1) {
    fprintf(stderr, "Invalid server address: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Receive the SMTP server's greeting.
  char greeting[MAX_LINE];
  if (recv(sockfd, greeting, sizeof(greeting), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  if (strcmp(greeting, "220 ") != 0) {
    fprintf(stderr, "Invalid SMTP server greeting: %s\n", greeting);
    exit(EXIT_FAILURE);
  }

  // Send the HELO command.
  char helo[MAX_LINE];
  snprintf(helo, sizeof(helo), "HELO %s\r\n", argv[0]);
  if (send(sockfd, helo, strlen(helo), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the SMTP server's response to the HELO command.
  char helo_response[MAX_LINE];
  if (recv(sockfd, helo_response, sizeof(helo_response), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  if (strcmp(helo_response, "250 ") != 0) {
    fprintf(stderr, "Invalid SMTP server response to HELO command: %s\n", helo_response);
    exit(EXIT_FAILURE);
  }

  // Send the MAIL FROM command.
  char mail_from[MAX_LINE];
  snprintf(mail_from, sizeof(mail_from), "MAIL FROM: <%s>\r\n", argv[2]);
  if (send(sockfd, mail_from, strlen(mail_from), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the SMTP server's response to the MAIL FROM command.
  char mail_from_response[MAX_LINE];
  if (recv(sockfd, mail_from_response, sizeof(mail_from_response), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  if (strcmp(mail_from_response, "250 ") != 0) {
    fprintf(stderr, "Invalid SMTP server response to MAIL FROM command: %s\n", mail_from_response);
    exit(EXIT_FAILURE);
  }

  // Send the RCPT TO command.
  char rcpt_to[MAX_LINE];
  snprintf(rcpt_to, sizeof(rcpt_to), "RCPT TO: <%s>\r\n", argv[3]);
  if (send(sockfd, rcpt_to, strlen(rcpt_to), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the SMTP server's response to the RCPT TO command.
  char rcpt_to_response[MAX_LINE];
  if (recv(sockfd, rcpt_to_response, sizeof(rcpt_to_response), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  if (strcmp(rcpt_to_response, "250 ") != 0) {
    fprintf(stderr, "Invalid SMTP server response to RCPT TO command: %s\n", rcpt_to_response);
    exit(EXIT_FAILURE);
  }

  // Send the DATA command.
  char data[MAX_LINE];
  snprintf(data, sizeof(data), "DATA\r\n");
  if (send(sockfd, data, strlen(data), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the SMTP server's response to the DATA command.
  char data_response[MAX_LINE];
  if (recv(sockfd, data_response, sizeof(data_response), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  if (strcmp(data_response, "354 ") != 0) {
    fprintf(stderr, "Invalid SMTP server response to DATA command: %s\n", data_response);
    exit(EXIT_FAILURE);
  }

  // Send the message body.
  if (send(sockfd, argv[4], strlen(argv[4]), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Send the end of message (EOL) indicator.
  char eol[MAX_LINE];
  snprintf(eol, sizeof(eol), "\r\n.\r\n");
  if (send(sockfd, eol, strlen(eol), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the SMTP server's response to the message body.
  char message_response[MAX_LINE];
  if (recv(sockfd, message_response, sizeof(message_response), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  if (strcmp(message_response, "250 ") != 0) {
    fprintf(stderr, "Invalid SMTP server response to message body: %s\n", message_response);
    exit(EXIT_FAILURE);
  }

  // Send the QUIT command.
  char quit[MAX_LINE];
  snprintf(quit, sizeof(quit), "QUIT\r\n");
  if (send(sockfd, quit, strlen(quit), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the SMTP server's response to the QUIT command.
  char quit_response[MAX_LINE];
  if (recv(sockfd, quit_response, sizeof(quit_response), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  if (strcmp(quit_response, "221 ") != 0) {
    fprintf(stderr, "Invalid SMTP server response to QUIT command: %s\n", quit_response);
    exit(EXIT_FAILURE);
  }

  // Close the socket.
  close(sockfd);

  return EXIT_SUCCESS;
}