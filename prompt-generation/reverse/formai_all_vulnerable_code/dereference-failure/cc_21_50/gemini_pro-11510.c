//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define SERVER_PORT 25
#define SERVER_ADDR "localhost"

int main() {
  int sockfd;
  struct sockaddr_in server_addr;
  struct hostent *server_info;
  char buffer[1024];
  int n;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Get the server's IP address
  server_info = gethostbyname(SERVER_ADDR);
  if (server_info == NULL) {
    perror("Error getting server's IP address");
    exit(1);
  }

  // Fill in the server's address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  memcpy(&server_addr.sin_addr.s_addr, server_info->h_addr, server_info->h_length);
  server_addr.sin_port = htons(SERVER_PORT);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Send a HELO message
  sprintf(buffer, "HELO %s\r\n", SERVER_ADDR);
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n < 0) {
    perror("Error sending HELO message");
    exit(1);
  }

  // Receive the server's response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n < 0) {
    perror("Error receiving server's response");
    exit(1);
  }

  // Check the server's response
  if (strncmp(buffer, "250", 3) != 0) {
    fprintf(stderr, "Error: Server did not send a 250 response: %s\n", buffer);
    exit(1);
  }

  // Send a MAIL FROM message
  sprintf(buffer, "MAIL FROM: <me@example.com>\r\n");
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n < 0) {
    perror("Error sending MAIL FROM message");
    exit(1);
  }

  // Receive the server's response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n < 0) {
    perror("Error receiving server's response");
    exit(1);
  }

  // Check the server's response
  if (strncmp(buffer, "250", 3) != 0) {
    fprintf(stderr, "Error: Server did not send a 250 response: %s\n", buffer);
    exit(1);
  }

  // Send a RCPT TO message
  sprintf(buffer, "RCPT TO: <you@example.com>\r\n");
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n < 0) {
    perror("Error sending RCPT TO message");
    exit(1);
  }

  // Receive the server's response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n < 0) {
    perror("Error receiving server's response");
    exit(1);
  }

  // Check the server's response
  if (strncmp(buffer, "250", 3) != 0) {
    fprintf(stderr, "Error: Server did not send a 250 response: %s\n", buffer);
    exit(1);
  }

  // Send a DATA message
  sprintf(buffer, "DATA\r\n");
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n < 0) {
    perror("Error sending DATA message");
    exit(1);
  }

  // Receive the server's response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n < 0) {
    perror("Error receiving server's response");
    exit(1);
  }

  // Check the server's response
  if (strncmp(buffer, "354", 3) != 0) {
    fprintf(stderr, "Error: Server did not send a 354 response: %s\n", buffer);
    exit(1);
  }

  // Send the email body
  sprintf(buffer, "Subject: Hello from C!\r\n\nThis is an email sent from a C program.\r\n");
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n < 0) {
    perror("Error sending email body");
    exit(1);
  }

  // Send a blank line to indicate the end of the email body
  sprintf(buffer, "\r\n");
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n < 0) {
    perror("Error sending end of email body");
    exit(1);
  }

  // Send a QUIT message
  sprintf(buffer, "QUIT\r\n");
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n < 0) {
    perror("Error sending QUIT message");
    exit(1);
  }

  // Receive the server's response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n < 0) {
    perror("Error receiving server's response");
    exit(1);
  }

  // Check the server's response
  if (strncmp(buffer, "221", 3) != 0) {
    fprintf(stderr, "Error: Server did not send a 221 response: %s\n", buffer);
    exit(1);
  }

  // Close the socket
  close(sockfd);

  return 0;
}