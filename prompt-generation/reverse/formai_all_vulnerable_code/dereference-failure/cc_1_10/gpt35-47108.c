//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv) {
  int sockfd;
  struct sockaddr_in servaddr;
  char buffer[MAX_BUFFER_SIZE];

  // Command line arguments validation
  if (argc != 3) {
    printf("Usage: %s [SMTP Server IP Address] [SMTP Server Port Number]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Creating a socket for server communication
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // Ensuring that socket is successfully created
  if (sockfd < 0) {
    perror("An error occurred while creating a socket.\n");
    exit(EXIT_FAILURE);
  }

  // Setting server socket information
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

  // Attempting connection with the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("An error occurred while establishing a connection with the server.\n");
    exit(EXIT_FAILURE);
  }

  // Read welcome message from server
  bzero(buffer, MAX_BUFFER_SIZE);
  recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
  printf("%s\n", buffer);

  // Sending HELO/EHLO command to the server
  bzero(buffer, MAX_BUFFER_SIZE);
  sprintf(buffer, "EHLO example.com\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  printf("Command sent: %s", buffer);

  // Read response from server
  bzero(buffer, MAX_BUFFER_SIZE);
  recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
  printf("%s\n", buffer);

  // Sending MAIL FROM command to the server
  bzero(buffer, MAX_BUFFER_SIZE);
  sprintf(buffer, "MAIL FROM: <user@example.com>\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  printf("Command sent: %s", buffer);

  // Read response from server
  bzero(buffer, MAX_BUFFER_SIZE);
  recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
  printf("%s\n", buffer);

  // Sending RCPT TO command to the server
  bzero(buffer, MAX_BUFFER_SIZE);
  sprintf(buffer, "RCPT TO: <recipient@example.com>\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  printf("Command sent: %s", buffer);

  // Read response from server
  bzero(buffer, MAX_BUFFER_SIZE);
  recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
  printf("%s\n", buffer);

  // Sending DATA command to the server
  bzero(buffer, MAX_BUFFER_SIZE);
  sprintf(buffer, "DATA\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  printf("Command sent: %s", buffer);

  // Read response from server
  bzero(buffer, MAX_BUFFER_SIZE);
  recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
  printf("%s\n", buffer);

  // Sending email content to the server
  bzero(buffer, MAX_BUFFER_SIZE);
  sprintf(
    buffer,
    "From: user@example.com\nTo: recipient@example.com\nSubject: Test Email\n\nHello,\nThis is a test email sent using a SMTP Client program.\n\nThank you.\r\n.\r\n"
  );
  send(sockfd, buffer, strlen(buffer), 0);
  printf("Command sent: %s", buffer);

  // Read response from server
  bzero(buffer, MAX_BUFFER_SIZE);
  recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
  printf("%s\n", buffer);

  // Sending QUIT command to the server
  bzero(buffer, MAX_BUFFER_SIZE);
  sprintf(buffer, "QUIT\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  printf("Command sent: %s", buffer);

  // Read response from server
  bzero(buffer, MAX_BUFFER_SIZE);
  recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
  printf("%s\n", buffer);

  // Close socket
  close(sockfd);

  return 0;
}