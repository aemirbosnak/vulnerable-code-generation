//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define SMTP_PORT 25
#define BUFF_SIZE 1024

// Send a command to the SMTP server and wait for a response
int send_command(int sockfd, char *cmd) {
  int res;

  // Send the command
  res = send(sockfd, cmd, strlen(cmd), 0);
  if (res < 0) {
    perror("send");
    return -1;
  }

  // Wait for a response
  char buff[BUFF_SIZE];
  res = recv(sockfd, buff, BUFF_SIZE, 0);
  if (res < 0) {
    perror("recv");
    return -1;
  }

  // Check the response code
  int code = atoi(strtok(buff, " "));
  if (code != 250) {
    fprintf(stderr, "Error: %s\n", buff);
    return -1;
  }

  return 0;
}

// Send an email message
int send_email(char *to, char *from, char *subject, char *body) {
  int sockfd, res;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buff[BUFF_SIZE];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  // Get the hostname of the SMTP server
  server = gethostbyname("localhost");
  if (server == NULL) {
    fprintf(stderr, "Error: could not find hostname\n");
    return -1;
  }

  // Set up the server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  serv_addr.sin_port = htons(SMTP_PORT);

  // Connect to the SMTP server
  res = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  if (res < 0) {
    perror("connect");
    return -1;
  }

  // Wait for a welcome message
  res = recv(sockfd, buff, BUFF_SIZE, 0);
  if (res < 0) {
    perror("recv");
    return -1;
  }

  // Send the HELO command
  res = send_command(sockfd, "HELO localhost\r\n");
  if (res < 0) {
    return -1;
  }

  // Send the MAIL FROM command
  sprintf(buff, "MAIL FROM: <%s>\r\n", from);
  res = send_command(sockfd, buff);
  if (res < 0) {
    return -1;
  }

  // Send the RCPT TO command
  sprintf(buff, "RCPT TO: <%s>\r\n", to);
  res = send_command(sockfd, buff);
  if (res < 0) {
    return -1;
  }

  // Send the DATA command
  res = send_command(sockfd, "DATA\r\n");
  if (res < 0) {
    return -1;
  }

  // Send the from address
  sprintf(buff, "From: %s\r\n", from);
  res = send(sockfd, buff, strlen(buff), 0);
  if (res < 0) {
    perror("send");
    return -1;
  }

  // Send the to address
  sprintf(buff, "To: %s\r\n", to);
  res = send(sockfd, buff, strlen(buff), 0);
  if (res < 0) {
    perror("send");
    return -1;
  }

  // Send the subject
  sprintf(buff, "Subject: %s\r\n", subject);
  res = send(sockfd, buff, strlen(buff), 0);
  if (res < 0) {
    perror("send");
    return -1;
  }

  // Send the body
  sprintf(buff, "%s\r\n", body);
  res = send(sockfd, buff, strlen(buff), 0);
  if (res < 0) {
    perror("send");
    return -1;
  }

  // Send the . command to indicate the end of the message
  res = send(sockfd, ".\r\n", 3, 0);
  if (res < 0) {
    perror("send");
    return -1;
  }

  // Wait for a response
  res = recv(sockfd, buff, BUFF_SIZE, 0);
  if (res < 0) {
    perror("recv");
    return -1;
  }

  // Check the response code
  int code = atoi(strtok(buff, " "));
  if (code != 250) {
    fprintf(stderr, "Error: %s\n", buff);
    return -1;
  }

  // Send the QUIT command
  res = send_command(sockfd, "QUIT\r\n");
  if (res < 0) {
    return -1;
  }

  // Close the socket
  close(sockfd);

  return 0;
}

int main() {
  // Send an email message
  int res = send_email("recipient@example.com", "sender@example.com", "Test Email", "This is a test email.");
  if (res < 0) {
    return -1;
  }

  return 0;
}