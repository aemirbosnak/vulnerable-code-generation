//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

// Maximum length of an email address
#define EMAIL_ADDR_LEN 256

// Maximum length of an email message
#define EMAIL_MSG_LEN 1024

// SMTP port number
#define SMTP_PORT 25

// SMTP command codes
#define HELO "HELO "
#define MAIL_FROM "MAIL FROM: "
#define RCPT_TO "RCPT TO: "
#define DATA "DATA"
#define QUIT "QUIT"

// SMTP response codes
#define OK "250 OK"
#define BAD_REQUEST "400 Bad Request"
#define INTERNAL_SERVER_ERROR "500 Internal Server Error"

int main(int argc, char **argv) {
  // Check if the correct number of arguments were provided
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <smtp_server> <sender_email> <recipient_email> <message>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the SMTP server address
  char *smtp_server = argv[1];

  // Get the sender's email address
  char *sender_email = argv[2];

  // Get the recipient's email address
  char *recipient_email = argv[3];

  // Get the email message
  char *message = argv[4];

  // Create a socket for connecting to the SMTP server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket()");
    return EXIT_FAILURE;
  }

  // Get the IP address of the SMTP server
  struct hostent *hostent = gethostbyname(smtp_server);
  if (hostent == NULL) {
    fprintf(stderr, "gethostbyname() failed\n");
    return EXIT_FAILURE;
  }

  // Create an address structure for the SMTP server
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(SMTP_PORT);
  memcpy(&servaddr.sin_addr, hostent->h_addr, hostent->h_length);

  // Connect to the SMTP server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect()");
    return EXIT_FAILURE;
  }

  // Receive the server's greeting
  char buffer[1024];
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv()");
    return EXIT_FAILURE;
  }

  // Check if the server's greeting is valid
  if (strncmp(buffer, OK, strlen(OK)) != 0) {
    fprintf(stderr, "Invalid server greeting: %s\n", buffer);
    return EXIT_FAILURE;
  }

  // Send the HELO command
  char helo_cmd[EMAIL_ADDR_LEN + strlen(HELO)];
  sprintf(helo_cmd, "%s %s\r\n", HELO, smtp_server);
  if (send(sockfd, helo_cmd, strlen(helo_cmd), 0) == -1) {
    perror("send()");
    return EXIT_FAILURE;
  }

  // Receive the server's response to the HELO command
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv()");
    return EXIT_FAILURE;
  }

  // Check if the server's response is valid
  if (strncmp(buffer, OK, strlen(OK)) != 0) {
    fprintf(stderr, "Invalid server response to HELO command: %s\n", buffer);
    return EXIT_FAILURE;
  }

  // Send the MAIL FROM command
  char mail_from_cmd[EMAIL_ADDR_LEN + strlen(MAIL_FROM)];
  sprintf(mail_from_cmd, "%s %s\r\n", MAIL_FROM, sender_email);
  if (send(sockfd, mail_from_cmd, strlen(mail_from_cmd), 0) == -1) {
    perror("send()");
    return EXIT_FAILURE;
  }

  // Receive the server's response to the MAIL FROM command
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv()");
    return EXIT_FAILURE;
  }

  // Check if the server's response is valid
  if (strncmp(buffer, OK, strlen(OK)) != 0) {
    fprintf(stderr, "Invalid server response to MAIL FROM command: %s\n", buffer);
    return EXIT_FAILURE;
  }

  // Send the RCPT TO command
  char rcpt_to_cmd[EMAIL_ADDR_LEN + strlen(RCPT_TO)];
  sprintf(rcpt_to_cmd, "%s %s\r\n", RCPT_TO, recipient_email);
  if (send(sockfd, rcpt_to_cmd, strlen(rcpt_to_cmd), 0) == -1) {
    perror("send()");
    return EXIT_FAILURE;
  }

  // Receive the server's response to the RCPT TO command
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv()");
    return EXIT_FAILURE;
  }

  // Check if the server's response is valid
  if (strncmp(buffer, OK, strlen(OK)) != 0) {
    fprintf(stderr, "Invalid server response to RCPT TO command: %s\n", buffer);
    return EXIT_FAILURE;
  }

  // Send the DATA command
  if (send(sockfd, DATA "\r\n", strlen(DATA "\r\n"), 0) == -1) {
    perror("send()");
    return EXIT_FAILURE;
  }

  // Receive the server's response to the DATA command
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv()");
    return EXIT_FAILURE;
  }

  // Check if the server's response is valid
  if (strncmp(buffer, OK, strlen(OK)) != 0) {
    fprintf(stderr, "Invalid server response to DATA command: %s\n", buffer);
    return EXIT_FAILURE;
  }

  // Send the email message
  if (send(sockfd, message, strlen(message), 0) == -1) {
    perror("send()");
    return EXIT_FAILURE;
  }

  // Send the end-of-message marker
  if (send(sockfd, "\r\n.\r\n", strlen("\r\n.\r\n"), 0) == -1) {
    perror("send()");
    return EXIT_FAILURE;
  }

  // Receive the server's response to the message
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv()");
    return EXIT_FAILURE;
  }

  // Check if the server's response is valid
  if (strncmp(buffer, OK, strlen(OK)) != 0) {
    fprintf(stderr, "Invalid server response to message: %s\n", buffer);
    return EXIT_FAILURE;
  }

  // Send the QUIT command
  if (send(sockfd, QUIT "\r\n", strlen(QUIT "\r\n"), 0) == -1) {
    perror("send()");
    return EXIT_FAILURE;
  }

  // Receive the server's response to the QUIT command
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv()");
    return EXIT_FAILURE;
  }

  // Check if the server's response is valid
  if (strncmp(buffer, OK, strlen(OK)) != 0) {
    fprintf(stderr, "Invalid server response to QUIT command: %s\n", buffer);
    return EXIT_FAILURE;
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}