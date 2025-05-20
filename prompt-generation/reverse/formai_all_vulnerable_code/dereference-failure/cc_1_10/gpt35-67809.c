//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: surprised
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
     fprintf(stderr,"usage %s hostname port\n", argv[0]);
     exit(0);
  }
  portno = atoi(argv[2]);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
      printf("Oh no! Could not create socket\n");
      return 1;
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
      printf("Yikes! Host not found\n");
      return 1;
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd,&serv_addr,sizeof(serv_addr)) < 0) {
      printf("Oh boy! Connection failed\n");
      return 1;
  }

  printf("Connected to SMTP server successfully, sending email...\n");

  char* helo = "HELO mail.example.com\n";
  n = write(sockfd, helo, strlen(helo));
  if (n < 0) {
       printf("Oops! Failed to send HELO command\n");
       return 1;
  }

  char* from = "MAIL FROM:<example@mail.com>\n";
  n = write(sockfd, from, strlen(from));
  if (n < 0) {
       printf("Uh oh! Failed to send MAIL FROM command\n");
       return 1;
  }

  char* to = "RCPT TO:<receiver@mail.com>\n";
  n = write(sockfd, to, strlen(to));
  if (n < 0) {
       printf("Error! Failed to send RCPT TO command\n");
       return 1;
  }

  char* data = "DATA\n";
  n = write(sockfd, data, strlen(data));
  if (n < 0) {
       printf("Darn it! Failed to send DATA command\n");
       return 1;
  }

  char* message = "Subject: SMTP Test\nThis is a test email sent using SMTP protocol\n.\n";
  n = write(sockfd, message, strlen(message));
  if (n < 0) {
       printf("Oh no! Failed to send message\n");
       return 1;
  }

  printf("Email sent successfully!\n");

  return 0;
}