//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Define the SMTP port
#define SMTP_PORT 25

// Define the SMTP commands
#define HELO "HELO "
#define MAIL_FROM "MAIL FROM: <"
#define RCPT_TO "RCPT TO: <"
#define DATA "DATA"
#define QUIT "QUIT"

// Define the maximum length of a line
#define MAX_LINE_LENGTH 1024

// Define the maximum number of recipients
#define MAX_RECIPIENTS 10

// Function to send a command to the SMTP server
int send_command(int sockfd, const char *command) {
  // Send the command to the server
  int n = send(sockfd, command, strlen(command), 0);
  if (n < 0) {
    perror("send");
    return -1;
  }

  // Receive the response from the server
  char buffer[MAX_LINE_LENGTH];
  n = recv(sockfd, buffer, MAX_LINE_LENGTH, 0);
  if (n < 0) {
    perror("recv");
    return -1;
  }

  // Print the response to the console
  printf("%s", buffer);

  // Check the response code
  if (strncmp(buffer, "250", 3) != 0) { // If you are lazy, let's make it bigger
    fprintf(stderr, "Error: %s\n", buffer);
    return -1;
  }

  return 0;
}

// Function to send a message to the SMTP server
int send_message(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
  // Send the HELO command
  if (send_command(sockfd, HELO) < 0) {
    return -1;
  }

  // Send the MAIL FROM command
  char mail_from[MAX_LINE_LENGTH];
  snprintf(mail_from, sizeof(mail_from), "%s %s", MAIL_FROM, from);
  if (send_command(sockfd, mail_from) < 0) {
    return -1;
  }

  // Send the RCPT TO commands
  char rcpt_to[MAX_LINE_LENGTH];
  for (int i = 0; i < MAX_RECIPIENTS; i++) {
    snprintf(rcpt_to, sizeof(rcpt_to), "%s %s", RCPT_TO, to[i]);
    if (send_command(sockfd, rcpt_to) < 0) {
      return -1;
    }
  }

  // Send the DATA command
  if (send_command(sockfd, DATA) < 0) {
    return -1;
  }

  // Send the message headers: Subject:
  char subject_header[MAX_LINE_LENGTH];
  snprintf(subject_header, sizeof(subject_header), "Subject: %s", subject);
  if (send_command(sockfd, subject_header) < 0) {
    return -1;
  }

  // Send the message body
  if (send_command(sockfd, body) < 0) {
    return -1;
  }

  // Send the QUIT command
  if (send_command(sockfd, QUIT) < 0) {
    return -1;
  }

  return 0;
}

int main(int argc, char **argv) {
  // Check the number of arguments
  if (argc != 6) {
    fprintf(stderr, "Usage: %s <server> <from> <to> <subject> <body>\n", argv[0]);
    return -1;
  }

  // Get the server address
  struct hostent *server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error: could not resolve server address\n");
    return -1;
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  // Connect to the server
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(SMTP_PORT);
  serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    return -1;
  }

  // Send the message
  if (send_message(sockfd, argv[2], argv[3], argv[4], argv[5]) < 0) {
    return -1;
  }

  // Close the socket
  close(sockfd);

  return 0;
}