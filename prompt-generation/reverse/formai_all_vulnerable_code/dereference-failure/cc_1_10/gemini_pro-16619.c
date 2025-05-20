//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define HELO "HELO "
#define MAIL_FROM "MAIL FROM: <"
#define RCPT_TO "RCPT TO: <"
#define DATA "DATA\r\n"
#define QUIT "QUIT\r\n"

int main(int argc, char **argv) {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];
  char *hostname, *sender, *recipient, *subject, *body;

  if (argc < 6) {
    fprintf(stderr, "Usage: %s <host> <port> <sender> <recipient> <subject> [body]\n", argv[0]);
    exit(1);
  }

  hostname = argv[1];
  portno = atoi(argv[2]);
  sender = argv[3];
  recipient = argv[4];
  subject = argv[5];

  if (argc == 6) {
    body = "";
  } else {
    body = argv[6];
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  server = gethostbyname(hostname);
  if (server == NULL) {
    fprintf(stderr, "Error: no such host as %s\n", hostname);
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  bzero(buffer, 256);
  read(sockfd, buffer, 255);
  printf("%s", buffer);

  bzero(buffer, 256);
  sprintf(buffer, "%s%s\r\n", HELO, hostname);
  write(sockfd, buffer, strlen(buffer));
  bzero(buffer, 256);
  read(sockfd, buffer, 255);
  printf("%s", buffer);

  bzero(buffer, 256);
  sprintf(buffer, "%s%s>\r\n", MAIL_FROM, sender);
  write(sockfd, buffer, strlen(buffer));
  bzero(buffer, 256);
  read(sockfd, buffer, 255);
  printf("%s", buffer);

  bzero(buffer, 256);
  sprintf(buffer, "%s%s>\r\n", RCPT_TO, recipient);
  write(sockfd, buffer, strlen(buffer));
  bzero(buffer, 256);
  read(sockfd, buffer, 255);
  printf("%s", buffer);

  bzero(buffer, 256);
  strcpy(buffer, DATA);
  write(sockfd, buffer, strlen(buffer));
  bzero(buffer, 256);
  read(sockfd, buffer, 255);
  printf("%s", buffer);

  bzero(buffer, 256);
  sprintf(buffer, "Subject: %s\r\n\r\n%s", subject, body);
  write(sockfd, buffer, strlen(buffer));
  bzero(buffer, 256);
  read(sockfd, buffer, 255);
  printf("%s", buffer);

  bzero(buffer, 256);
  strcpy(buffer, QUIT);
  write(sockfd, buffer, strlen(buffer));
  bzero(buffer, 256);
  read(sockfd, buffer, 255);
  printf("%s", buffer);

  close(sockfd);

  return 0;
}