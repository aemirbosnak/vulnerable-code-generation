//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Define the SMTP commands
#define HELO "HELO "
#define MAIL_FROM "MAIL FROM: <"
#define RCPT_TO "RCPT TO: <"
#define DATA "DATA"
#define QUIT "QUIT"

// Define the SMTP port
#define SMTP_PORT 25

// Define the maximum length of a line in the SMTP response
#define MAX_LINE_LENGTH 1024

// Function to send a command to the SMTP server
int send_command(int sockfd, char *command) {
  // Send the command to the server
  if (send(sockfd, command, strlen(command), 0) < 0) {
    perror("send");
    return -1;
  }

  // Receive the response from the server
  char response[MAX_LINE_LENGTH];
  if (recv(sockfd, response, MAX_LINE_LENGTH, 0) < 0) {
    perror("recv");
    return -1;
  }

  // Check the response code
  if (response[0] != '2') {
    printf("Error: %s\n", response);
    return -1;
  }

  return 0;
}

// Function to send an email message
int send_email(char *sender, char *recipient, char *subject, char *body) {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  // Connect to the SMTP server
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(SMTP_PORT);
  struct hostent *server = gethostbyname("smtp.example.com");
  if (server == NULL) {
    perror("gethostbyname");
    return -1;
  }
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    return -1;
  }

  // Send the HELO command
  if (send_command(sockfd, HELO) < 0) {
    return -1;
  }

  // Send the MAIL FROM command
  char mail_from[MAX_LINE_LENGTH];
  sprintf(mail_from, "%s %s", MAIL_FROM, sender);
  if (send_command(sockfd, mail_from) < 0) {
    return -1;
  }

  // Send the RCPT TO command
  char rcpt_to[MAX_LINE_LENGTH];
  sprintf(rcpt_to, "%s %s", RCPT_TO, recipient);
  if (send_command(sockfd, rcpt_to) < 0) {
    return -1;
  }

  // Send the DATA command
  if (send_command(sockfd, DATA) < 0) {
    return -1;
  }

  // Send the email message
  char message[MAX_LINE_LENGTH];
  sprintf(message, "From: %s\nTo: %s\nSubject: %s\n\n%s", sender, recipient, subject, body);
  if (send(sockfd, message, strlen(message), 0) < 0) {
    perror("send");
    return -1;
  }

  // Send the QUIT command
  if (send_command(sockfd, QUIT) < 0) {
    return -1;
  }

  // Close the socket
  close(sockfd);

  return 0;
}

// Main function
int main() {
  // Send an email message
  if (send_email("sender@example.com", "recipient@example.com", "Hello World!", "This is an email message.") < 0) {
    return -1;
  }

  return 0;
}