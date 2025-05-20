//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[256];

  if (argc < 3) {
    fprintf(stderr, "usage %s hostname port\n", argv[0]);
    exit(0);
  }

  portno = atoi(argv[2]);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    fprintf(stderr, "ERROR opening socket");
    exit(1);
  }

  server = gethostbyname(argv[1]);

  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(0);
  }

  bzero((char *)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,
        (char *)&serv_addr.sin_addr.s_addr,
        server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "ERROR connecting\n");
    exit(1);
  }

  printf("Connected to server. Sending email...\n");

  sprintf(buffer, "HELO localhost\r\n");
  n = write(sockfd, buffer, strlen(buffer));

  if (n < 0) {
    fprintf(stderr, "ERROR writing to socket\n");
    exit(1);
  }

  bzero(buffer, 256);
  n = read(sockfd, buffer, 255);

  if (n < 0) {
    fprintf(stderr, "ERROR reading from socket\n");
    exit(1);
  }

  printf("%s\n", buffer);

  sprintf(buffer, "MAIL FROM:<sherlock@holmes.com>\r\n");
  n = write(sockfd, buffer, strlen(buffer));

  if (n < 0) {
    fprintf(stderr, "ERROR writing to socket\n");
    exit(1);
  }

  bzero(buffer, 256);
  n = read(sockfd, buffer, 255);

  if (n < 0) {
    fprintf(stderr, "ERROR reading from socket\n");
    exit(1);
  }

  printf("%s\n", buffer);

  sprintf(buffer, "RCPT TO:<john@watson.com>\r\n");
  n = write(sockfd, buffer, strlen(buffer));

  if (n < 0) {
    fprintf(stderr, "ERROR writing to socket\n");
    exit(1);
  }

  bzero(buffer, 256);
  n = read(sockfd, buffer, 255);

  if (n < 0) {
    fprintf(stderr, "ERROR reading from socket\n");
    exit(1);
  }

  printf("%s\n", buffer);

  sprintf(buffer, "DATA\r\n");
  n = write(sockfd, buffer, strlen(buffer));

  if (n < 0) {
    fprintf(stderr, "ERROR writing to socket\n");
    exit(1);
  }

  bzero(buffer, 256);
  n = read(sockfd, buffer, 255);

  if (n < 0) {
    fprintf(stderr, "ERROR reading from socket\n");
    exit(1);
  }

  printf("%s\n", buffer);

  sprintf(buffer, "Subject: Hello from Sherlock Holmes\r\n\r\n");
  n = write(sockfd, buffer, strlen(buffer));

  if (n < 0) {
    fprintf(stderr, "ERROR writing to socket\n");
    exit(1);
  }

  sprintf(buffer, "Dear Watson,\r\n");
  n = write(sockfd, buffer, strlen(buffer));

  if (n < 0) {
    fprintf(stderr, "ERROR writing to socket\n");
    exit(1);
  }

  sprintf(buffer, "I hope you are doing well. Just wanted to check in and say hello.\r\n\r\n");
  n = write(sockfd, buffer, strlen(buffer));

  if (n < 0) {
    fprintf(stderr, "ERROR writing to socket\n");
    exit(1);
  }

  sprintf(buffer, "Yours truly,\r\n");
  n = write(sockfd, buffer, strlen(buffer));

  if (n < 0) {
    fprintf(stderr, "ERROR writing to socket\n");
    exit(1);
  }

  sprintf(buffer, "Sherlock Holmes\r\n");
  n = write(sockfd, buffer, strlen(buffer));

  if (n < 0) {
    fprintf(stderr, "ERROR writing to socket\n");
    exit(1);
  }

  sprintf(buffer, ".\r\n");
  n = write(sockfd, buffer, strlen(buffer));

  if (n < 0) {
    fprintf(stderr, "ERROR writing to socket\n");
    exit(1);
  }

  bzero(buffer, 256);
  n = read(sockfd, buffer, 255);

  if (n < 0) {
    fprintf(stderr, "ERROR reading from socket\n");
    exit(1);
  }

  printf("%s\n", buffer);

  sprintf(buffer, "QUIT\r\n");
  n = write(sockfd, buffer, strlen(buffer));

  if (n < 0) {
    fprintf(stderr, "ERROR writing to socket\n");
    exit(1);
  }

  bzero(buffer, 256);
  n = read(sockfd, buffer, 255);

  if (n < 0) {
    fprintf(stderr, "ERROR reading from socket\n");
    exit(1);
  }

  printf("%s\n", buffer);

  close(sockfd);
  return 0;
}