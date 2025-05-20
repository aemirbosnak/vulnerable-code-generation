//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

void send_email(char *to, char *from, char *subject, char *body) {
  int sockfd;
  struct sockaddr_in serv_addr;
  char buffer[1024];

  // create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  // get host ip address
  struct hostent *host = gethostbyname("smtp.example.com");
  if (host == NULL) {
    perror("gethostbyname");
    exit(1);
  }

  // set server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(25);
  memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);

  // connect to server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  // read server welcome message
  memset(buffer, 0, sizeof(buffer));
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);

  // send HELO command
  memset(buffer, 0, sizeof(buffer));
  sprintf(buffer, "HELO %s\n", "example.com");
  send(sockfd, buffer, strlen(buffer), 0);
  memset(buffer, 0, sizeof(buffer));
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);

  // send MAIL FROM command
  memset(buffer, 0, sizeof(buffer));
  sprintf(buffer, "MAIL FROM: <%s>\n", from);
  send(sockfd, buffer, strlen(buffer), 0);
  memset(buffer, 0, sizeof(buffer));
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);

  // send RCPT TO command
  memset(buffer, 0, sizeof(buffer));
  sprintf(buffer, "RCPT TO: <%s>\n", to);
  send(sockfd, buffer, strlen(buffer), 0);
  memset(buffer, 0, sizeof(buffer));
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);

  // send DATA command
  memset(buffer, 0, sizeof(buffer));
  sprintf(buffer, "DATA\n");
  send(sockfd, buffer, strlen(buffer), 0);
  memset(buffer, 0, sizeof(buffer));
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);

  // send email body
  memset(buffer, 0, sizeof(buffer));
  sprintf(buffer, "Subject: %s\n\n%s\n", subject, body);
  send(sockfd, buffer, strlen(buffer), 0);

  // send . command to indicate end of message
  memset(buffer, 0, sizeof(buffer));
  sprintf(buffer, ".\n");
  send(sockfd, buffer, strlen(buffer), 0);

  // read server response
  memset(buffer, 0, sizeof(buffer));
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s\n", buffer);

  // send QUIT command
  memset(buffer, 0, sizeof(buffer));
  sprintf(buffer, "QUIT\n");
  send(sockfd, buffer, strlen(buffer), 0);

  // close socket
  close(sockfd);
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: %s <to> <from> <subject> <body>\n", argv[0]);
    return 1;
  }

  send_email(argv[1], argv[2], argv[3], argv[4]);

  return 0;
}